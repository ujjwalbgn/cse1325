CXXFLAGS = --std=c++17

all: color main test

coin: main.o coin.o *.h
	$(CXX) $(CXXFLAGS) main.o coin.o -o coin

test: main.o test.o *.h
	$(CXX) $(CXXFLAGS) main.o test.o -o test

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
main.o: color.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o coin.o

clean:
	rm -f *.o *.gch ~* a.out color test