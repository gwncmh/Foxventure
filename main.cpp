#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <ctime>
#include "def.h"
#include "graphics.h"
#include "game.h"
#include "menu.h"
#include "fox.h"
#include "enemy.h"
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
    srand(time(0));
    Graphics graphics;
    graphics.init();
    Fox fox(graphics);
    EnemyType type = EnemyType::Centipede;
    Enemy enemy(graphics, type);
    Game game(graphics, fox);
    Menu menu(graphics, game);
    graphics.playBGM();
    while (true) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                menu.menuevents(event);
                break;
            case SDL_USEREVENT:
                menu.userevents(event);
                break;
        }
        menu.rendermenu(event);
    }
}
    graphics.flushEventQueue();
    graphics.quit();
    return 0;
}



