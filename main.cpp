#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "def.h"
#include "graphics.h"
#include "game.h"
#include "menu.h"
#include "fox.h"
using namespace std;
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
int main(int argc, char *argv[]){
    Graphics graphics;
    graphics.init();
    Fox fox(graphics);
    Game game(graphics, fox);
    Menu menu(graphics, game);
    SDL_Event event;

    while (true) {
        while (SDL_PollEvent(&event)) {
            menu.menuevents(event);
        }
        menu.rendermenu();
    }
    graphics.flushEventQueue();
    graphics.quit();
    return 0;
}



