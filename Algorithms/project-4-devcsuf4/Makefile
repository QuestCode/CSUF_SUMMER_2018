
GXX49_VERSION := $(shell g++-4.9 --version 2>/dev/null)

ifdef GXX49_VERSION
	CXX_COMMAND := g++-4.9
else
	CXX_COMMAND := g++
endif

CXX = ${CXX_COMMAND} -std=c++14 -Wall

all: test dynamic_subsequence_timing

headers: rubrictest.hpp timer.hpp dynamic_subsequence.hpp

dynamic_subsequence_test: headers dynamic_subsequence_test.cpp
	${CXX} dynamic_subsequence_test.cpp -o dynamic_subsequence_test

test: dynamic_subsequence_test
	./dynamic_subsequence_test

dynamic_subsequence_timing: headers dynamic_subsequence_timing.cpp
	${CXX} dynamic_subsequence_timing.cpp -o dynamic_subsequence_timing

clean:
	rm -f dynamic_subsequence_test dynamic_subsequence_timing
