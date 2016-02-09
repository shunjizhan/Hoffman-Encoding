CXX=clang++
# CXX=g++


MinHeap.o: MinHeap.cpp
	${CXX} -c MinHeap.cpp

Main.o: Main.cpp
	${CXX} -c Main.cpp

test: MinHeap.o Main.o
	${CXX} MinHeap.o Main.o -o encode

clean:
	/bin/rm -f *.o MinHeap.o Main.o encode
