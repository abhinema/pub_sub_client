//
//  sender.cpp
//  
//
//  Created by Abhishek Nema on 20/05/18.
//

#include <stdio.h>
#include "sender.h"

int main(int argc, char** argv)  {
    if(argc != 4)  {
        std::cerr<<"Wrong Syntax\nUse Command ./sender <IP> <PORT> <DATA/STRING>"<<endl;
        return -1;
    }

    string ip = argv[1];
    short unsigned int port = atoi(argv[2]);

#ifdef SENDER_INT
    int dataToSend = atoi(argv[3]);
    boost::scoped_thread<> t1(server<int>, dataToSend, ip, port);
#endif
    
#ifdef SENDER_STRING
    string dataToSend = argv[3];
    boost::scoped_thread<> t1(server<string>, dataToSend, ip, port);
#endif
    return 0;
}
/* End of File */

