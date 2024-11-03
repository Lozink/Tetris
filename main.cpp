#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <Block.hpp>
#include <common.hpp>

#define SCREEN_WIDTH 720 
#define SCREEN_HEIGHT 900

bool init();

bool loadMedia();

void close();

int main(int argc, char** argv){

    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            SDL_Event e;
            bool quit = false;
            while (!quit)
            {
                while (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }

                    SDL_Rect* currentBlockClip = &gBlockClips[0];
                    gBlockSheet.render((SCREEN_WIDTH - currentBlockClip->w) / 2, (SCREEN_HEIGHT - currentBlockClip->h) / 2, currentBlockClip);

                    SDL_RenderPresent(gRenderer);
                }
            }
        }
    }
    close();

    return 0;
}

bool init()
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                int imgFlags = IMG_INIT_PNG;
                if(!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }   
    return success;
}

bool loadMedia()
{
    bool success = true;

    if (!gBlockSheet.loadFromFile("images/blocks.png"))
    {
        printf("Failed to load blocks sheet !\n");
        success = false;
    }
    else
    {
        gBlockClips[0].x = 0;
        gBlockClips[0].y = 133;
        gBlockClips[0].w = 533;
        gBlockClips[0].h = 266;

        gBlockClips[1].x = 0;
        gBlockClips[1].y = 0;
        gBlockClips[1].w = 0;
        gBlockClips[1].h = 0;

        gBlockClips[2].x = 0;
        gBlockClips[2].y = 0;
        gBlockClips[2].w = 0;
        gBlockClips[2].h = 0;

        gBlockClips[3].x = 0;
        gBlockClips[3].y = 0;
        gBlockClips[3].w = 0;
        gBlockClips[3].h = 0;

        gBlockClips[4].x = 0;
        gBlockClips[4].y = 0;
        gBlockClips[4].w = 0;
        gBlockClips[4].h = 0;

        gBlockClips[5].x = 0;
        gBlockClips[5].y = 0;
        gBlockClips[5].w = 0;
        gBlockClips[5].h = 0;

        gBlockClips[6].x = 0;
        gBlockClips[6].y = 0;
        gBlockClips[6].w = 0;
        gBlockClips[6].h = 0;
    }

    return success;
}

void close() {

    SDL_DestroyRenderer(gRenderer);
    gRenderer = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    IMG_Quit();
    SDL_Quit();
}