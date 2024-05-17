#include "game.h"

Game::Game(Graphics& graphics, Fox& fox, Menu& menu, Enemy& enemy, Enemy& enemy1, Enemy& enemy2) : graphics(graphics), fox(fox), menu(menu), enemy(enemy),
enemy1(enemy1), enemy2(enemy2), topfive(5,0)
{
    background = graphics.loadTexture("pics/forestbg.png");
    gpause = graphics.loadTexture("pics/pause.png");
    gcontinue = graphics.loadTexture("pics/continue.png");
    grestart = graphics.loadTexture("pics/restart.png");
    musicoff = graphics.loadTexture("pics/sound_off.png");
    musicon = graphics.loadTexture("pics/sound.png");
    ghome = graphics.loadTexture("pics/menubtn.png");
    quit = false;
    gameover = false;
    gamepaused=false;
    musicisoff=false;
    sback.setTexture(graphics.loadTexture("pics/grasspf1.png"));
    sback.scrollingOffset = SCRW;
    sback1.setTexture(graphics.loadTexture("pics/grasspf2.png"));
    sback1.scrollingOffset = 0;
    sback2.setTexture(graphics.loadTexture("pics/grasspf3.png"));
    sback2.scrollingOffset = -SCRW;
    glose = graphics.loadSound("sounds/lost.wav");
    score=0;
    HighScore();
    lose=graphics.loadFont("ZeroCool.ttf", 150);
    scoret=graphics.loadFont("PeaberryBase.ttf", 30);
    timebetween=0;
    color = {255, 255, 0, 0};
    SDL_Color color1 = {212, 238, 68, 0};
    losetext = graphics.renderText("YOU LOSE", lose, color);
    losetext1 = graphics.renderText("YOU LOSE", lose, color1);

}

Game::~Game() {
    SDL_DestroyTexture( background );
    background = nullptr;
    SDL_DestroyTexture( gpause );
    gpause = nullptr;
    SDL_DestroyTexture( gcontinue );
    gcontinue = nullptr;
    SDL_DestroyTexture( grestart );
    grestart = nullptr;
    SDL_DestroyTexture( ghome );
    ghome = nullptr;
    SDL_DestroyTexture( sback.texture );
    SDL_DestroyTexture( sback1.texture );
    SDL_DestroyTexture( sback2.texture );
    SDL_DestroyTexture( losetext );
    losetext = NULL;
    SDL_DestroyTexture( losetext1 );
    losetext1 = NULL;
    SDL_DestroyTexture(highScoreTexture);
    SDL_DestroyTexture(scoreTexture);
    SDL_DestroyTexture(musicoff);
    musicoff = nullptr;
    SDL_DestroyTexture(musicon);
    musicon = nullptr;
}

void Game::run() {
    SDL_Event e;
    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT )  quit = true;
            if( e.type == SDL_KEYDOWN ) {
                switch(e.key.keysym.sym) {
                    case SDLK_UP:
                        if(fox.onGround()) {
                            fox.jump();
                        }
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
                if (x >= 70 && x <= 140 && y >= 0 && y <= 70) {
                    musicisoff=!musicisoff;
                }
        }     if (gamepaused) {
                    graphics.renderTexture(gcontinue, 0, 0);
                    if (musicisoff) {
                        graphics.renderTexture(musicoff, MUSIC_X, MUSIC_Y);
                        Mix_PauseMusic();
                        }
                        else {
                        graphics.renderTexture(musicon, MUSIC_X, MUSIC_Y);
                        Mix_ResumeMusic();
                    }
                    graphics.presentScene();
                }
                else {
                        graphics.renderTexture(gpause, 0, 0);
                    }
    }
        if(!gamepaused){
            update();
            render();
        }
    }
    }

