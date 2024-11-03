#include <common.hpp> 

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

int numberOfBlocks = 7;
SDL_Rect* gBlockClips = new SDL_Rect[numberOfBlocks];
Block gBlockSheet;