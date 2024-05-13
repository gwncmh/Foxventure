#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "fox.h"
#include "enemy.h"
#include "menu.h"
using namespace std;

class Game {
private:
    ScrollingBackground sback,sback1,sback2;
    SDL_Texture* background;
    TTF_Font* lose;
    TTF_Font* scoret;
    SDL_Texture* losetext;
    SDL_Texture* losetext1;
    SDL_Texture* gpause;
    SDL_Texture* gcontinue;
    SDL_Texture* grestart;
    SDL_Texture* highScoreTexture;
    SDL_Texture* scoreTexture;
    Graphics& graphics;
    Fox& fox;
    Menu& menu;
    Enemy& enemy;
    SDL_Color color;
    int timebetween = 0;
    bool quit;
    int MAX_TIME;
    string highScoreText, scoreText;
public:
    Game(Graphics& graphics, Fox& fox, Menu& menu, Enemy& enemy);
    ~Game();
    void run();
    void handleEvents();
    void update();
    void render();
    bool checkCollision(Fox fox, Enemy enemy);
    bool isPaused = false;
    int score;
    int highScore;
    void reset();
    bool gameover, gamepaused;
    void renderOver();
    void overEvent();
    void updateHighScore();
    void renderScore();
    void HighScore();
};

#endif // GAME_H_INCLUDED
