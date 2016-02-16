CXX=clang++
# CXX=g++

test: MinHeap.o Main.o
	${CXX} MinHeap.o Main.o -o prog2

clean:
	/bin/rm -f *.o MinHeap.o Main.o prog2

MinHeap.o: MinHeap.cpp
	${CXX} -c MinHeap.cpp

Main.o: Main.cpp
	${CXX} -c Main.cpp
