#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "graphics.h"
using namespace std;
class Enemy {
public:
    Enemy(Graphics& graphics);
    ~Enemy();
    void update();
    void render(Graphics& graphics);
    void shoot();

private:
    Graphics& graphics;
    Sprite ewalk, eattack, edeath;
    SDL_Texture* enemywalk;
    SDL_Texture* enemyattack;
    SDL_Texture* enemydeath;
    SDL_Texture* bullet;
    Sprite ebullet;
    vector<SDL_Rect> bullets;
};

#endif // ENEMY_H_INCLUDED
