#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "game.h"
using namespace std;
class Menu {
public:
    Menu(Graphics& graphics, FoxGame& game);
    ~Menu();
    void menuevents(SDL_Event& event);
    void rendermenu();
    void showHelp();
    void showSettings();
    void returnToMenu(Graphics& graphics, SDL_Rect& playrect, SDL_Rect& helprect, SDL_Rect& setrect);
private:
    Graphics& graphics;
    FoxGame& game;
    SDL_Texture* menu;
    SDL_Texture* soundoff;
    SDL_Texture* musicoff;
    SDL_Texture* soundon;
    SDL_Texture* musicon;
    SDL_Texture* helpbg;
    SDL_Texture* settingsbg;
    SDL_Rect playrect;
    SDL_Rect helprect;
    SDL_Rect setrect;
    SDL_Rect prevrect;
    SDL_Rect soundrect;
    SDL_Rect musicrect;
    int x, y;
    bool gameStarted;
    bool helpStarted;
    bool settingsStarted;
    bool soundisoff;
    bool musicisoff;
};


#endif // MENU_H_INCLUDED
