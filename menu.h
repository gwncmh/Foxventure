#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "graphics.h"
using namespace std;
class Game;
class Menu {
public:
    Menu(Graphics& graphics, Game* game);
    ~Menu();
    void menuevents(SDL_Event& event);
    void rendermenu(SDL_Event& event);
    void userevents(SDL_Event& event);
    void showHelp();
    void showhighscores();
    void returnToMenu(Graphics& graphics);
    void setGame(Game* game);
    bool gameStarted;
private:
    Graphics& graphics;
    Game* game;
    TTF_Font* scoret;
    SDL_Texture* menu;
    SDL_Texture* gclose;
    SDL_Texture* helpbg;
    SDL_Texture* highscoresbg;
    SDL_Texture* HSTexture;
    SDL_Texture* playb;
    SDL_Texture* helpb;
    SDL_Texture* hsb;
    SDL_Texture* prevb;
    SDL_Color color;
    int x, y;
    string HSText;
    bool helpStarted;
    bool highscoresStarted;
};


#endif // MENU_H_INCLUDED
