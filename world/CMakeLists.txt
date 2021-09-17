add_library(world OBJECT src/world.cpp include/world.hpp)

target_include_directories(world PUBLIC include/ ${DOCTEST_INCLUDE_DIR})
