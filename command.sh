#!/bin/sh
# to run rcv & sender commands
./build/bin/rcv_int 127.0.0.1 1234 &  
./build/bin/sender_int 127.0.0.1 1234 7
