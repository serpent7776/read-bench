#include <fstream>
#include <iostream>
#include <vector>

void proc(std::istream& stream)
{
	std::streamsize size = stream.tellg();
	if (size == -1) abort();
	stream.seekg(0, std::ios::beg);

	std::vector<char> buffer(size);
	if (stream.read(buffer.data(), size) and stream.gcount() == size) {/* ok */}
	else abort();
	std::cout << buffer.size() << '\n';
}

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		std::ifstream file(argv[1], std::ios::binary | std::ios::ate);
		file.exceptions(std::ios_base::badbit | std::ios_base::failbit);
		proc(file);
	}
	else
	{
		std::cin.exceptions(std::ios_base::badbit | std::ios_base::failbit);
		std::cin.seekg(0, std::ios::end);
		proc(std::cin);
	}
}
