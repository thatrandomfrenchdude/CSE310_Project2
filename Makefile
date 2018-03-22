run	:main.o heap.o util.o
	g++ -o run -std=c++11 main.o heap.o util.o

main.o	:main.cpp main.hpp heap.hpp util.hpp
	g++ -c -std=c++11 main.cpp

heap.o	:heap.cpp main.hpp heap.hpp util.hpp
	g++ -c -std=c++11 heap.cpp

util.o	:util.cpp main.hpp heap.hpp util.hpp
	g++ -c -std=c++11 util.cpp

clean	:
	rm *.o 

cleanAll	:
	rm *.o run
