# Publisher Subscriber Client and Server
This is C++ code for Pub/Sub design pattern using Client and Server 

### Library Dependencies (Linux Ubuntu 18.04)
sudo apt-get install libboost-all-dev cmake

### Build Commands:

1. Make build directory.

2.a cmake .. -DWITH_INTEGER=ON
Will build client_int and server_int for integer event passing from server to client.

2.b cmake .. -DWITH_STRING=ON
Will build client_string and server_string for string event passing from server to client.

3. Make

### Run:
1. Go to bin folder

2.a 
On one console use ./client_int 127.0.0.1 1234 
and on another use ./server_int 127.0.0.1 1234 0

Client Console will print:  Received Event: 0

2.b
On one console use ./client_string 127.0.0.1 1234 
and on another use ./server_string 127.0.0.1 1234 c++

Client Console will print:  Received Event: c++

Note:
Events can be changed in client_pub_sub.cpp.
