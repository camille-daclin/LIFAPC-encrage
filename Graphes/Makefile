all: bin/test

bin/test: obj/test.o obj/pixel.o
		g++ -Wall -g obj/test.o obj/pixel.o -o bin/test.exe

obj/test.o: src/test.cpp src/pixel.h
		g++ -Wall -g -c src/test.cpp -o obj/test.o

obj/pixel.o:  src/pixel.cpp src/pixel.h
		g++  -Wall -g -c src/pixel.cpp -o obj/pixel.o

clean: 
		rm obj/*.o