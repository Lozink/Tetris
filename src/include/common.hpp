#ifndef COMMON_H
#define COMMON_H

#include <SDL2/SDL.h>
#include <Block.hpp>

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;

extern int numberOfBlocks;
extern SDL_Rect* gBlockClips;
extern Block gBlockSheet;

#endif