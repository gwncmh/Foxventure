#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "def.h"
#include "graphics.h"
#include "game.h"
#include "menu.h"
using namespace std;
void flushEventQueue() {
    SDL_Event e;
    SDL_PumpEvents();
    while (SDL_PeepEvents(&e, 1, SDL_GETEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT) > 0) {}
}
void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();
    FoxGame game(graphics);
    Menu menu(graphics, game);
    SDL_Event event;

    while (true) {
        while (SDL_PollEvent(&event)) {
            menu.handleEvents(event);
        }
        menu.render();
        SDL_Delay(10);
    }
    flushEventQueue();
    graphics.quit();
    return 0;
}



