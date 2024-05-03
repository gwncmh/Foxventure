#include "menu.h"

Menu::Menu(Graphics& graphics, FoxGame& game)
    : graphics(graphics), game(game), sclickcount(0), mclickcount(0),
      gameStarted(false), helpStarted(false), settingsStarted(false),
      soundisoff(false), musicisoff(false) {
    menu = graphics.loadTexture("pics/menu.png");
    soundoff = graphics.loadTexture("pics/music_off.png");
    musicoff = graphics.loadTexture("pics/sound_off.png");
    soundon = graphics.loadTexture("pics/music.png");
    musicon = graphics.loadTexture("pics/sound.png");
    playrect = {PLAY_X+17, PLAY_Y+13, 100, 100};
    helprect = {PLAY_X-63, PLAY_Y+98, 60, 60};
    setrect = {PLAY_X+135, PLAY_Y+98, 60, 60};
    graphics.prepareScene(menu);
    graphics.presentScene();
    drawButtons();
}

void Menu::handleEvents(SDL_Event& event) {
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
void Menu::drawButtons() {
    SDL_SetRenderDrawBlendMode(graphics.renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(graphics.renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(graphics.renderer, &playrect);
    SDL_RenderFillRect(graphics.renderer, &helprect);
    SDL_RenderFillRect(graphics.renderer, &setrect);
    graphics.presentScene();
}
void Menu::rendermenu() {
    if (helpStarted) {
        game.showHelp();
        SDL_Rect prevrect;
        prevrect.x=0;
        prevrect.y=0;
        prevrect.w=70;
        prevrect.h=70;
        SDL_RenderFillRect(graphics.renderer, &prevrect);
        SDL_RenderPresent(graphics.renderer);
        SDL_Event ev;
        SDL_PollEvent(&ev);
             if (ev.type == SDL_MOUSEBUTTONDOWN) {
                if (x >= prevrect.x && x <= prevrect.x + prevrect.w &&
                    y >= prevrect.y && y <= prevrect.y + prevrect.h) {
                    game.returnToMenu(graphics, playrect, helprect, setrect);
                    helpStarted = false;
                }
            }
    }
    if (settingsStarted) {
        game.showSettings();
        SDL_Rect prevrect;
        prevrect.x=0;
        prevrect.y=0;
        prevrect.w=70;
        prevrect.h=70;
        SDL_Rect soundrect;
        soundrect.x=200;
        soundrect.y=200;
        soundrect.w=100;
        soundrect.h=100;
        SDL_Rect musicrect;
        musicrect.x=100;
        musicrect.y=100;
        musicrect.w=100;
        musicrect.h=100;
        SDL_RenderFillRect(graphics.renderer, &prevrect);
        SDL_RenderFillRect(graphics.renderer, &soundrect);
        SDL_RenderFillRect(graphics.renderer, &musicrect);
        SDL_RenderPresent(graphics.renderer);
        SDL_Event eve;
        while (SDL_PollEvent(&eve)) {
            if (eve.type == SDL_MOUSEBUTTONDOWN) {
                if (x >= prevrect.x && x <= prevrect.x + prevrect.w &&
                    y >= prevrect.y && y <= prevrect.y + prevrect.h) {
                    game.returnToMenu(graphics, playrect, helprect, setrect);
                    settingsStarted = false;
                }
            if (x >= soundrect.x && x <= soundrect.x + soundrect.w &&
                y >= soundrect.y && y <= soundrect.y + soundrect.h) {
                sclickcount++;
                soundisoff = sclickcount % 2 != 0 && sclickcount!=0;
            }
            if (x >= musicrect.x && x <= musicrect.x + musicrect.w &&
                y >= musicrect.y && y <= musicrect.y + musicrect.h) {
                mclickcount++;
                musicisoff = mclickcount % 2 != 0 && mclickcount!=0;
            }
        }
    }
    if (soundisoff) {
        graphics.renderTexture(soundoff, 150, 150);
    } else {
        graphics.renderTexture(soundon, 150, 150);
    }
    if (musicisoff) {
        graphics.renderTexture(musicoff, 250, 150);
    } else {
        graphics.renderTexture(musicon, 250, 150);
    }
        graphics.presentScene();
    }
    if (gameStarted) {
        game.run();
    }
}
