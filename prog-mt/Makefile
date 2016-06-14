CXX = compile

all: match

clean:
	rm -f *.o match

%.o: %.cpp %.h
	$(CXX) -g -c $*.cpp -o $*.o

match: match.cpp matchlib.o
	$(CXX) -g match.cpp matchlib.o -o $@



