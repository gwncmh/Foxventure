#include "enemy.h"
using namespace std;
Enemy::Enemy(Graphics& graphics, EnemyType& type) : graphics(graphics), type(type) {
    if (type == EnemyType::Centipede) {
    enemyattack = graphics.loadTexture("pics/Centipede_attack3.png");
    enemydeath = graphics.loadTexture("pics/Centipede_death.png");
    eattack.init(enemyattack, EATTACK_FRAMES, EATTACK_CLIPS);
    edeath.init(enemydeath, EDEAD_FRAMES, EDEAD_CLIPS);
    enemyposX=SCRW;
    } else if (type == EnemyType::Obstacle) {
    obstacles = graphics.loadTexture("pics/tileset.png");
    obs.init(obstacles, OBSTACLE_FRAMES, OBSTACLE_CLIPS);
    obsposX=SCRW+100;
    }
}

Enemy::~Enemy() {
    SDL_DestroyTexture(enemyattack);
    enemyattack = nullptr;
    SDL_DestroyTexture(enemydeath);
    enemydeath = nullptr;
}
void Enemy::update() {
    if(type == EnemyType::Centipede) {enemyposX -= 1;}
    else if (type == EnemyType::Obstacle) {obsposX -=1;}
}

void Enemy::render(Graphics& graphics) {
    if(type == EnemyType::Centipede) {
    eattack.tick();
    graphics.renders(enemyposX, GROUNDFY+20, eattack);}
    else if (type == EnemyType::Obstacle) {
    obs.tick();
    graphics.renders(obsposX, GROUNDFY+20, obs);}

}
SDL_Rect Enemy::eboundary() const {
    return {enemyposX, GROUNDFY+25, 60, 60};
}
SDL_Rect Enemy::oboundary() const {
    return {obsposX, GROUNDFY+25, 52, 27};
}

