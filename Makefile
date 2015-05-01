CC = g++
CXXFLAGS = -Wall -Werror -pedantic -std=c++11 
EXECUTABLE = treecheck

############################### 
# Build
###############################

all: treecheck.o tree.o
	${CC} ${CXXFLAGS} -o ${EXECUTABLE} $^

treecheck.o: treecheck.cpp tree.h
	${CC} ${CXXFLAGS} -c treecheck.cpp

tree.o: tree.cpp tree.h
	${CC} ${CXXFLAGS} -c tree.cpp

############################### 
# Tests
###############################

test: test/runner
	test/runner

test-valgrind: test/runner
	valgrind test/runner

test/runner: test/runner.o test/tree.o tree.o
	${CC} ${CXXFLAGS} -o test/runner $^

test/runner.o: test/runner.cpp
	${CC} ${CXXFLAGS} -c test/runner.cpp -o test/runner.o

test/tree.o: test/tree.cpp
	${CC} ${CXXFLAGS} -c test/tree.cpp -o test/tree.o

inputs: million all
	for f in inputs/*.in; do ./${EXECUTABLE} $$f; done

million: 
	seq 1000000 | shuf > inputs/million.in

############################### 
# Misc
###############################

clean:
	rm -f *.tgz ${EXECUTABLE} test/runner inputs/million.in
	find . -name "*.o" -type f -delete

package: clean 
	tar -cvzf alg3_patzl_if14b048_steinberger_if14b049.tgz *.md *.pdf Makefile *.cpp *.h test inputs

valgrind: all
	valgrind ./${EXECUTABLE}

.PHONY: docs
docs: design.md 
	pandoc --latex-engine=xelatex --mathjax -f markdown -o design.pdf design.md

run: all
	./${EXECUTABLE}
