#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <bits/stdc++.h>
#include "graphics.h"
#include "game.h"

using namespace std;
class Menu {
public:
    Menu(Graphics& graphics, FoxGame& game);
    void handleEvents(SDL_Event& event);
    void render();
    void drawButtons();
private:
    Graphics& graphics;
    FoxGame& game;
    SDL_Texture* menu;
    SDL_Texture* soundoff;
    SDL_Texture* musicoff;
    SDL_Texture* soundon;
    SDL_Texture* musicon;
    SDL_Rect playrect;
    SDL_Rect helprect;
    SDL_Rect setrect;
    int x, y;
    int sclickcount, mclickcount;
    bool gameStarted;
    bool helpStarted;
    bool settingsStarted;
    bool soundisoff;
    bool musicisoff;
};


#endif // MENU_H_INCLUDED
