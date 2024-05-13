#include "enemy.h"

using namespace std;

Enemy::Enemy(Graphics& graphics) : graphics(graphics) {
    enemyattack = graphics.loadTexture("pics/Centipede_attack3.png");
    enemydeath = graphics.loadTexture("pics/Centipede_death.png");
    eattack.init(enemyattack, EATTACK_FRAMES, EATTACK_CLIPS);
    edeath.init(enemydeath, EDEAD_FRAMES, EDEAD_CLIPS);
    enemyposX=SCRW;
    currentSprite = &eattack;
}

Enemy::~Enemy() {
    SDL_DestroyTexture(enemyattack);
    enemyattack = nullptr;
    SDL_DestroyTexture(enemydeath);
    enemydeath = nullptr;
}

void Enemy::update() {
    enemyposX -= 5;
    if (currentSprite == &edeath && edeath.isLastFrame()) {
        enemyposX = SCRW;
        currentSprite = &eattack;
    }
}
void Enemy::reset() {
    enemyposX=SCRW;
    currentSprite = &eattack;
}

void Enemy::render(Graphics& graphics) {
    currentSprite->tick();
    graphics.renders(enemyposX, GROUNDFY+20, *currentSprite);
}

SDL_Rect Enemy::eboundary() const {
    return {enemyposX, GROUNDFY+25, 60, 60};
}

bool Enemy::isOffScreen() {
    return (enemyposX + 60 < 0 || enemyposX > SCRW);
}

