//
//  pub_sub.h
//  
//
//  Created by Abhishek Nema on 20/05/18.
//

#ifndef pub_sub_h
#define pub_sub_h

#include <iostream>
#include <functional>
#include <map>
#include <vector>
#include <algorithm>
#include <array>
#include <boost/asio.hpp>
#include <boost/thread/scoped_thread.hpp>
#include <typeinfo>
#include <string>
#include <boost/units/detail/utility.hpp>

using namespace std;
using boost::asio::ip::tcp;

template <typename T> class dispatcher;
/*
 Connection Class to create unique id for each event subscription
 */
template <typename T>
class Connection
{
public:
    Connection(){};
    unsigned int id() const {return _id;};
    void disconnect()  {
        if( _dispatcher )
            _dispatcher->unsubscribe( *this );
    }
    
private:
    Connection( dispatcher<T>* dispatcher, unsigned int id )  : _dispatcher( dispatcher )
    , _id( id )  {  }
    
    dispatcher<T>* _dispatcher = nullptr;
    unsigned int _id = 0;
    friend class dispatcher<T>;
};

/*
 Dispatcher class
 */
template <typename T>
class dispatcher{
public:
    unsigned int _nextID = 0;
    struct SlotHandle    {
        unsigned int id;
        std::function< void( T& )> slot;
    };
    map<T, vector<SlotHandle>  > check;
    
    dispatcher(){
#ifdef DEBUG
        cout<<"Called Dispatcher class Constructor"<<endl;
#endif        
    } 
    ~dispatcher(){
#ifdef DEBUG
        cout<<"Called Dispatcher class Distructor"<<endl;
#endif        
    } 
     
public:
    Connection<T> subscribe(T i, std::function< void( T& )> b)  {
        auto id           = _nextID;
        SlotHandle handle = { id, b };
        check[i].emplace_back( handle );
#ifdef DEBUG
        auto&& observers = check.at( i );
        cout<<"registered event count:>>>"<<observers.size()<<"For Value:"<<i<<endl;
#endif
        ++_nextID;
        return Connection<T>( this, id );
    }
    
    void unsubscribe(const Connection<T>& connection){
        for( auto&& pair : check )        {
            auto&& handles = pair.second;
            
            handles.erase( std::remove_if( handles.begin(), handles.end(),
                                          [&] ( SlotHandle& handle )
                                          {
                                              return handle.id == connection.id();
                                          } ),
                          handles.end() );
        }
    }
    
    void post( T event )    {
        if( check.find( event ) == check.end() ){
            cerr<<"Event :"<<event<<" ************** Not subscribed ************** "<<endl;
            return;
        }
        auto&& observers = check.at( event );
        for( auto&& observer : observers ){
#ifdef DEBUG        
            cout<<"Called:::"<<event<<endl;
#endif            
            observer.slot( event );
        }
    }
};

/*
 Post events with subscribed functions
 */
template <typename T>
void post_events(dispatcher<T> &d, T& val){
    d.post(val);
}

/*
 Initialize Module class
 */
template <typename T>
Connection<T> init_Module(dispatcher<T>& d, T val, std::function< void( T& )> func)  {
    auto connection = d.subscribe( val, func );
    return connection;
}
/*
 Module class creates instance of dispatcher and assigns events with function
 */
template <typename T>
class Module{
    vector< Connection<T> > connections;
public:
    template<std::size_t SIZE>
    Module(dispatcher<T> &d, const array<T, SIZE> & eventList,std::function<void(T &)> fun){
        
        for(auto subscription_val: eventList){
            cout<<"subscription_val: "<<subscription_val<<endl;
            connections.push_back(init_Module(d,subscription_val, fun));
        }
    }
    ~Module(){
        for(auto connection: connections){
            connection.disconnect();
        }
    }
};
#endif /* pub_sub_h */
