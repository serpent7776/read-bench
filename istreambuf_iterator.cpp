#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		std::ifstream file(argv[1]);
		std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
		(void)content;
		std::cout << content.size() << '\n';
	}
	else
	{
		std::string content((std::istreambuf_iterator<char>(std::cin)), std::istreambuf_iterator<char>());
		(void)content;
		std::cout << content.size() << '\n';
	}
}
