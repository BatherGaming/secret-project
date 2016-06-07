FLAGS = -Wall -Wshadow -Wextra -Wconversion -std=c++11

all: game.o background.o platform.o player.o

game.o : game.cpp game.h background.h platform.h player.h gui.h general.h
	g++ $(FLAGS) -c game.cpp -o $@

background.o : background.cpp background.h game.h general.h
	g++ $(FLAGS) -c background.cpp -o $@

platform.o : platform.cpp platform.h game.h general.h
	g++ $(FLAGS) -c platform.cpp -o $@

player.o : player.cpp player.h game.h platform.h general.h
	g++ $(FLAGS) -c player.cpp -o $@

.PHONY: clean

clean:
	rm -rf *.o