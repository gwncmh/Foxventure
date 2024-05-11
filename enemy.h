#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "graphics.h"
#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
using namespace std;
enum class EnemyType {
    Centipede,
    Obstacle
};
class Enemy {
public:
    Enemy(Graphics& graphics, EnemyType& type);
    ~Enemy();
    void update();
    void render(Graphics& graphics);
    int enemyposX;
    int obsposX;
    SDL_Rect eboundary() const;
    SDL_Rect oboundary() const;
    Sprite edeath,eattack,obs;
    EnemyType type;
private:
    Graphics& graphics;
    SDL_Texture* enemyattack;
    SDL_Texture* enemydeath;
    SDL_Texture* obstacles;

};

#endif // ENEMY_H_INCLUDED
