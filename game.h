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
    SDL_Texture* gclose;
    SDL_Texture* homeb;
    SDL_Texture* closeb;
    SDL_Texture* restartb;
    SDL_Texture* highScoreTexture;
    SDL_Texture* scoreTexture;
    SDL_Texture* musicoff;
    SDL_Texture* musicon;
    SDL_Texture* ghome;
    Graphics& graphics;
    Fox& fox;
    Menu& menu;
    Enemy& enemy;
    Enemy& enemy1;
    Enemy& enemy2;
    SDL_Color color;
    int timebetween = 0;
    bool quit;
    int frames,frames1,frames2;
    string highScoreText, scoreText;
    Mix_Chunk* glose;
public:
    Game(Graphics& graphics, Fox& fox, Menu& menu, Enemy& enemy, Enemy& enemy1, Enemy& enemy2);
    ~Game();
    void run();
    void handleEvents();
    void update();
    void render();
    bool checkCollision(Fox fox, Enemy enemy);
    bool isPaused = false;
    int score;
    int highScore;
    vector<int> topfive;
    void reset();
    bool gameover, gamepaused;
    void renderOver();
    void overEvent();
    void updateHighScore();
    void renderScore();
    void HighScore();
    bool musicisoff;
};

#endif // GAME_H_INCLUDED
