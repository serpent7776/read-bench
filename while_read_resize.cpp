#include <fstream>
#include <iostream>

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		std::ifstream file(argv[1]);
		std::string content;
		const size_t bufsize = 1 << 16;
		size_t offset = 0;
		size_t count = 0;
		while(file)
		{
			content.resize(++count * bufsize);
			file.read(&*content.begin() + offset, bufsize);
			offset += file.gcount();
		}
		content.resize(offset);
		(void)content;
		std::cout << content.size() << '\n';
	}
	else
	{
		std::string content;
		const size_t bufsize = 1 << 16;
		size_t offset = 0;
		size_t count = 1;
		while(std::cin)
		{
			content.resize(++count * bufsize);
			std::cin.read(&*content.begin() + offset, bufsize);
			offset += std::cin.gcount();
		}
		content.resize(offset);
		(void)content;
		std::cout << content.size() << '\n';
	}
}
