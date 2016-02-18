CXX=clang++
# CXX=g++

hoffman: MinHeap.o Main.o
	${CXX} MinHeap.o Main.o -o hoffman

clean:
	/bin/rm -f *.o MinHeap.o Main.o hoffman

MinHeap.o: MinHeap.cpp
	${CXX} -c MinHeap.cpp

Main.o: Main.cpp
	${CXX} -c Main.cpp
