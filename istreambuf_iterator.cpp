#include <fstream>
#include <iostream>
#include <vector>

void proc(std::istream& stream)
{
	std::string content((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
	(void)content;
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
