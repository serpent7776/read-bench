#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		std::ifstream file(argv[1], std::ios::binary | std::ios::ate);
		std::streamsize size = file.tellg();
		file.seekg(0, std::ios::beg);

		std::vector<char> buffer(size);
		if (file.read(buffer.data(), size) and file.gcount() == size) {/* ok */}
		else abort();
		(void)buffer;
		std::cout << buffer.size() << '\n';
	}
	else
	{
		std::cin.seekg(0, std::ios::end);
		std::streamsize size = std::cin.tellg();
		std::cin.seekg(0, std::ios::beg);

		std::vector<char> buffer(size);
		if (std::cin.read(buffer.data(), size) and std::cin.gcount() == size) {/* ok */}
		else abort();
		(void)buffer;
		std::cout << buffer.size() << '\n';
	}
}
