cmake_minimum_required(VERSION 3.12...3.20)

project(Everything-But-The-Kitchen-Sink VERSION 1.0
                  DESCRIPTION "For testing things"
                  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Taken from
# https://cliutils.gitlab.io/modern-cmake/chapters/projects/submodule.html
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/cxxopts/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

add_subdirectory(extern/cxxopts)

add_library(world src/world.cpp include/world.hpp)
add_executable(sink src/hello.cpp)

target_link_libraries(sink PRIVATE world)
target_include_directories(sink PRIVATE include)
target_include_directories(world PRIVATE include)

target_include_directories(sink PRIVATE extern/cxxopts/include)

# cxxopts takes a while to compile, so if possible precompile it.
if(COMMAND target_precompile_headers)
	target_precompile_headers(sink PRIVATE extern/cxxopts/include/cxxopts.hpp)
endif()
