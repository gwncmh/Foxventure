#include "fox.h"

Fox::Fox(Graphics& graphics): graphics(graphics), isJumping(false), isAttacking(false), quit(false)
{   FOXPOSY=GROUNDFY;
    foxwalk = graphics.loadTexture("pics/fox_walk.png");
    foxattack = graphics.loadTexture("pics/fox_attack.png");
    foxhit = graphics.loadTexture("pics/fox_hit.png");
    foxdeath = graphics.loadTexture("pics/fox_death.png");
    fwalk.init(foxwalk, WALK_FRAMES, WALK_CLIPS);
    fattack.init(foxattack, ATTACK_FRAMES, ATTACK_CLIPS);
    fhit.init(foxhit, HIT_FRAMES, HIT_CLIPS);
    fdeath.init(foxdeath, DEAD_FRAMES, DEAD_CLIPS);
    gJump = graphics.loadSound("sounds/jump.wav");
    gAttack = graphics.loadSound("sounds/attack.wav");
    currentSprite = &fwalk;
    JUMP_SPEED = 3;
    FALL_SPEED = 3;
}

Fox::~Fox()
{
    SDL_DestroyTexture( foxwalk );
    foxwalk = nullptr;
    SDL_DestroyTexture( foxhit );
    foxhit = nullptr;
    SDL_DestroyTexture( foxattack );
    foxattack = nullptr;
    SDL_DestroyTexture( foxdeath );
    foxdeath = nullptr;
}

void Fox::jump()
{
    if (!isJumping)
    {
        graphics.play2(gJump);
        isJumping = true;
    }
}
void Fox::update()
{
        if (isJumping)
        {
            if (FOXPOSY >= MAX_HEIGHT)
            {
                FOXPOSY -= JUMP_SPEED;
            }
            else
            {
                isJumping = false;
            }
        }
        else if (FOXPOSY < GROUNDFY)
        {
            FOXPOSY += FALL_SPEED;
        }
        if (FOXPOSY > GROUNDFY)
        {
            FOXPOSY = GROUNDFY;
        }
    if (isAttacking)
    {
        if (currentSprite == &fattack && fattack.isLastFrame())
        {
            isAttacking = false;
            currentSprite = &fwalk;
        }
    }
}
bool Fox::onGround(){
    return FOXPOSY==GROUNDFY;
}
void Fox::attack()
{
    if (!isAttacking)
    {
        graphics.play2(gAttack);
        currentSprite = &fattack;
        fattack.currentFrame = 0;
        isAttacking = true;
    }
}
void Fox::reset() {
    isJumping = false;
    isAttacking = false;
    currentSprite = &fwalk;
    FOXPOSY = GROUNDFY;
}
void Fox::render(Graphics& graphics)
{   currentSprite->tick();
    graphics.renders(GROUNDFX, FOXPOSY, *currentSprite);
}
SDL_Rect Fox::boundary(){
    return {GROUNDFX+49, FOXPOSY, 30, 54};
}
