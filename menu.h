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
    void showSettings();
    void returnToMenu(Graphics& graphics);
    void setGame(Game* game);
    bool gameStarted;
    bool musicisoff;
private:
    Graphics& graphics;
    Game* game;
    SDL_Texture* menu;
    SDL_Texture* soundoff;
    SDL_Texture* musicoff;
    SDL_Texture* soundon;
    SDL_Texture* musicon;
    SDL_Texture* helpbg;
    SDL_Texture* settingsbg;
    int x, y;
    bool helpStarted;
    bool settingsStarted;
    bool soundisoff;
};


#endif // MENU_H_INCLUDED
