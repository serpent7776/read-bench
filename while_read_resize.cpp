#include <fstream>
#include <iostream>

void proc(std::istream& stream)
{
	std::string content;
	const size_t bufsize = 1 << 16;
	size_t offset = 0;
	size_t count = 0;
	while(stream)
	{
		content.resize(++count * bufsize);
		stream.read(&*content.begin() + offset, bufsize);
		offset += stream.gcount();
	}
	content.resize(offset);
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
