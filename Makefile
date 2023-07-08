CXXFLAGS= -std=c++20 -Wall -Wextra -pedantic -O2 -ggdb3

all: seekg_tellg istreambuf_iterator ostringstream while_read_resize fstat_fread getline_eof ignore_seekg while_fread while_read

prepare_98M:
	rm -f input
	truncate -s 98M input

prepare_980M:
	rm -f input
	truncate -s 980M input

time:
	@echo
	@./time.sh ./seekg_tellg
	@./time.sh ./istreambuf_iterator
	@./time.sh ./ostringstream
	@./time.sh ./while_read_resize
	@./time.sh ./fstat_fread
	@./time.sh ./getline_eof
	@./time.sh ./ignore_seekg
	@./time.sh ./while_fread
	@./time.sh ./while_read

memcheck:
	@echo
	@./memcheck.sh ./seekg_tellg
	@./memcheck.sh ./istreambuf_iterator
	@./memcheck.sh ./ostringstream
	@./memcheck.sh ./while_read_resize
	@./memcheck.sh ./fstat_fread
	@./memcheck.sh ./getline_eof
	@./memcheck.sh ./ignore_seekg
	@./memcheck.sh ./while_fread
	@./memcheck.sh ./while_read

test_98M: all prepare_98M time

test_980M: all prepare_980M time

memcheck_98M: all prepare_98M memcheck

memcheck_980M: all prepare_980M memcheck
