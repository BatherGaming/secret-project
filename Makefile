all: main.o shader.o
	g++ main.o shader.o -L/usr/local/lib -lglfw -pthread\
		-lGLEW -lGLU -lGL -lrt -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lglut

main.o: main.cpp
	g++ -c main.cpp 

shader.o: shader.cpp shader.hpp
	g++ -c shader.cpp	