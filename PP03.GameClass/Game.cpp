#include <SDL.h>
#include "Game.h"
#include <iostream>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;

bool Game::init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        g_pWindow = SDL_CreateWindow(title, xpos, ypos,
            width, height, fullscreen);
        if (g_pWindow != 0)
        {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }
    }
    else {
        return false;
    }
    return true;
}

void Game::render()
{
    SDL_RenderClear(g_pRenderer);
    SDL_RenderPresent(g_pRenderer);
}

void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(g_pWindow);
    SDL_DestroyRenderer(g_pRenderer);
    SDL_Quit();
}

void Game::handleEvent()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
                g_bRunning = false;
                break;
        default:
            break;
        }
    }
}