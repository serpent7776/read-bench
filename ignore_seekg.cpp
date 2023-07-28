#include <iostream>
#include <fstream>
#include <limits>

void proc(std::istream& stream)
{
	stream.exceptions(std::ios_base::badbit | std::ios_base::failbit);
	stream.ignore(std::numeric_limits<std::streamsize>::max());
	std::string content(stream.gcount(), 0);
	stream.seekg(0);
	stream.read(content.data(), content.size());
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
