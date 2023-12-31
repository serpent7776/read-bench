#include <fstream>
#include <iostream>
#include <sstream>

void proc(std::istream& stream)
{
	stream.exceptions(std::ios_base::badbit | std::ios_base::failbit);
	std::ostringstream sstr;
	sstr << stream.rdbuf();
	std::string content = sstr.str();
	std::cout << content.size() << '\n';
}

int main(int argc, char** argv)
{
	std::ios_base::sync_with_stdio(STDIO_SYNC);
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
