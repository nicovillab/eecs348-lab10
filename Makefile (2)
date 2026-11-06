CXX = g++
CXXFLAGS = -Wall -Wextra

all: matrix

matrix: main.o matrix.o
	$(CXX) $(CXXFLAGS) -o matrix main.o matrix.o

main.o: main.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c main.cpp

matrix.o: matrix.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c matrix.cpp

clean:
	rm -f matrix *.o
