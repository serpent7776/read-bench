#include <iostream>
#include <cstdio>
#include <sys/stat.h>

int main(int argc, char** argv)
{
	std::string content;
	FILE* file = argc > 1 ? ::fopen(argv[1], "rb") : stdin;
	if (!file) abort();
	struct stat st;
	if (::fstat(::fileno(file), &st) == -1) abort();

	content.resize(st.st_size);
	::fread(&*content.begin(), 1, st.st_size, file);
	::fclose(file);

	(void)content;
	std::cout << content.size() << '\n';
}
