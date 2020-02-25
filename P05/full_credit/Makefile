CXXFLAGS = --std=c++17

all: store

store: main.o product.o tax.o taxfree.o
	$(CXX) $(CXXFLAGS) main.o product.o tax.o taxfree.o -o store

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o

product.o:Product.cpp *.h
	$(CXX) $(CXXFLAGS) product.cpp -c -o product.o

taxed.o: Taxed.cpp *.h
	$(CXX) $(CXXFLAGS) tax.cpp -c -o tax.o

taxfree.o: Taxfree.cpp *.h
	$(CXX) $(CXXFLAGS) taxfree.cpp -c -o taxfree.o

product.gch: Product.h
	$(CXX) $(CXXFLAGS) -c product.h -o product.gch
taxed.gch: Taxed.h
	$(CXX) $(CXXFLAGS) -c tax.h -o taxed.gch
taxfree.gch: Taxfree.h
	$(CXX) $(CXXFLAGS) -c taxfree.h -o taxfree.gch


clean:
	rm -f *.o *.gch a.out store