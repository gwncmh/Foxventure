#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <cstdlib>
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
    Enemy enemy(graphics);
    Enemy enemy1(graphics);
    Enemy enemy2(graphics);
    Menu menu(graphics, nullptr);
    Game game(graphics, fox, menu, enemy, enemy1, enemy2);
    menu.setGame(&game);
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
                case SDL_MOUSEMOTION:
                    menu.menuevents(event);
            }
            if (!menu.gameStarted) {
            menu.rendermenu(event);
            } else {
            game.run();
            while (game.gameover) {
            Mix_PauseMusic();
            game.renderOver();
            game.overEvent();
        }
        }
        }
    }
    graphics.flushEventQueue();
    graphics.quit();
    return 0;
}


