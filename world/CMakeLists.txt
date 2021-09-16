add_library(world STATIC src/world.cpp include/world.hpp)

target_include_directories(world PUBLIC include/ ${DOCTEST_INCLUDE_DIR})
