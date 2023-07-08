#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		std::ifstream file(argv[1]);
		std::ostringstream sstr;
		sstr << file.rdbuf();
		std::string content = sstr.str();
		(void)content;
		std::cout << content.size() << '\n';
	}
	else
	{
		std::ostringstream sstr;
		sstr << std::cin.rdbuf();
		std::string content = sstr.str();
		(void)content;
		std::cout << content.size() << '\n';
	}
}