void Game::update() {
    timebetween++;
    SDL_Rect foxBox = fox.boundary();
    cerr << "Fox boundary: (" << foxBox.x << ", " << foxBox.x + foxBox.w << ", " << foxBox.y  + foxBox.h << ")\n";
    SDL_Rect enemyBox = enemy.eboundary();
    cerr << "Enemy boundary: (" << enemyBox.x << ", " << enemyBox.x + enemyBox.w << ", " << enemyBox.y + enemyBox.h << ")\n";
    SDL_Rect enemyBox1 = enemy1.eboundary();
    cerr << "Enemy boundary: (" << enemyBox1.x << ", " << enemyBox1.x + enemyBox1.w << ", " << enemyBox1.y + enemyBox1.h << ")\n";
    SDL_Rect enemyBox2 = enemy2.eboundary();
    cerr << "Enemy boundary: (" << enemyBox2.x << ", " << enemyBox2.x + enemyBox2.w << ", " << enemyBox2.y+ enemyBox2.h << ")\n";
    SDL_Rect obsBox = enemy.oboundary();
    cerr << "Obs boundary: (" << obsBox.x << ", " << obsBox.x + obsBox.w << ", " << obsBox.y + obsBox.h << ")\n";
    SDL_Rect obsBox1 = enemy1.oboundary();
    cerr << "Obs boundary: (" << obsBox1.x << ", " << obsBox1.x + obsBox1.w << ", " << obsBox1.y + obsBox1.h << ")\n";
    SDL_Rect obsBox2 = enemy2.oboundary();
    cerr << "Obs boundary: (" << obsBox2.x << ", " << obsBox2.x + obsBox2.w << ", " << obsBox2.y + obsBox2.h << ")\n";
    if(fox.currentSprite!=&fox.fattack) {foxBox.w=30;} else foxBox.w=55;
    if (enemy.obsposX<=-30) {enemy.obsposX = SCRW+113+rand()%150;}
    if (enemy1.obsposX<=-30) {enemy1.obsposX = SCRW+271+rand()%150;}
    if (enemy2.obsposX<=-30) {enemy2.obsposX = SCRW+460+rand()%150;}
    if (enemy.isOffScreen()&&(
        (obsBox1.x+obsBox1.w>=enemyBox.x&&obsBox1.x+obsBox1.w<=enemyBox.x+enemyBox.w)||
        (obsBox2.x+obsBox2.w>=enemyBox.x&&obsBox2.x+obsBox2.w<=enemyBox.x+enemyBox.w))) {
        enemy.enemyposX +=100+rand()%150;
    }
    if (enemy1.isOffScreen()&&(
        (obsBox.x+obsBox.w>=enemyBox1.x&&obsBox.x+obsBox.w<=enemyBox1.x+enemyBox1.w)||
        (obsBox2.x+obsBox2.w>=enemyBox1.x&&obsBox2.x+obsBox2.w<=enemyBox1.x+enemyBox1.w))) {
        enemy1.enemyposX +=200+rand()%150;
    }
    if (enemy2.isOffScreen()&&(
        (obsBox1.x+obsBox1.w>=enemyBox2.x&&obsBox1.x+obsBox1.w<=enemyBox2.x+enemyBox2.w)||
        (obsBox.x+obsBox.w>=enemyBox2.x&&obsBox.x+obsBox.w<=enemyBox2.x+enemyBox2.w))) {
        enemy2.enemyposX +=300+rand()%150;
    }
    fox.update();
    if(enemy.obsposX==enemy1.obsposX&&enemy1.obsposX==enemy2.obsposX&&enemy.obsposX>SCRW) {enemy1.obsposX+=450;enemy2.obsposX+=850;}
    enemy.update();
    enemy1.update();
    enemy2.update();
    sback.scroll(enemy.speed);
    sback1.scroll(enemy.speed);
    sback2.scroll(enemy.speed);
    if (SDL_HasIntersection(&foxBox, &enemyBox)) {
    if (fox.currentSprite == &fox.fattack && enemy.currentSprite != &enemy.edeath) {
        enemy.currentSprite = &enemy.edeath;
        graphics.presentScene();
        score += 5;
        enemy.enemyposX = SCRW+150+rand()%100;
    } else if (fox.currentSprite != &fox.fattack) {
        fox.currentSprite = &fox.fdeath;
        quit = true;
        gameover = true;
        }
    }
     if (SDL_HasIntersection(&foxBox, &enemyBox1)) {
    if (fox.currentSprite == &fox.fattack && enemy1.currentSprite != &enemy1.edeath) {
        enemy1.currentSprite = &enemy1.edeath;
        graphics.presentScene();
        score += 5;
        enemy1.enemyposX = SCRW+450+rand()%200;
    } else if (fox.currentSprite != &fox.fattack) {
        fox.currentSprite = &fox.fdeath;
        quit = true;
        gameover = true;
        }
    }
     if (SDL_HasIntersection(&foxBox, &enemyBox2)) {
    if (fox.currentSprite == &fox.fattack && enemy2.currentSprite != &enemy2.edeath) {
        enemy2.currentSprite = &enemy2.edeath;
        graphics.presentScene();
        score += 5;
        enemy2.enemyposX = SCRW+700+rand()%100;
    } else if (fox.currentSprite != &fox.fattack) {
        fox.currentSprite = &fox.fdeath;
        quit = true;
        gameover = true;
        }
    }
    if (SDL_HasIntersection(&foxBox, &obsBox)) {
        fox.currentSprite = &fox.fdeath;
        quit = true;
        gameover = true;
    }
    if ((enemy.speed%2==0&&enemy.obsposX==70)||(enemy.speed%2!=0&&enemy.obsposX==71)) {score += 2;}
    if (SDL_HasIntersection(&foxBox, &obsBox1)) {
        fox.currentSprite = &fox.fdeath;
        quit = true;
        gameover = true;
    }
    if ((enemy1.speed%2==0&&enemy1.obsposX==70)||(enemy1.speed%2!=0&&enemy1.obsposX==71)) {score += 2;}
     if (SDL_HasIntersection(&foxBox, &obsBox2)) {
        fox.currentSprite = &fox.fdeath;
        quit = true;
        gameover = true;
    }
    if ((enemy2.speed%2==0&&enemy2.obsposX==70)||(enemy2.speed%2!=0&&enemy2.obsposX==71)) {score += 2;}
    scoreText="Score: "+to_string(score);
    scoreTexture=graphics.renderText(scoreText.c_str(), scoret, color);
    if(timebetween>=2000&&score>40) {
        enemy.speed+=1;
        enemy1.speed+=1;
        enemy2.speed+=1;
        fox.JUMP_SPEED += 1;
        fox.FALL_SPEED +=1;
        timebetween=0;
    }
}
void Game::reset() {
    quit = false;
    gameover = false;
    gamepaused = false;
    timebetween = 0;
    score = 0;
    fox.reset();
    enemy.reset();
    enemy1.reset();
    enemy2.reset();
    sback.scrollingOffset = SCRW;
    sback1.scrollingOffset = 0;
    sback2.scrollingOffset = -SCRW;
    Mix_RewindMusic();
    if(!musicisoff){Mix_ResumeMusic();}
}


