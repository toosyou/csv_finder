CXX = g++

all: cf

cf: csv_finder.cpp
	$(CXX) csv_finder.cpp -o $@

clean:
	rm -rf cf
