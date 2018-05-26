//
//  client_pub_sub.cpp
//  
//
//  Created by Abhishek Nema on 20/05/18.
//

#include <stdio.h>
#include <array>
#include <boost/thread/scoped_thread.hpp>
#include <string>

#include "client.h"
#include "pub_sub.h"
using namespace std;

/* Main Function */

int main(int argc, char** argv)  {
    if(argc != 3)  {
        std::cerr<<"Wrong Syntax\nUse Command ./client <IP> <PORT>"<<endl;
        return -1;
    }

    string ip = argv[1];
    string port = argv[2];
    
#ifdef CLIENT_INT
    array<int,10> iEventList { { 1,2,3,4,5,6,7,8,9,0 } }; // {{ }}Required in c++11
    boost::scoped_thread<> t(client<int>,iEventList,ip, port);
#endif
    
#ifdef CLIENT_STRING
    array<string,10> sEventList { { "c", "c++", "java", "linux", "android", "macosx","python", "ruby" ,"...", "etc" } }; // {{ }}Required in c++11
    boost::scoped_thread<> t1(client<string>,sEventList,ip, port);
#endif
}
/* End of File */
