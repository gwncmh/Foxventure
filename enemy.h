#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "graphics.h"
#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <cstdlib>
using namespace std;

class Enemy {
public:
    Enemy(Graphics& graphics);
    ~Enemy();
    void update();
    void render(Graphics& graphics);
    int enemyposX, obsposX;
    SDL_Rect eboundary() const;
    SDL_Rect oboundary() const;
    Sprite edeath,eattack,obs;
    Sprite* currentSprite;
    bool isOffScreen();
    void reset();
private:
    Graphics& graphics;
    SDL_Texture* enemyattack;
    SDL_Texture* enemydeath;
    SDL_Texture* tileset;
    enum State { ATTACKING, OBSTACLE };
    State state;
};

#endif // ENEMY_H_INCLUDED

