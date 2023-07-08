#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstdlib>

int main(int argc, char** argv)
{
	const int file = argc > 1 ? ::open(argv[1], O_RDONLY) : 0;
	if (file < 0) abort();
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
		const ssize_t n = ::read(file, content+bytesread, bufsize);
		if (n < 1) break;
		bytesread += n;
	}
	::close(file);

	(void)content;
	std::cout << bytesread << '\n';
}
