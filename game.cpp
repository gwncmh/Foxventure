#include "game.h"
using namespace std;

FoxGame::FoxGame(Graphics& graphics) : graphics(graphics), quit(false){
        background = graphics.loadTexture("pics/forestbg.png");
        menu = graphics.loadTexture("pics/menu.png");
        helpbg = graphics.loadTexture("pics/helpbg.png");
        settingsbg = graphics.loadTexture("pics/setting.png");
        foxwalk = graphics.loadTexture("pics/fox_walk.png");
        foxattack = graphics.loadTexture("pics/fox_attack.png");
        foxhit = graphics.loadTexture("pics/fox_hit.png");
        foxdeath = graphics.loadTexture("pics/fox_death.png");
        foxjump = graphics.loadTexture("pics/fox_attack.png");
        fwalk.init(foxwalk, WALK_FRAMES, WALK_CLIPS);
        fattack.init(foxattack, ATTACK_FRAMES, ATTACK_CLIPS);
        fhit.init(foxhit, HIT_FRAMES, HIT_CLIPS);
        fdeath.init(foxdeath, DEAD_FRAMES, DEAD_CLIPS);
        fjump.init(foxjump, JUMP_FRAMES, JUMP_CLIPS);
        sback.setTexture(graphics.loadTexture("pics/grasspf1.png"));
        sback.scrollingOffset = SCRW;
        sback1.setTexture(graphics.loadTexture("pics/grasspf2.png"));
        sback1.scrollingOffset = 0;
        sback2.setTexture(graphics.loadTexture("pics/grasspf3.png"));
        sback2.scrollingOffset = -SCRW;
}
FoxGame::~FoxGame() {
    SDL_DestroyTexture( menu );
    menu = nullptr;
    SDL_DestroyTexture( background );
    background = nullptr;
    SDL_DestroyTexture( foxwalk );
    foxwalk = nullptr;
    SDL_DestroyTexture( foxhit );
    foxhit = nullptr;
    SDL_DestroyTexture( foxattack );
    foxattack = nullptr;
    SDL_DestroyTexture( foxdeath );
    foxdeath = nullptr;
    SDL_DestroyTexture( foxjump );
    foxjump = nullptr;
    SDL_DestroyTexture( sback.texture );
    SDL_DestroyTexture( sback1.texture );
    SDL_DestroyTexture( sback2.texture );
    SDL_DestroyTexture(helpbg);
    SDL_DestroyTexture(settingsbg);
}
void FoxGame::showHelp() {
    graphics.prepareScene(helpbg);
    graphics.presentScene();
}
void FoxGame::showSettings() {
    graphics.prepareScene(settingsbg);
    graphics.presentScene();
}
void FoxGame::returnToMenu(Graphics& graphics, SDL_Rect& playrect, SDL_Rect& helprect, SDL_Rect& setrect) {
    cerr << "Returning to menu!" << endl;
    graphics.prepareScene(menu);
    SDL_RenderFillRect(graphics.renderer, &playrect);
    SDL_RenderFillRect(graphics.renderer, &helprect);
    SDL_RenderFillRect(graphics.renderer, &setrect);
    SDL_RenderPresent(graphics.renderer);
}
void FoxGame::run() {
    SDL_Event e;
    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT )  quit = true;
        }
        graphics.prepareScene(background);
        sback.scroll(GROUNDSPEED);
        sback1.scroll(GROUNDSPEED);
        sback2.scroll(GROUNDSPEED);
        graphics.render(sback);
        graphics.render(sback1);
        graphics.render(sback2);
        fwalk.tick();
        fattack.tick();
        fhit.tick();
        fdeath.tick();
        fjump.tick();
        graphics.renders(GROUNDFX+100, GROUNDFY, fattack);
        graphics.renders(GROUNDFX, GROUNDFY, fwalk);
        graphics.renders(GROUNDFX+50, GROUNDFY, fhit);
        graphics.renders(GROUNDFX-50, GROUNDFY, fdeath);
        graphics.renders(GROUNDFX, GROUNDFY-135, fjump);
        graphics.presentScene();
        SDL_Delay(135);
    }
};

