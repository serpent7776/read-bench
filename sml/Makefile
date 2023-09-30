outputs := test_mlton test_mlkit test_poly test_smlnj
executables := test_mlton test_mlkit test_poly

all: ${outputs}

prepare_98M:
	rm -f input
	truncate -s 98M input

prepare_980M:
	rm -f input
	truncate -s 980M input

time:
	@echo
	@$(foreach exe, $(outputs), ./time.sh ./${exe} &&) true

test_98M: all prepare_98M time

test_980M: all prepare_980M time

strace_98M: prepare_98M
	@$(foreach exe, ${executables}, ./strace.sh ./${exe} &&) true

test_mlton: MltonTest.sml Test.sml test.mlb
	mlton -output test_mlton test.mlb

test_mlkit: MltonTest.sml Test.sml test.mlb
	mlkit -o test_mlkit test.mlb

test_poly: PolyTest.sml Test.sml
	polyc -o test_poly PolyTest.sml

.PHONY: test_smlnj
test_smlnj: SmlnjTest.sml Test.sml test.cm
	ml-build test.cm Smlnj.main
