CC=g++
INCLUDE_FLAGS=-I. -lglut -lGLU -lGLEW -lGL

all: main.cpp 
	$(CC) -o houseScene *.cpp $(INCLUDE_FLAGS)

run: all
	./houseScene

clean:
	rm ./houseScene	
