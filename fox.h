#ifndef FOX_H_INCLUDED
#define FOX_H_INCLUDED

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "graphics.h"
using namespace std;

class Fox {
public:
    Fox(Graphics& graphics);
    ~Fox();
    void jump();
    void attack();
    void update();
    void render(Graphics& graphics);
    SDL_Rect boundary();
    Sprite* currentSprite;
    Sprite fdeath;
    int FOXPOSY;
private:
    SDL_Texture* foxwalk;
    SDL_Texture* foxattack;
    SDL_Texture* foxhit;
    SDL_Texture* foxdeath;
    Mix_Chunk* gJump;
    Mix_Chunk* gAttack;
    Sprite fwalk,fattack,fhit;
    Graphics& graphics;
    bool isJumping;
    bool isAttacking;
    bool quit;
};

#endif // FOX_H_INCLUDED
