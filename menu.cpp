#include "menu.h"

Menu::Menu(Graphics& graphics, FoxGame& game)
    : graphics(graphics), game(game),
      gameStarted(false), helpStarted(false), settingsStarted(false),
      soundisoff(false), musicisoff(false) {
    menu = graphics.loadTexture("pics/menu.png");
    helpbg = graphics.loadTexture("pics/helpbg.png");
    settingsbg = graphics.loadTexture("pics/setting.png");
    soundoff = graphics.loadTexture("pics/music_off.png");
    musicoff = graphics.loadTexture("pics/sound_off.png");
    soundon = graphics.loadTexture("pics/music.png");
    musicon = graphics.loadTexture("pics/sound.png");
    playrect = {PLAY_X+17, PLAY_Y+13, 100, 100};
    helprect = {PLAY_X-63, PLAY_Y+98, 60, 60};
    setrect = {PLAY_X+135, PLAY_Y+98, 60, 60};
    graphics.prepareScene(menu);
    graphics.presentScene();
    SDL_SetRenderDrawBlendMode(graphics.renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(graphics.renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(graphics.renderer, &playrect);
    SDL_RenderFillRect(graphics.renderer, &helprect);
    SDL_RenderFillRect(graphics.renderer, &setrect);
    graphics.presentScene();
}
Menu:: ~Menu() {
    SDL_DestroyTexture( menu );
    menu = nullptr;
    SDL_DestroyTexture(helpbg);
    helpbg = nullptr;
    SDL_DestroyTexture(settingsbg);
    settingsbg = nullptr;
    SDL_DestroyTexture(soundoff);
    soundoff = nullptr;
    SDL_DestroyTexture(musicoff);
    musicoff = nullptr;
    SDL_DestroyTexture(soundon);
    soundon = nullptr;
    SDL_DestroyTexture(musicon);
    musicon = nullptr;
}

void Menu::menuevents(SDL_Event& event) {
    SDL_GetMouseState(&x, &y);
    switch (event.type) {
        case SDL_QUIT:
            exit(0);
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (x >= helprect.x && x <= helprect.x + helprect.w &&
                    y >= helprect.y && y <= helprect.y + helprect.h) {
                    helpStarted = true;
                    cerr << "Help enabled!" << endl;
                }
                if (x >= playrect.x && x <= playrect.x + playrect.w &&
                    y >= playrect.y && y <= playrect.y + playrect.h) {
                    gameStarted = true;
                    cerr << "Game started!" << endl;
                }
                if (x >= setrect.x && x <= setrect.x + setrect.w &&
                    y >= setrect.y && y <= setrect.y + setrect.h) {
                    settingsStarted = true;
                    cerr << "Settings enabled!" << endl;
                }
                break;
    }
}
void Menu::showHelp() {
    graphics.prepareScene(helpbg);
    graphics.presentScene();
}
void Menu::showSettings() {
    graphics.prepareScene(settingsbg);
    graphics.presentScene();
}
void Menu::returnToMenu(Graphics& graphics, SDL_Rect& playrect, SDL_Rect& helprect, SDL_Rect& setrect) {
    cerr << "Returning to menu!" << endl;
    graphics.prepareScene(menu);
    SDL_RenderFillRect(graphics.renderer, &playrect);
    SDL_RenderFillRect(graphics.renderer, &helprect);
    SDL_RenderFillRect(graphics.renderer, &setrect);
    graphics.presentScene();
}
void Menu::rendermenu() {
    if (helpStarted) {
        showHelp();
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
             if (ev.type == SDL_MOUSEBUTTONDOWN) {
                if (x >= 0 && x <= 70 && y >= 0 && y <= 70) {
                    returnToMenu(graphics, playrect, helprect, setrect);
                    helpStarted = false;
                }
            }
        }
        graphics.presentScene();
    }
    if (settingsStarted) {
        showSettings();
        SDL_Event eve;
        while (SDL_PollEvent(&eve)) {
            if (eve.type == SDL_MOUSEBUTTONDOWN) {
                if (x >= 0 && x <= 70 && y >= 0 && y <= 70) {
                    returnToMenu(graphics, playrect, helprect, setrect);
                    settingsStarted = false;
                }
            if (x >= 200 && x <= 300 && y >= 200 && y <= 300) {
                soundisoff = !soundisoff;
            }
            if (x >= 100 && x <= 200 && y >= 100 && y <= 200) {
                musicisoff = !musicisoff;
            }
        }
    }
    if (soundisoff) {
        graphics.renderTexture(soundoff, 150, 150);
        cerr<<"soff"<<endl;
    } else {
        graphics.renderTexture(soundon, 150, 150);
        cerr<<"son"<<endl;
    }
    if (musicisoff) {
        graphics.renderTexture(musicoff, 250, 150);
        cerr<<"moff"<<endl;
    } else {
        graphics.renderTexture(musicon, 250, 150);
        cerr<<"mon"<<endl;
    }
    graphics.presentScene();
    }
    if (gameStarted) {
        game.run();
    }
}
