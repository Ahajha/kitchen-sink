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
