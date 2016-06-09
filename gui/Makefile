all: gui.o shader.o
	g++ gui.o shader.o -L/usr/local/lib -lglfw -pthread\
		-lGLEW -lGLU -lGL -lrt -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lglut -std=c++11

gui.o: gui.cpp gui.h
	g++ -c gui.cpp -std=c++11

shader.o: shader.cpp shader.hpp
	g++ -c shader.cpp	-std=c++11