
GXX49_VERSION := $(shell g++-4.9 --version 2>/dev/null)

ifdef GXX49_VERSION
	CXX_COMMAND := g++-4.9
else
	CXX_COMMAND := g++
endif

CXX = ${CXX_COMMAND} -std=c++14 -Wall

all: test project2_timing

run_project1: project1
	./project1

headers: rubrictest.hpp timer.hpp project2.hpp

project2_test: headers project2_test.cpp
	${CXX} project2_test.cpp -o project2_test

test: project2_test
	./project2_test

project2_timing: headers project2_timing.cpp
	${CXX} project2_timing.cpp -o project2_timing

clean:
	rm -f project2_test project2_timing
