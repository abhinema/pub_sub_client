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
int main(){
    
#ifdef CLIENT_INT
    array<int,10> iEventList { { 1,2,3,4,5,6,7,8,9,0 } }; // {{ }}Required in c++11
    boost::scoped_thread<> t(client<int>, iEventList);
#endif
    
#ifdef CLIENT_STRING
    array<string,10> sEventList { { "c", "c++", "java", "linux", "android", "macosx","python", "ruby" ,"...", "etc" } }; // {{ }}Required in c++11
    boost::scoped_thread<> t1(client<string>, sEventList);
#endif
}
/* End of File */
