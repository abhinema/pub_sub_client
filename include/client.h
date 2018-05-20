//
//  client.h
//
//
//  Created by Abhishek Nema on 20/05/18.
//

#ifndef client_h
#define client_h

#include <boost/asio.hpp>

#include <typeinfo>
#include <string>
#include <boost/units/detail/utility.hpp>

#include "pub_sub.h"
template <typename T>
void client(const array<T,10> &eventList) try {
	dispatcher<T> d;
	Module<T> M(d, eventList);

	while(1) if(tcp::iostream s{"127.0.0.1", "12345"}) {
		T p;
		int i;
		string str;
		s>>i;
		s>>str;
#ifdef DEBUG
		std::cout<<"Length of data type: "<<i<<endl;
		std::cout <<"Client thread got the value "<<str<<endl;
#endif
        if(str == typeid(T).name()){
        	s>>i;
        	s>>p;
#ifdef DEBUG
            std::cout<<"Length of payload: "<<i<<endl;
            cout<<"Its String :"<<p<<endl;
#endif
        	post_events(d,p);
        }
        s.flush();
	}
} catch(std::exception& e) { std::cout << e.what() << '\n'; }
#endif /* client_h */
