ifeq ($(OS),Windows_NT)
all : ./src/main.cpp
	g++ -Ithird_party/include -Lthird_party/lib ./src/main.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -o game
else
all : ./src/main.cpp
	g++ ./src/main.cpp -lSDL2 -lSDL2_image -lSDL2_ttf -o game
endif
