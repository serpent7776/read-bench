#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		std::string content;
		std::ifstream file(argv[1]);
		std::getline(file, content, std::string::traits_type::to_char_type(
				std::string::traits_type::eof()));
		(void)content;
		std::cout << content.size() << '\n';
	}
	else
	{
		std::string content;
		std::getline(std::cin, content, std::string::traits_type::to_char_type(
				std::string::traits_type::eof()));
		(void)content;
		std::cout << content.size() << '\n';
	}
}
