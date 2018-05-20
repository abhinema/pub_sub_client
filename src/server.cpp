//
//  server.cpp
//  
//
//  Created by Abhishek Nema on 20/05/18.
//

#include <stdio.h>
#include "server.h"

int main(int argc, char** argv)  {
    if(argc != 2)  {
        std::cerr<<"Wrong Syntax\nUse Command ./server <DATA/STRING>"<<endl;
        return -1;
    }
#ifdef SERVER_INT
    int i = atoi(argv[1]);
    boost::scoped_thread<> t1(server<int>,i);
#endif
    
#ifdef SERVER_STRING
    string i = argv[1];
    boost::scoped_thread<> t1(server<string>,i);
#endif
    return 0;
}
/* End of File */
