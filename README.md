Build Commands:
===============
1. Make build directory.

2.a cmake .. -DWITH_INTEGER=ON
Will build client_int and server_int for integer event passing from server to client.

2.b cmake .. -DWITH_STRING=ON
Will build client_string and server_string for string event passing from server to client.

3. Make

4. Got to bin folder

5. ./client_int & ./server_int 0
# Received Event: 0

./client_int & ./server_int 10
Event :10 ************** Not subscribed ************** 

Events can be changed in client_pub_sub.cpp.