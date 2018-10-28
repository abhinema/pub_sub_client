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
#include <boost/thread/scoped_thread.hpp>

#include "pub_sub.h"

template <typename T>
void client(string ip, string port, dispatcher<T> &d) try {

	while(1) if(tcp::iostream s{ip.c_str(), port.c_str()}) {
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
