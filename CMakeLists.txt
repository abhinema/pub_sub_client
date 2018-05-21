# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.0)

# Project's name
project(publisher_subscriber_with_client_server)
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
  add_definitions(-D CLIENT_INT)
  add_executable(client_int ${PROJECT_SOURCE_DIR}/src/client_pub_sub.cpp)
  target_link_libraries(client_int ${LIBRARIES} ${ADDITIONAL_LIBRARIES})

  add_definitions(-D SERVER_INT)
  add_executable(server_int ${PROJECT_SOURCE_DIR}/src/server.cpp)
  target_link_libraries(server_int ${LIBRARIES} ${ADDITIONAL_LIBRARIES})

else(WITH_STRING)
  add_definitions(-D CLIENT_STRING)
  add_executable(client_string ${PROJECT_SOURCE_DIR}/src/client_pub_sub.cpp)
  target_link_libraries(client_string ${LIBRARIES} ${ADDITIONAL_LIBRARIES})

  add_definitions(-D SERVER_STRING)
  add_executable(server_string ${PROJECT_SOURCE_DIR}/src/server.cpp)
  target_link_libraries(server_string ${LIBRARIES} ${ADDITIONAL_LIBRARIES})
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O3 -Wall -Wextra")

