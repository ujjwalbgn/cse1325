CXXFLAGS += --std=c++17

all: elsa

elsa: main.o customer.o desktop.o options.o order.o store.o *.h
	$(CXX) $(CXXFLAGS) main.o customer.o desktop.o options.o order.o store.o  -o elsa

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o

customer.o: customer.cpp *.h
	$(CXX) $(CXXFLAGS) customer.cpp -c -o customer.o

desktop.o: desktop.cpp *.h
	$(CXX) $(CXXFLAGS) desktop.cpp -c -o desktop.o

options.o: options.cpp *.h
	$(CXX) $(CXXFLAGS) options.cpp -c -o options.o
	
store.o: store.cpp *.h
	$(CXX) $(CXXFLAGS) store.cpp -c -o store.o

clean:
	rm -f *.o *.gch a.out elsa
