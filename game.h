#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "fox.h"
using namespace std;

class Game {
private:
    ScrollingBackground sback,sback1,sback2;
    SDL_Texture* background;
    SDL_Texture* menu;
    Graphics& graphics;
    Fox& fox;
    bool quit;

public:
    Game(Graphics& graphics, Fox& fox);
    ~Game();
    void run();
    void handleEvents();
    void update();
    void render();
};

#endif // GAME_H_INCLUDED

