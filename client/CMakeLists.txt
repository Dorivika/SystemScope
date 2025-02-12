cmake_minimum_required(VERSION 3.14)
project(SystemMonitorClient)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system)

add_executable(client
    src/main.cpp
)

target_include_directories(client PRIVATE include)
target_link_libraries(client PRIVATE Boost::system)