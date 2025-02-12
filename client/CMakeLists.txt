cmake_minimum_required(VERSION 3.14)
project(SystemMonitorClient)

set(CMAKE_CXX_STANDARD 17)

# Add WebSocket++
include_directories(${CMAKE_SOURCE_DIR}/third_party/websocketpp)

add_executable(client
    src/main.cpp
)

target_link_libraries(client PRIVATE ws2_32)