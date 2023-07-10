#include <fstream>
#include <iostream>
#include <sstream>

void proc(std::istream& stream)
{
	std::ostringstream sstr;
	sstr << stream.rdbuf();
	std::string content = sstr.str();
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
