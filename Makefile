CC = g++
CXXFLAGS = -Wall -Werror -pedantic -std=c++11 
EXECUTABLE = treecheck

############################### 
# Build
###############################

all: treecheck.o
	${CC} ${CXXFLAGS} -o ${EXECUTABLE} $^

treecheck.o: treecheck.cpp 
	${CC} ${CXXFLAGS} -c treecheck.cpp

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
