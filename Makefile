OS_SYSTEM :=
ifeq ($(OS),Windows_NT)
	OS_SYSTEM = WINDOWS
else
	UNAME_M := $(shell uname -m)
	ifeq ($(UNAME_M), x86_64)
		OS_SYSTEM = MAC64
	endif
	ifeq ($(UNAME_M), arm64)
		OS_SYSTEM = MACARM
	endif
endif

SDL2_LIB := 
ifeq ($(OS_SYSTEM),WINDOWS)
	SDL2_LIB = -Ithird_party/include -Lthird_party/lib
else
	ifeq ($(OS_SYSTEM), MACARM)
		SDL2_LIB = -I/opt/homebrew/include -L/opt/homebrew/lib
	endif
endif

SDL2_OPTIONS :=
ifeq ($(OS_SYSTEM), WINDOWS)
	SDL2_OPTIONS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
else
	SDL2_OPTIONS = -lSDL2 -lSDL2_image -lSDL2_ttf
endif

_OFILE = screen.o picture.o map.o
_C_OPTION = -std=c++11

all : game

clean :
	rm -f *.o
	rm -f game

game : ./src/main.cpp $(_OFILE)
	g++ $^ -o $@ $(SDL2_LIB) $(SDL2_OPTIONS) $(_C_OPTION) 

screen.o : ./src/views/screen.cpp 
	g++ $^ -c -o $@ $(SDL2_LIB) $(SDL2_OPTIONS) $(_C_OPTION) 

picture.o : ./src/views/picture.cpp
	g++ $^ -c -o $@ $(SDL2_LIB) $(SDL2_OPTIONS) $(_C_OPTION)

map.o : ./src/views/map.cpp
	g++ $^ -c -o $@ $(SDL2_LIB) $(SDL2_OPTIONS) $(_C_OPTION)