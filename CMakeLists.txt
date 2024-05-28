cmake_minimum_required(VERSION 3.28)
project(untitled1)

set(CMAKE_CXX_STANDARD 23)
INCLUDE(FindProtobuf)

FIND_PACKAGE(Protobuf REQUIRED)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS js_event.proto)
add_executable(client client.cpp
        js_event.pb.cc
)
target_link_libraries(client PRIVATE protobuf::libprotobuf)
add_executable(server server.cpp
        js_event.pb.cc
)
target_link_libraries(server PRIVATE protobuf::libprotobuf)