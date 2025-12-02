all: bin/encrage

bin/encrage: bin/main.o bin/image.o bin/pixel.o
	g++ -Wall -std=c++11 -o bin/encrage bin/main.o bin/image.o bin/pixel.o -lm


bin/main.o: src/main.cpp src/image.h src/pixel.h
	g++ -Wall -std=c++11 -c src/main.cpp -o bin/main.o

bin/image.o: src/image.cpp src/image.h src/pixel.h
	g++ -Wall -std=c++11 -c src/image.cpp -o bin/image.o

bin/pixel.o: src/pixel.cpp src/pixel.h
	g++ -Wall -std=c++11 -c src/pixel.cpp -o bin/pixel.o

clean:
	rm -f bin/*.o

test: bin/encrage
	./bin/encrage test.ascii.pgm resultat_test.pgm 30 2.0 100

baboon: bin/encrage
	./bin/encrage baboon.reduced.pgm resultat_baboon.pgm 5 400 100