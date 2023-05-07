all : ./src/main.cpp
CMD :=
ifeq ($(OS),Windows_NT)
	CMD += -Ithird_party/include -Lthird_party/lib ./src/main.cpp -lmingw32
else
	UNAME_M := $(shell uname -m)
	ifeq ($(UNAME_M), x86_64)
		CMD += ./src/main.cpp
	endif
	ifeq ($(UNAME_M), arm64)
		CMD += -I/opt/homebrew/include -L/opt/homebrew/lib ./src/main.cpp
	endif
endif

all : ./src/main.cpp
	g++ $(CMD) -lSDL2 -lSDL2_image -lSDL2_ttf -o game