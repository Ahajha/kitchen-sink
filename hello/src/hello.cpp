//import world;
#include <world.hpp>
#include <cxxopts.hpp>

int main(int argc, char** argv)
{
	// This section is from the example at
	// https://github.com/jarro2783/cxxopts
	cxxopts::Options options("test", "A brief description");

    options.add_options()
        ("f,foo", "Param foo", cxxopts::value<int>()->default_value("10"))
        ("b,bar", "Param bar", cxxopts::value<std::string>())
        ("d,debug", "Enable debugging")
        ("h,help", "Print usage")
    ;

    auto result = options.parse(argc, argv);
    
    if (result.count("help"))
    {
    	std::cout << options.help() << '\n';
    	return 0;
	}
	
	if (result.count("debug"))
	{
		std::cout << "debugging on\n";
	}
	
	std::cout << "Foo: " << result["foo"].as<int>() << '\n';
	std::cout << "Bar: " << result["bar"].as<std::string>() << '\n';
    
	say_hello();
}
