![C/C++ CI](https://github.com/abhinema/pub_sub_client/workflows/C/C++%20CI/badge.svg?branch=master)

# Publisher Subscriber Client and Server

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/ccfaa45653fb409694ea7508edf144c7)](https://app.codacy.com/manual/abhinema/pub_sub_client?utm_source=github.com&utm_medium=referral&utm_content=abhinema/pub_sub_client&utm_campaign=Badge_Grade_Dashboard)

This is C++ code for Pub/Sub design pattern using Receive and Sender 

### Library Dependencies (Linux Ubuntu 18.04)
sudo apt-get install libboost-all-dev cmake

### Build Commands:

## 1. Make build directory.

## 2.a cmake .. -DWITH_INTEGER=ON
Will build rcv_int and sender_int for integer event passing from sender to receive modules.

## 2.b cmake .. -DWITH_STRING=ON
Will build rcv_string and sender_string for string event passing from sender to receive modules.

## 3. Make
Run Make command

### Run:
## 1. Go to bin folder

## 2.a 
On one console use ./rcv_int 127.0.0.1 1234 
and on another use ./sender_int 127.0.0.1 1234 0

Client Console will print:  Received Event: 0

## 2.b
On one console use ./rcv_string 127.0.0.1 1234 
and on another use ./sender_string 127.0.0.1 1234 c++

Client Console will print:  Received Event: c++

# Note:
Events can be changed in client_pub_sub.cpp.
