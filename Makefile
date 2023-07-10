CXXFLAGS= -std=c++20 -Wall -Wextra -pedantic -O2 -ggdb3

cpps := $(wildcard *.cpp)
objects := $(patsubst %.cpp, %.o, ${cpps})
executables := $(patsubst %.cpp, %, ${cpps})

all: ${executables}

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

csv:
	@echo ", user, system, total, cpu, max resident, major faults, minor faults" > data.csv
	@./csv.sh ./seekg_tellg >> data.csv
	@./csv.sh ./istreambuf_iterator >> data.csv
	@./csv.sh ./ostringstream >> data.csv
	@./csv.sh ./while_read_resize >> data.csv
	@./csv.sh ./fstat_fread >> data.csv
	@./csv.sh ./getline_eof >> data.csv
	@./csv.sh ./ignore_seekg >> data.csv
	@./csv.sh ./while_fread >> data.csv
	@./csv.sh ./while_read >> data.csv

test_98M: all prepare_98M time

test_980M: all prepare_980M time

csv_98M: all prepare_98M csv

scim_98M: csv_98M
	sc-im data.csv

scim_980M: csv_980M
	sc-im data.csv

csv_980M: all prepare_980M csv

memcheck_98M: all prepare_98M memcheck

memcheck_980M: all prepare_980M memcheck

clean:
	rm -f ${objects} ${executables}
