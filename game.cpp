#include "game.h"

Game::Game(Graphics& graphics, Fox& fox) : graphics(graphics), fox(fox){
    background = graphics.loadTexture("pics/forestbg.png");
    quit = false;
    sback.setTexture(graphics.loadTexture("pics/grasspf1.png"));
    sback.scrollingOffset = SCRW;
    sback1.setTexture(graphics.loadTexture("pics/grasspf2.png"));
    sback1.scrollingOffset = 0;
    sback2.setTexture(graphics.loadTexture("pics/grasspf3.png"));
    sback2.scrollingOffset = -SCRW;
}

Game::~Game() {
    SDL_DestroyTexture( background );
    SDL_DestroyTexture( sback.texture );
    SDL_DestroyTexture( sback1.texture );
    SDL_DestroyTexture( sback2.texture );
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
    sback.scroll(GROUNDSPEED);
    sback1.scroll(GROUNDSPEED);
    sback2.scroll(GROUNDSPEED);
}

void Game::render() {
    graphics.prepareScene(background);
    graphics.render(sback);
    graphics.render(sback1);
    graphics.render(sback2);
    fox.render(graphics);
    graphics.presentScene();
}

/*graphics.prepareScene(background);
        graphics.renders(GROUNDFX+100, FOXPOSY, fattack);
        graphics.renders(GROUNDFX, FOXPOSY, fwalk);
        graphics.renders(GROUNDFX+50, FOXPOSY, fhit);
        graphics.renders(GROUNDFX-50, FOXPOSY, fdeath);
        graphics.renders(GROUNDFX, FOXPOSY-135, fjump);
*/
