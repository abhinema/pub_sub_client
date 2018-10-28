# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.0)

# Project's name
project(publisher_subscriber_with_client_and_sender)
# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)

# The following folder will be included
include_directories("${INCLUDE_PATH}")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

option(WITH_INTEGER "Option description" OFF)
option(WITH_STRING "Option description" OFF)

set(LIBRARIES -pthread -lboost_system)

if(APPLE)
    set(ADDITIONAL_LIBRARIES -lboost_thread-mt)
else (UNIX AND NOT APPLE)
    set(ADDITIONAL_LIBRARIES -lboost_thread)
endif()


if(WITH_INTEGER)
  add_definitions(-D RCV_INT)
  add_executable(rcv_int ${PROJECT_SOURCE_DIR}/src/client_pub_sub.cpp)
  target_link_libraries(rcv_int ${LIBRARIES} ${ADDITIONAL_LIBRARIES})

  add_definitions(-D SENDER_INT)
  add_executable(sender_int ${PROJECT_SOURCE_DIR}/src/sender.cpp)
  target_link_libraries(sender_int ${LIBRARIES} ${ADDITIONAL_LIBRARIES})

else(WITH_STRING)
  add_definitions(-D RCV_STRING)
  add_executable(rcv_string ${PROJECT_SOURCE_DIR}/src/client_pub_sub.cpp)
  target_link_libraries(rcv_string ${LIBRARIES} ${ADDITIONAL_LIBRARIES})

  add_definitions(-D SENDER_STRING)
  add_executable(sender_string ${PROJECT_SOURCE_DIR}/src/sender.cpp)
  target_link_libraries(sender_string ${LIBRARIES} ${ADDITIONAL_LIBRARIES})
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O3 -Wall -Wextra")

