cmake_minimum_required(VERSION 3.7...3.20)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(Everything-But-The-Kitchen-Sink VERSION 1.0
                  DESCRIPTION "For testing things"
                  LANGUAGES CXX)

add_library(world src/world.cpp include/world.hpp)
add_executable(sink src/hello.cpp)

target_link_libraries(sink PRIVATE world)
target_include_directories(sink PRIVATE include)
target_include_directories(world PRIVATE include)
