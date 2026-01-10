cmake_minimum_required(VERSION 3.30)
project(ConsoleApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ConsoleApp ConsoleApp.cpp)

target_link_libraries(ConsoleApp Core)