void Game::render() {
    graphics.prepareScene(background);
    graphics.render(sback);
    graphics.render(sback1);
    graphics.render(sback2);
    if (musicisoff) {
                    graphics.renderTexture(musicoff, MUSIC_X, MUSIC_Y);
                    Mix_PauseMusic();
                }
                else {
                        graphics.renderTexture(musicon, MUSIC_X, MUSIC_Y);
                        Mix_ResumeMusic();
                    }
    enemy.render(graphics);
    enemy1.render(graphics);
    enemy2.render(graphics);
    fox.render(graphics);
    renderScore();
    graphics.presentScene();
}

void Game::renderOver() {
    static bool soundPlayed = false;
    graphics.renderTexture(losetext1, 119, 32);
    graphics.renderTexture(losetext, 114, 31);
    graphics.renderTexture(grestart, SCRW/2-102, 210);
    graphics.renderTexture(ghome, SCRW/2+2, 210);
    if (!soundPlayed) {
        graphics.play2(glose);
        soundPlayed = true;
    }
    updateHighScore();
    renderScore();
    graphics.presentScene();
}


void Game::overEvent() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            if (x >= SCRW/2-102 && x <= SCRW/2-2 && y >= 210 && y <= 310) {
                reset();
            }
            if (x >= SCRW/2+2 && x <= SCRW/2+102 && y >= 210 && y <= 310) {
                menu.gameStarted=false;
                menu.returnToMenu(graphics);
                reset();
            }
        }
    }
}
void Game::updateHighScore() {
 if (score > topfive[4]&&score < topfive[3]) {
        topfive[4] = score;
    } else if (score > topfive[3]&&score < topfive[2]) {
        topfive[4] = topfive[3];
        topfive[3] = score;
    } else if (score > topfive[2]&&score < topfive[1]) {
        topfive[4] = topfive[3];
        topfive[3] = topfive[2];
        topfive[2] = score;
    } else if (score > topfive[1]&&score < topfive[0]) {
        topfive[4] = topfive[3];
        topfive[3] = topfive[2];
        topfive[2] = topfive[1];
        topfive[1] = score;
    } else if (score > topfive[0]) {
        topfive[4] = topfive[3];
        topfive[3] = topfive[2];
        topfive[2] = topfive[1];
        topfive[1] = topfive[0];
        topfive[0] = score;
    }
    fstream file("highscore.txt");
    for (int a : topfive) {
        file<<a<<endl;
    }
    file.close();
    highScore = topfive.front();
    highScoreText = "High Score: " + to_string(highScore);
    highScoreTexture = graphics.renderText(highScoreText.c_str(), scoret, color);
}

void Game::HighScore() {
    fstream file("highscore.txt");
    for(int i=0; i<5; i++) {
        file>>topfive[i];
    }
    file.close();
}

void Game::renderScore() {
    graphics.renderTexture(scoreTexture, 0, 450);
    graphics.renderTexture(highScoreTexture, 0, 490);
}


/*if (x >= SOUND_X && x <= SOUND_X+110 && y >= SOUND_Y && y <= SOUND_Y+110) {
                soundisoff = !soundisoff;
            }
            if (x >= MUSIC_X && x <= MUSIC_X+110 && y >= MUSIC_Y && y <= MUSIC_Y+110) {
                musicisoff = !musicisoff;
            }
        }
            if (soundisoff) {
                graphics.renderTexture(soundoff, SOUND_X, SOUND_Y);
            } else {
                graphics.renderTexture(soundon, SOUND_X, SOUND_Y);
            }
            if (musicisoff) {
                graphics.renderTexture(musicoff, MUSIC_X, MUSIC_Y);
                Mix_PauseMusic();
            } else {
                graphics.renderTexture(musicon, MUSIC_X, MUSIC_Y);
                Mix_ResumeMusic();
            }
graphics.prepareScene(background);
        graphics.renders(GROUNDFX+100, FOXPOSY, fattack);
        graphics.renders(GROUNDFX, FOXPOSY, fwalk);
        graphics.renders(GROUNDFX+50, FOXPOSY, fhit);
        graphics.renders(GROUNDFX-50, FOXPOSY, fdeath);
        graphics.renders(GROUNDFX, FOXPOSY-135, fjump);
*/
