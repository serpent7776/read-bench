CXXFLAGS= -std=c++20 -Wall -Wextra -pedantic -O2 -ggdb3 #-stdlib=libc++
# CXX=clang++

# https://stackoverflow.com/a/13375395/5956245
LINK.o = $(LINK.cc)

cpps := $(wildcard *.cpp)
objects := $(sort $(patsubst %.cpp, %_sync.o, ${cpps}) $(patsubst %.cpp, %_unsync.o, ${cpps}))
executables := $(sort $(patsubst %.cpp, %_sync, ${cpps}) $(patsubst %.cpp, %_unsync, ${cpps}))

all: ${executables}

${objects}: Makefile

%_sync.o: %.cpp
	${CXX} -c ${CXXFLAGS} -DSTDIO_SYNC=true -o $@ $<

%_unsync.o: %.cpp
	${CXX} -c ${CXXFLAGS} -DSTDIO_SYNC=false -o $@ $<

prepare_98M:
	rm -f input
	truncate -s 98M input

prepare_980M:
	rm -f input
	truncate -s 980M input

time:
	@echo
	@$(foreach exe, $(executables), ./time.sh ./${exe} &&) true

memcheck:
	@echo
	@$(foreach exe, $(executables), ./memcheck.sh ./${exe} &&) true

csv:
	@echo ", user, system, total, cpu, max resident, major faults, minor faults" > data.csv
	@$(foreach exe, $(executables), ./csv.sh ./${exe} >> data.csv &&) true

test_98M: all prepare_98M time

test_980M: all prepare_980M time

csv_98M: all prepare_98M csv

scim_98M: csv_98M
	sc-im data.csv

scim_980M: csv_980M
	sc-im data.csv

csv_980M: all prepare_980M csv

time_plot_98M: csv_98M
	./plot.sh 98M

time_plot_980M: csv_980M
	./plot.sh 980M

memcheck_98M: all prepare_98M memcheck

memcheck_980M: all prepare_980M memcheck

strace_98M: prepare_98M
	@$(foreach exe, ${executables}, ./strace.sh ./${exe} &&) true

clean:
	rm -f ${objects} ${executables}
