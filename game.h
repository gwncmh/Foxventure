#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "graphics.h"
using namespace std;

class FoxGame {
private:
    Sprite fwalk,fattack,fhit,fdeath,fjump;
    ScrollingBackground sback,sback1,sback2;
    SDL_Texture* background;
    SDL_Texture* foxwalk;
    SDL_Texture* foxattack;
    SDL_Texture* foxhit;
    SDL_Texture* foxdeath;
    SDL_Texture* foxjump;
    SDL_Texture* helpbg;
    SDL_Texture* settingsbg;
    SDL_Texture* menu;
    Graphics& graphics;
    bool quit;

public:
    FoxGame(Graphics& graphics);
    ~FoxGame();
    void showHelp();
    void showSettings();
    void returnToMenu(Graphics& graphics, SDL_Rect& playrect, SDL_Rect& helprect, SDL_Rect& setrect);
    void run();
};

#endif // GAME_H_INCLUDED
