include ./config.mk

OBJ_GUI = gui/gui.o

OBJ_CORE = core/game.o \
core/background.o \
core/platform.o core/player.o\
	 core/main.o\
	 core/general.o

MODULES = core gui

all:
	for dir in $(MODULES); do \
		(cd $$dir; ${MAKE} all); \
	done	
	$(CXX) $(OBJ_CORE) $(OBJ_GUI) -o wheel $(LIBS)


.PHONY: all clean

clean:
	rm $(OBJ_GUI) $(OBJ_CORE) wheel
	
