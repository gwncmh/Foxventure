#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <cstdlib>
#include "fox.h"
#include "enemy.h"
using namespace std;

class Game {
private:
    ScrollingBackground sback,sback1,sback2;
    SDL_Texture* background;
    SDL_Texture* menu;
    TTF_Font* lose;
    SDL_Texture* losetext;
    SDL_Texture* losetext1;
    Graphics& graphics;
    Fox& fox;
    vector<Enemy> enemies;  // This vector will hold all your enemies
    int timebetween = 0;
    int timer = 0;
    int maxdelay = 0;
    bool quit;
    bool gameover;
    int score;  // Current score
    int highScore;  // High score
public:
    Game(Graphics& graphics, Fox& fox);  // Removed the 'Enemy& enemy' parameter
    ~Game();
    void run();
    void handleEvents();
    void update();
    void render();
    bool checkCollision(Fox fox, Enemy enemy);
    bool isPaused = false;
};

#endif // GAME_H_INCLUDED
