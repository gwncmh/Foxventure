#include "enemy.h"
using namespace std;
Enemy::Enemy(Graphics& graphics) : graphics(graphics) {
    enemywalk = graphics.loadTexture("pics/Big_bloated_walk.png");
    enemyattack = graphics.loadTexture("pics/Big_bloated_attack4.png");
    enemydeath = graphics.loadTexture("pics/Big_bloated_death.png");
    ewalk.init(enemywalk, EWALK_FRAMES, EWALK_CLIPS);
    eattack.init(enemyattack, EATTACK_FRAMES, EATTACK_CLIPS);
    edeath.init(enemydeath, EDEAD_FRAMES, EDEAD_CLIPS);
    bullet = graphics.loadTexture("pics/Bolt.png");
}

Enemy::~Enemy() {
    SDL_DestroyTexture(enemywalk);
    enemywalk = nullptr;
    SDL_DestroyTexture(enemyattack);
    enemyattack = nullptr;
    SDL_DestroyTexture(enemydeath);
    enemydeath = nullptr;
    SDL_DestroyTexture(bullet);
    bullet = nullptr;
}

void Enemy::update() {
    vector<SDL_Rect> bulletsToKeep;
    for (auto& b : bullets) {
        b.x += 5; // adjust bullet speed here
        if (b.x <= SCRW) { // keep bullets that are still on the screen
            bulletsToKeep.push_back(b);
        }
    }
    bullets = bulletsToKeep; // replace old bullets with the ones we kept
}


void Enemy::render(Graphics& graphics) {
    graphics.renders(300,300, ewalk); // adjust enemy position here
    for (const auto& b : bullets) {
        graphics.blitRect(bullet, ebullet.getCurrentClip(), b.x, b.y);
    }
}

void Enemy::shoot() {
    SDL_Rect bul = {100, 100, 10, 10}; // adjust initial bullet position here
    bullets.push_back(bul);
}
