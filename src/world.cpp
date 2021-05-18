// As fun as modules are, gcc 11 is very new and will likely continue to be a
// headache to work with (just in the install process, never mind CI and CMake
// support). The compiler itself doesn't seem to have many issues, but it will
// be good to let it mature for a bit before it is used full-time.
/*
// Global module fragment
module;
#include <iostream>

export module world;
// Can't do this on gcc yet it seems
//import <iostream>;

export void say_hello()
{
	std::cout << "Hello World\n!";
}
*/

#include <world.hpp>
#include <iostream>
#include <string_view>
#include <ranges>

void say_hello()
{
	// Over-engineered Hello World to ensure we are using C++20.
	for (auto c : std::string_view("\n!dlroW olleH") | std::views::reverse)
		std::cout << c;
}
