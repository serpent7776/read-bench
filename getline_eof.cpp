#include <iostream>
#include <fstream>

void proc(std::istream& stream)
{
	stream.exceptions(std::ios_base::badbit | std::ios_base::failbit);
	std::string content;
	std::getline(stream, content, std::string::traits_type::to_char_type(
			std::string::traits_type::eof()));
	std::cout << content.size() << '\n';
}

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		std::ifstream file(argv[1]);
		proc(file);
	}
	else
	{
		proc(std::cin);
	}
}
