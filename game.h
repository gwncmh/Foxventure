#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
using namespace std;

class FoxGame {
private:
    Sprite fwalk,fattack,fhit,fdeath,fjump;
    ScrollingBackground sback,sback1,sback2;
    SDL_Texture* background;
    SDL_Texture* foxwalk;
    SDL_Texture* foxattack;
    SDL_Texture* foxhit;
    SDL_Texture* foxdeath;
    SDL_Texture* foxjump;
    SDL_Texture* helpbg;
    SDL_Texture* settingsbg;
    SDL_Texture* menu;
    Graphics& graphics;
    bool quit;

public:
    FoxGame(Graphics& graphics):graphics(graphics), quit(false) {
        background = graphics.loadTexture("pics/forestbg.png");
        menu = graphics.loadTexture("pics/menu.png");
        helpbg = graphics.loadTexture("pics/helpbg.png");
        settingsbg = graphics.loadTexture("pics/setting.png");
        foxwalk = graphics.loadTexture(FOX_WALKING);
        foxattack = graphics.loadTexture(FOX_ATTACK);
        foxhit = graphics.loadTexture(FOX_HIT);
        foxdeath = graphics.loadTexture(FOX_DEAD);
        foxjump = graphics.loadTexture(FOX_JUMP);
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

    ~FoxGame() {
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
    void showHelp() {
    graphics.prepareScene(helpbg);
    graphics.presentScene();
    }
    void showSettings() {
    graphics.prepareScene(settingsbg);
    graphics.presentScene();
    }
    void returnToMenu(Graphics& graphics, SDL_Rect& playrect, SDL_Rect& helprect, SDL_Rect& setrect) {
    cerr << "Returning to menu!" << endl;
    graphics.prepareScene(menu);
    SDL_RenderFillRect(graphics.renderer, &playrect);
    SDL_RenderFillRect(graphics.renderer, &helprect);
    SDL_RenderFillRect(graphics.renderer, &setrect);
    SDL_RenderPresent(graphics.renderer);
}
    void run() {
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
    }
};

#endif // GAME_H_INCLUDED
