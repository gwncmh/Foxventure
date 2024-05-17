#include "menu.h"
#include "game.h"

Menu::Menu(Graphics& graphics, Game* game)
    : graphics(graphics), game(game),
      gameStarted(false), helpStarted(false), highscoresStarted(false) {
    menu = graphics.loadTexture("pics/menu.png");
    helpbg = graphics.loadTexture("pics/helpbg.png");
    highscoresbg = graphics.loadTexture("pics/highscoresbg.png");
    playb = graphics.loadTexture("pics/playbig.png");
    helpb = graphics.loadTexture("pics/helpbig.png");
    hsb = graphics.loadTexture("pics/prizebig.png");
    prevb = graphics.loadTexture("pics/prewbig.png");
    graphics.prepareScene(menu);
    graphics.presentScene();
    scoret=graphics.loadFont("fonts/PeaberryBase.ttf", 50);
    color = {255, 255, 0, 0};
}
Menu:: ~Menu() {
    SDL_DestroyTexture( menu );
    menu = nullptr;
    SDL_DestroyTexture(helpbg);
    helpbg = nullptr;
    SDL_DestroyTexture(highscoresbg);
    highscoresbg = nullptr;
    SDL_DestroyTexture(playb);
    playb = nullptr;
    SDL_DestroyTexture(helpb);
    helpb = nullptr;
    SDL_DestroyTexture(hsb);
    hsb = nullptr;
    SDL_DestroyTexture(HSTexture);
    HSTexture = NULL;
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
            if (!highscoresStarted && x >= PLAY_X-63 && x <= PLAY_X-3 &&
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
                SDL_Event highscoresEvent;
                highscoresEvent.type = SDL_USEREVENT;
                highscoresEvent.user.code = 3; // Mã định danh cho sự kiện highscores
                SDL_PushEvent(&highscoresEvent);
            }
            break;
            case SDL_MOUSEMOTION:
            x = event.motion.x;
            y = event.motion.y;
            if (helpStarted==false&&gameStarted==false&&highscoresStarted==false
            && x >= 316 && x <= 381 && y >= 308 && y <= 372) {
            graphics.renderTexture(helpb, 313, 305);
            graphics.presentScene();
            } else if (helpStarted==false&&gameStarted==false&&highscoresStarted==false
            && x >= 386 && x <= 504 && y >= 213 && y <= 331) {
            graphics.renderTexture(playb, 385, 214);
            graphics.presentScene();
            } else if (helpStarted==false&&gameStarted==false&&highscoresStarted==false
            && x >= 518 && x <= 580 && y >= 308 && y <= 372) {
            graphics.renderTexture(hsb, 510, 305);
            graphics.presentScene();
            } else if (helpStarted==false&&gameStarted==false&&highscoresStarted==false) {
            graphics.renderTexture(menu,0,0);
            graphics.presentScene();
    }
    break;
    }
}

void Menu::showHelp() {
    graphics.prepareScene(helpbg);
}
void Menu::showhighscores() {
    graphics.prepareScene(highscoresbg);
    for (int i = 0; i < game->topfive.size(); i++) {
    HSText = to_string(game->topfive[i]);
    HSTexture = graphics.renderText(HSText.c_str(), scoret, color);
    if(game->topfive[i]<10) {
    graphics.renderTexture(HSTexture, SCOREX, SCOREY + i*SCOREGAP);
    } else if(game->topfive[i]<100) {
    graphics.renderTexture(HSTexture, SCOREX-10, SCOREY + i*SCOREGAP);
    } else if (game->topfive[i]<1000) {
    graphics.renderTexture(HSTexture, SCOREX-25, SCOREY + i*SCOREGAP);
    }
    }
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
        highscoresStarted = true;
        cerr << "Highscores enabled!" << endl;
    }
        }
void Menu::rendermenu(SDL_Event& event) {
   SDL_GetMouseState(&x, &y);

    if (helpStarted) {
        showHelp();
        if (event.type == SDL_MOUSEMOTION && x >= 0 && x <= 70 && y >= 0 && y <= 70) {
            graphics.renderTexture(prevb,0,0);
            graphics.presentScene();
        }
        if (event.type == SDL_MOUSEBUTTONDOWN && x >= 0 && x <= 70 && y >= 0 && y <= 70) {
                returnToMenu(graphics);
                helpStarted = false;
                return;
            }
        graphics.presentScene();
    }
    if (highscoresStarted) {
        showhighscores();
        if (event.type == SDL_MOUSEMOTION && x >= 0 && x <= 70 && y >= 0 && y <= 70) {
            graphics.renderTexture(prevb,0,0);
            graphics.presentScene();
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            if (x >= 0 && x <= 70 && y >= 0 && y <= 70) {
                returnToMenu(graphics);
                highscoresStarted = false;
                return;
            }
    }
    graphics.presentScene();
    }
    if (gameStarted) {
        game->run();
    }
}
void Menu::setGame(Game* game) {
    this->game = game;
}


