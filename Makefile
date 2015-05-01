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

million: all
	seq 1000000 | shuf | ./${EXECUTABLE}

############################### 
# Misc
###############################

clean:
	rm -f *.zip ${EXECUTABLE} test/runner
	find . -name "*.o" -type f -delete

zip: clean 
	zip -r patzl_if14b048_steinberger_if14b049.zip . -x .git/ -x .gitignore -x .git/**\* -x *.pdf -x *.in

valgrind: all
	valgrind ./${EXECUTABLE}

run: all
	./${EXECUTABLE}
