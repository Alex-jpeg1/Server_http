cmake_minimum_required(VERSION 3.20)

project(Server)

set(INCLUDE_PATHS  boost_1_81_0 boost_1_81_0/boost/asio  boost_1_81_0/boost crow/include)

set(CMAKE_CXX_STANDARD 17)

add_executable(Server src/main.cpp)

target_include_directories(Server PUBLIC ${INCLUDE_PATHS})

target_link_libraries(Server PRIVATE pthread)

