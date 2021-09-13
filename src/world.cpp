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

#include "world.hpp"
#include <iostream>
#include <string_view>
#include <ranges>

void say_hello()
{
	const std::string_view hw = "\n!dlroW olleH";
	// Over-engineered Hello World to ensure we are using C++20.
	for (auto c : hw | std::views::reverse)
		std::cout << c;
}

unsigned long long fibb(unsigned n)
{
	if (n <= 1) return n;
	
	unsigned long long prev_prev = 0, prev = 1;
	
	for (unsigned k = 2; k <= n; ++k)
	{
		const unsigned long long current = prev + prev_prev;
		
		prev_prev = prev;
		prev = current;
	}
	
	return prev;
}
