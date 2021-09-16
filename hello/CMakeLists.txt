add_executable(sink src/hello.cpp)

target_link_libraries(sink PUBLIC cxxopts world)
