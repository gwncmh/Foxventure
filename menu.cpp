#include "menu.h"
#include "game.h"

Menu::Menu(Graphics& graphics, Game* game)
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
    graphics.prepareScene(menu);
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
            x = event.button.x;
            y = event.button.y;
            if (!settingsStarted && x >= PLAY_X-63 && x <= PLAY_X-3 &&
                y >= PLAY_Y+98 && y <= PLAY_Y+158) {
                SDL_Event helpEvent;
                helpEvent.type = SDL_USEREVENT;
                helpEvent.user.code = 1; // Mã định danh cho sự kiện help
                SDL_PushEvent(&helpEvent);
            }

            if (x >= PLAY_X+17 && x <= PLAY_X+117 &&
                y >= PLAY_Y+17 && y <= PLAY_Y+113) {
                SDL_Event playEvent;
                playEvent.type = SDL_USEREVENT;
                playEvent.user.code = 2; // Mã định danh cho sự kiện play
                SDL_PushEvent(&playEvent);
            }

            if (!helpStarted && x >= PLAY_X+135 && x <= PLAY_X+195 &&
                y >= PLAY_Y+98 && y <= PLAY_Y+158) {
                SDL_Event settingsEvent;
                settingsEvent.type = SDL_USEREVENT;
                settingsEvent.user.code = 3; // Mã định danh cho sự kiện settings
                SDL_PushEvent(&settingsEvent);
            }
            break;
    }
}

void Menu::showHelp() {
    graphics.prepareScene(helpbg);
}
void Menu::showSettings() {
    graphics.prepareScene(settingsbg);
}
void Menu::returnToMenu(Graphics& graphics) {
    cerr << "Returning to menu!" << endl;
    graphics.prepareScene(menu);
    graphics.presentScene();
}
void Menu::userevents(SDL_Event& event) {
    if (event.user.code == 1) {
        helpStarted = true;
        cerr << "Help enabled!" << endl;
    } else if (event.user.code == 2) {
        gameStarted = true;
        cerr << "Game started!" << endl;
    } else if (event.user.code == 3) {
        settingsStarted = true;
        cerr << "Settings enabled!" << endl;
    }
        }
void Menu::rendermenu(SDL_Event& event) {
   SDL_GetMouseState(&x, &y);

    if (helpStarted) {
        showHelp();
        if (event.type == SDL_MOUSEBUTTONDOWN && x >= 0 && x <= 70 && y >= 0 && y <= 70) {
                returnToMenu(graphics);
                helpStarted = false;
            }
        graphics.presentScene();
    }
    if (settingsStarted) {
        showSettings();
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            if (x >= 0 && x <= 70 && y >= 0 && y <= 70) {
                returnToMenu(graphics);
                settingsStarted = false;
                return;
            }
            if (x >= SOUND_X && x <= SOUND_X+110 && y >= SOUND_Y && y <= SOUND_Y+110) {
                soundisoff = !soundisoff;
            }
            if (x >= MUSIC_X && x <= MUSIC_X+110 && y >= MUSIC_Y && y <= MUSIC_Y+110) {
                musicisoff = !musicisoff;
            }
        }
            if (soundisoff) {
                graphics.renderTexture(soundoff, SOUND_X, SOUND_Y);
                Mix_Pause(-1);
            } else {
                graphics.renderTexture(soundon, SOUND_X, SOUND_Y);
                Mix_Resume(-1);
            }
            if (musicisoff) {
                graphics.renderTexture(musicoff, MUSIC_X, MUSIC_Y);
                Mix_PauseMusic();
            } else {
                graphics.renderTexture(musicon, MUSIC_X, MUSIC_Y);
                Mix_ResumeMusic();
            }

        graphics.presentScene();
    }

    if (gameStarted) {
        game->run(); // Use -> instead of .
    }
}
void Menu::setGame(Game* game) {
    this->game = game;
}


