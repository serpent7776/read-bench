#include <iostream>
#include <fstream>
#include <limits>

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		std::ifstream file(argv[1]);
		file.ignore(std::numeric_limits<std::streamsize>::max());
		std::string content(file.gcount(), 0);
		file.seekg(0);
		file.read(&*content.begin(), content.size());
		(void)content;
		std::cout << content.size() << '\n';
	}
	else
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		std::string content(std::cin.gcount(), 0);
		std::cin.seekg(0);
		std::cin.read(&*content.begin(), content.size());
		(void)content;
		std::cout << content.size() << '\n';
	}
}
