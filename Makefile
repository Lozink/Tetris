all:
	g++ -Isrc/Include -Lsrc/lib -o main main.cpp src/lib/Block.cpp src/lib/common.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image