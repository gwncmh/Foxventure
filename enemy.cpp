#include "enemy.h"

using namespace std;

Enemy::Enemy(Graphics& graphics) : graphics(graphics) {
    enemyattack = graphics.loadTexture("pics/Centipede_attack3.png");
    enemydeath = graphics.loadTexture("pics/Centipede_death.png");
    tileset = graphics.loadTexture("pics/tileset.png");
    eattack.init(enemyattack, EATTACK_FRAMES, EATTACK_CLIPS);
    edeath.init(enemydeath, EDEAD_FRAMES, EDEAD_CLIPS);
    obs.init(tileset, OBSTACLE_FRAMES, OBSTACLE_CLIPS);
    enemyposX=SCRW+450;
    obsposX=SCRW+10;
    currentSprite = &eattack;
    state=ATTACKING;
}

Enemy::~Enemy() {
    SDL_DestroyTexture(enemyattack);
    enemyattack = nullptr;
    SDL_DestroyTexture(enemydeath);
    enemydeath = nullptr;
    SDL_DestroyTexture(tileset);
    tileset = nullptr;
}

void Enemy::update() {
        if (state == ATTACKING) {
            enemyposX -= 2;
            if (currentSprite == &edeath && edeath.isLastFrame()) {
                currentSprite = &eattack;
            }
            if (isOffScreen()) {
                state = OBSTACLE;
            }
        } else if (state == OBSTACLE) {
            obsposX -= 2;
            if (obsposX<-30) {
                state = ATTACKING;
            }
        }
    }

void Enemy::reset() {
    enemyposX=SCRW+450;
    obsposX=SCRW+10;
    currentSprite = &eattack;
}

void Enemy::render(Graphics& graphics) {
        if (state == ATTACKING) {
            currentSprite->tick();
            graphics.renders(enemyposX, GROUNDFY+19, *currentSprite);
        } else if (state == OBSTACLE) {
            obs.tick();
            graphics.renders(obsposX, GROUNDFY+34, obs);
        }
    }

SDL_Rect Enemy::eboundary() const {
    return {enemyposX+2, GROUNDFY+39, 43, 30};
}
SDL_Rect Enemy::oboundary() const {
    return {obsposX+2, GROUNDFY+59, 38, 20};
}

bool Enemy::isOffScreen() {
    return (enemyposX + 43 < 0 || enemyposX > SCRW);
}

