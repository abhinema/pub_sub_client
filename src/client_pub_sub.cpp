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

#include "receiver.h"
#include "pub_sub.h"
using namespace std;

/* 
 * User Defined functions 
 * These functions will be called with subscribe events
 */
#ifdef RCV_STRING
/* 
 * codacy Issue: Function parameter 'a' should be passed by const reference.
 */
int parse( const string &a){
    cout<<"Received Event: "<<a<<" in parse() api"<<a<<endl;     
return 0;
}
/* 
 * codacy Issue: Function parameter 'a' should be passed by const reference.
 */

int anotherParse( const string &a){
    cout<<"Received Event: "<<a<<" in anotherParse() api"<<a<<endl;     
return 0;
}
#elif RCV_INT
int parse(int a){
    cout<<"Received Event: "<<a<<" in parse() api"<<a<<endl;     
return 0;
}

int anotherParse(int a){
    cout<<"Received Event: "<<a<<" in anotherParse() api"<<a<<endl;     
return 0;
}
#endif

/* 
 * Main Function
 * Here we will create one or more dispatchers and connect with client in a thread 
 */
int main(int argc, char** argv)  {
    if(argc != 3)  {
        std::cerr<<"Wrong Syntax\nUse Command ./client <IP> <PORT>"<<endl;
        return -1;
    }

    string ip = argv[1];
    string port = argv[2];
    
#ifdef RCV_INT
  	dispatcher<int> intDispatcher;
    array<int,10> iEventList { { 1,2,3,4,5,6,7,8,9,0 } }; // {{ }}Required in c++11
    array<int,20> iOtherEventList { { 1,2,3,4,5,6,7,8,9,0,
                                      11,12,13,14,15,16,17,18,19,20 } }; // {{ }}Required in c++11
/* Assigning Event List to Handler Functions */    
    Module<int> M1(intDispatcher, iEventList,parse);
    Module<int> M2(intDispatcher, iOtherEventList,anotherParse);
    boost::scoped_thread<> t(client<int>,ip, port,intDispatcher);    
    
#elif RCV_STRING

  	dispatcher<string> stringDispatcher;
    array<string,10> sEventList { { "c", "c++", "java", "linux", "android", 
                                    "macosx","python", "ruby" ,"...", "etc" } }; // {{ }}Required in c++11
    array<string,20> sOtherEventList { { "c", "c++", "java", "linux", "android", 
                                    "macosx","python", "ruby" ,"...", "etc",
                                    "one","two","three","four","five","six",
                                    "seven","eight","nine","zero"} }; // {{ }}Required in c++11
    /* Assigning Event List to Handler Functions */
    Module<string> M1(stringDispatcher, sEventList,parse);
    Module<string> M2(stringDispatcher, sOtherEventList,anotherParse);
    boost::scoped_thread<> t(client<string>,ip, port,stringDispatcher);    
    
#endif
}
/* End of File */

