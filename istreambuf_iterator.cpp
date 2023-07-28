#include <fstream>
#include <iostream>
#include <vector>

void proc(std::istream& stream)
{
	stream.exceptions(std::ios_base::badbit | std::ios_base::failbit);
	std::string content((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
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
