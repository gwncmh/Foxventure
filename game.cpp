#include "game.h"

Game::Game(Graphics& graphics, Fox& fox) : graphics(graphics), fox(fox) {
    background = graphics.loadTexture("pics/forestbg.png");
    quit = false;
    gameover = false;
    sback.setTexture(graphics.loadTexture("pics/grasspf1.png"));
    sback.scrollingOffset = SCRW;
    sback1.setTexture(graphics.loadTexture("pics/grasspf2.png"));
    sback1.scrollingOffset = 0;
    sback2.setTexture(graphics.loadTexture("pics/grasspf3.png"));
    sback2.scrollingOffset = -SCRW;
    lose=graphics.loadFont("ZeroCool.ttf", 150);
    timebetween=0;
    SDL_Color color = {255, 255, 0, 0};
    SDL_Color color1 = {212, 238, 68, 0};
    losetext = graphics.renderText("YOU LOSE", lose, color);
    losetext1 = graphics.renderText("YOU LOSE", lose, color1);
}
Game::~Game() {
    SDL_DestroyTexture( background );
    SDL_DestroyTexture( sback.texture );
    SDL_DestroyTexture( sback1.texture );
    SDL_DestroyTexture( sback2.texture );
    SDL_DestroyTexture( losetext );
    losetext = NULL;
    SDL_DestroyTexture( losetext1 );
    losetext1 = NULL;
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
        }
        update();
        render();
    }
}

void Game::update() {
    fox.update();
    for (Enemy& enemy : enemies) {
        enemy.update();
    }
    sback.scroll(GROUNDSPEED);
    sback1.scroll(GROUNDSPEED);
    sback2.scroll(GROUNDSPEED);
     if (timebetween >= MAX_TIME) {
        timebetween = 0;
        EnemyType type = (rand() % 2 == 0) ? EnemyType::Centipede : EnemyType::Obstacle;
        enemies.push_back(Enemy(graphics, type));
        // Set positions for new enemies based on type
        if (type == EnemyType::Centipede) {
            enemies.back().enemyposX = SCRW;
            enemies.back().obsposX = 0; // Reset obstacle position
        } else {
            enemies.back().enemyposX = 0; // Reset centipede position
            enemies.back().obsposX = SCRW;
        }
    }
    SDL_Rect foxBox = fox.boundary();
    for (Enemy& enemy : enemies) {
        SDL_Rect enemyBox = enemy.eboundary();
        SDL_Rect obsBox = enemy.oboundary();

        if (SDL_HasIntersection(&foxBox, &enemyBox) || SDL_HasIntersection(&foxBox, &obsBox)) {
            fox.currentSprite = &fox.fdeath;
            quit = true;
            gameover = true;
            break;
        }
    }
}

void Game::render() {
    graphics.prepareScene(background);
    graphics.render(sback);
    graphics.render(sback1);
    graphics.render(sback2);
    fox.render(graphics);
    for (Enemy& enemy : enemies) {
        enemy.render(graphics);
    }
    if(gameover){
    graphics.renderTexture(losetext1, 115, 55);
    graphics.renderTexture(losetext, 110, 50);
    }
    graphics.presentScene();
}

/*graphics.prepareScene(background);
        graphics.renders(GROUNDFX+100, FOXPOSY, fattack);
        graphics.renders(GROUNDFX, FOXPOSY, fwalk);
        graphics.renders(GROUNDFX+50, FOXPOSY, fhit);
        graphics.renders(GROUNDFX-50, FOXPOSY, fdeath);
        graphics.renders(GROUNDFX, FOXPOSY-135, fjump);
*/
