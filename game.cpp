#include "game.h"

Game::Game(Graphics& graphics, Fox& fox, Menu& menu, Enemy& enemy) : graphics(graphics), fox(fox), menu(menu), enemy(enemy) {
    background = graphics.loadTexture("pics/forestbg.png");
    gpause = graphics.loadTexture("pics/pause.png");
    gcontinue = graphics.loadTexture("pics/continue.png");
    grestart = graphics.loadTexture("pics/restart.png");
    quit = false;
    gameover = false;
    gamepaused=false;
    sback.setTexture(graphics.loadTexture("pics/grasspf1.png"));
    sback.scrollingOffset = SCRW;
    sback1.setTexture(graphics.loadTexture("pics/grasspf2.png"));
    sback1.scrollingOffset = 0;
    sback2.setTexture(graphics.loadTexture("pics/grasspf3.png"));
    sback2.scrollingOffset = -SCRW;
    score=0;
    HighScore();
    lose=graphics.loadFont("ZeroCool.ttf", 150);
    scoret=graphics.loadFont("PeaberryBase.ttf", 30);
    timebetween=0;
    color = {255, 255, 0, 0};
    SDL_Color color1 = {212, 238, 68, 0};
    losetext = graphics.renderText("YOU LOSE", lose, color);
    losetext1 = graphics.renderText("YOU LOSE", lose, color1);
    MAX_TIME=450;
}

Game::~Game() {
    SDL_DestroyTexture( background );
    SDL_DestroyTexture( gpause );
    SDL_DestroyTexture( gcontinue );
    SDL_DestroyTexture( grestart );
    SDL_DestroyTexture( sback.texture );
    SDL_DestroyTexture( sback1.texture );
    SDL_DestroyTexture( sback2.texture );
    SDL_DestroyTexture( losetext );
    losetext = NULL;
    SDL_DestroyTexture( losetext1 );
    losetext1 = NULL;
    SDL_DestroyTexture(highScoreTexture);
    SDL_DestroyTexture(scoreTexture);
}

void Game::run() {
    SDL_Event e;
    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT )  quit = true;
            if( e.type == SDL_KEYDOWN ) {
                switch(e.key.keysym.sym) {
                    case SDLK_UP:
                        fox.jump();
                        break;
                    case SDLK_SPACE:
                        fox.attack();
                        break;
                    default:
                        break;
                }
            }
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= 0 && x <= 70 && y >= 0 && y <= 70) {
                    gamepaused=!gamepaused;
                }
                if (gamepaused) {
                    graphics.renderTexture(gcontinue, 0, 0);
                    Mix_PauseMusic();
                } else {
                    if(menu.musicisoff) {
                        graphics.renderTexture(gpause, 0, 0);
                    } else {
                        graphics.renderTexture(gpause, 0, 0);
                        Mix_ResumeMusic();
                    }
                }
                }
            graphics.presentScene();
        }
        if(!gamepaused){
            update();
            render();
        }
    }
    }

void Game::update() {
    fox.update();
    enemy.update();
    sback.scroll(GROUNDSPEED);
    sback1.scroll(GROUNDSPEED);
    sback2.scroll(GROUNDSPEED);
    timebetween++;
    if (timebetween >= MAX_TIME) {
        timebetween = 0;
        enemy.enemyposX = SCRW;
        int random = rand() % 451;
        MAX_TIME = 450 + random;
    }
    SDL_Rect foxBox = fox.boundary();
    SDL_Rect enemyBox = enemy.eboundary();
    if (SDL_HasIntersection(&foxBox, &enemyBox)) {
    if (fox.currentSprite == &fox.fattack && enemy.currentSprite != &enemy.edeath) {
        enemy.currentSprite = &enemy.edeath;
        score += 5;
    } else if (fox.currentSprite != &fox.fattack) {
        fox.currentSprite = &fox.fdeath;
        quit = true;
        gameover = true;
        }
    }
    scoreText="Score: "+to_string(score);
    scoreTexture=graphics.renderText(scoreText.c_str(), scoret, color);
    updateHighScore();
}
void Game::reset() {
    quit = false;
    gameover = false;
    gamepaused = false;
    timebetween = 0;
    score = 0;
    MAX_TIME = 450;
    fox.reset();
    enemy.reset();
    sback.scrollingOffset = SCRW;
    sback1.scrollingOffset = 0;
    sback2.scrollingOffset = -SCRW;
    menu.gameStarted=true;
}


void Game::render() {
    graphics.prepareScene(background);
    graphics.render(sback);
    graphics.render(sback1);
    graphics.render(sback2);
    enemy.render(graphics);
    fox.render(graphics);
    if (enemy.isOffScreen()) {
        enemy.enemyposX = SCRW;
    }
    renderScore();
    graphics.presentScene();
}

void Game::renderOver() {
    graphics.renderTexture(losetext1, 115, 35);
    graphics.renderTexture(losetext, 110, 30);
    graphics.renderTexture(grestart, SCRW/2-50, 210);
    renderScore();
    graphics.presentScene();
}

void Game::overEvent() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            if (x >= SCRW/2-50 && x <= SCRW/2+50 && y >= 210 && y <= 310) {
                reset();
            }
        }
    }
}
void Game::updateHighScore() {
    if (score > highScore) {
        highScore=score;
    }
    fstream file("highscore.txt");
            file<<highScore;
        file.close();
    highScoreText="High Score: "+to_string(highScore);
    highScoreTexture=graphics.renderText(highScoreText.c_str(), scoret, color);
}
void Game::HighScore() {
    fstream file("highscore.txt");
            file>>highScore;
        file.close();
}

void Game::renderScore() {
    graphics.renderTexture(scoreTexture, 0, 400);
    graphics.renderTexture(highScoreTexture, 0, 450);
}


/*graphics.prepareScene(background);
        graphics.renders(GROUNDFX+100, FOXPOSY, fattack);
        graphics.renders(GROUNDFX, FOXPOSY, fwalk);
        graphics.renders(GROUNDFX+50, FOXPOSY, fhit);
        graphics.renders(GROUNDFX-50, FOXPOSY, fdeath);
        graphics.renders(GROUNDFX, FOXPOSY-135, fjump);
*/
