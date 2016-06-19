all: gui.o drawable.o

gui.o: gui.cpp gui.h general.h
	g++ -std=c++11 -c gui.cpp

drawable.o: drawable.cpp drawable.h general.h
	g++ -std=c++11 -c drawable.cpp

.PHONY: all