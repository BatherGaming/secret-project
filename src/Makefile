FLAGS = -Wall -Wshadow -Wextra -Wconversion -std=c++11

all: game.o background.o platform.o player.o gui.o shader.o main.o
	g++ -std=c++11 game.o background.o platform.o player.o gui.o shader.o main.o -o main\
	  -L/usr/local/lib -lglfw -pthread\
		-lGLEW -lGLU -lGL -lrt -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lglut -std=c++11

main.o: main.cpp 
	g++ $(FLAGS) -c main.cpp -o $@

game.o : game.cpp game.h background.h platform.h player.h gui.h general.h
	g++ $(FLAGS) -c game.cpp -o $@

background.o : background.cpp background.h game.h general.h
	g++ $(FLAGS) -c background.cpp -o $@

platform.o : platform.cpp platform.h game.h general.h
	g++ $(FLAGS) -c platform.cpp -o $@

player.o : player.cpp player.h game.h platform.h general.h
	g++ $(FLAGS) -c player.cpp -o $@

gui.o: gui.cpp gui.h
	g++ -c gui.cpp -std=c++11

shader.o: shader.cpp shader.hpp
	g++ -c shader.cpp	-std=c++11

.PHONY: clean

clean:
	rm -rf *.o