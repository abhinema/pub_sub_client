//g++ -std=c++14 -O3 -Wall -Wextra tcp.cpp -pthread -lboost_thread -lboost_system 
//reset;g++ -o server_int -std=c++14 -O3 -Wall -Wextra tcp.cpp -pthread -lboost_thread -lboost_system

#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread/scoped_thread.hpp>
#include <typeinfo>
#include <string>

using namespace std;
using boost::asio::ip::tcp;

template <typename T>
void server(T val) try {
    boost::asio::io_service io_service;
    tcp::acceptor acceptor(io_service, tcp::endpoint{boost::asio::ip::address::from_string("127.0.0.1"), 12345});

    tcp::iostream stream;
    acceptor.accept(*stream.rdbuf());
    stringstream ss;
    string dataTypeLength = typeid(val).name();
        ss<<" ";
    ss<<dataTypeLength.length();
        ss<<" ";
    ss<<typeid(val).name();
        ss<<" ";
    if(typeid(T) == typeid(string)){
        ss<<sizeof(val);
        ss<<" ";
    }
    else{
        ss<<sizeof(T);
        ss<<" ";
    }
    ss<<val;
    stream<<ss.str().c_str();
#ifdef DEBUG
    cout<<hex<<ss.str().c_str()<<endl;  //DEBUG
#endif
} catch(std::exception& e) { std::cout << e.what() << '\n'; }
/* End of File */
