#include <iostream>
#include <cstdio>
#include <cstdlib>

int main(int argc, char** argv)
{
	FILE* file = argc > 1 ? ::fopen(argv[1], "rb") : stdin;
	if (!file) abort();
	const size_t bufsize = 1 << 16;
	size_t capacity = bufsize;
	size_t bytesread = 0;
	char* content = (char*)malloc(capacity);

	while (true)
	{
		if (capacity <= bytesread)
		{
			capacity *= 2;
			content = (char*)realloc(content, capacity);
		}
		if (::fread(content+bytesread, bufsize, 1, file) < 1) break;
		bytesread += bufsize;
	}
	::fclose(file);

	std::cout << bytesread << '\n';
}
