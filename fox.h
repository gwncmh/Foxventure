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
    void update(); // Update the fox's state
    void render(Graphics& graphics); // Render the fox on the screen

private:
    SDL_Texture* foxwalk;
    SDL_Texture* foxattack;
    SDL_Texture* foxhit;
    SDL_Texture* foxdeath;
    Mix_Chunk* gJump;
    Mix_Chunk* gAttack;
    Sprite fwalk,fattack,fhit,fdeath;
    Sprite* currentSprite;
    Graphics& graphics;
    int FOXPOSY;
    bool isJumping;
    bool isAttacking;
    bool quit;
};

#endif // FOX_H_INCLUDED
