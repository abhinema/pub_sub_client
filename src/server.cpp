//
//  server.cpp
//  
//
//  Created by Abhishek Nema on 20/05/18.
//

#include <stdio.h>
#include "server.h"

int main(int argc, char** argv)  {
    if(argc != 4)  {
        std::cerr<<"Wrong Syntax\nUse Command ./server <IP> <PORT> <DATA/STRING>"<<endl;
        return -1;
    }

    string ip = argv[1];
    short unsigned int port = atoi(argv[2]);

#ifdef SERVER_INT
    int i = atoi(argv[3]);
    boost::scoped_thread<> t1(server<int>,i ,ip, port);
#endif
    
#ifdef SERVER_STRING
    string i = argv[3];
    boost::scoped_thread<> t1(server<string>,i,ip, port);
#endif
    return 0;
}
/* End of File */
