#include <fstream>
#include <iostream>
#include <vector>

void proc(std::istream& stream)
{
	std::streamsize size = stream.tellg();
	stream.seekg(0, std::ios::beg);

	std::vector<char> buffer(size);
	if (stream.read(buffer.data(), size) and stream.gcount() == size) {/* ok */}
	else abort();
	(void)buffer;
	std::cout << buffer.size() << '\n';
}

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		std::ifstream file(argv[1], std::ios::binary | std::ios::ate);
		proc(file);
	}
	else
	{
		std::cin.seekg(0, std::ios::end);
		proc(std::cin);
	}
}
