cmake_minimum_required(VERSION 3.12...3.20)

project(Everything-But-The-Kitchen-Sink VERSION 1.0
                  DESCRIPTION "For testing things"
                  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(world src/world.cpp include/world.hpp)
add_executable(sink src/hello.cpp)

target_link_libraries(sink PRIVATE world)
target_include_directories(sink PRIVATE include)
target_include_directories(world PRIVATE include)
