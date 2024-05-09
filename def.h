#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED
const int SCRW = 900;
const int SCRH = 531;

const int MIX_CHANNEL = -1;
const int WALK_CLIPS[][4] = {
    {   0, 0, 160, 128},
    { 160, 0, 160, 128},
    { 320, 0, 160, 128},
    { 480, 0, 160, 128}};
const int WALK_FRAMES = sizeof(WALK_CLIPS)/sizeof(int)/4;
const int HIT_CLIPS[][4] = {
    {   0, 0, 160, 128},
    { 160, 0, 160, 128},
    { 320, 0, 160, 128},
    { 480, 0, 160, 128}};
const int HIT_FRAMES = sizeof(HIT_CLIPS)/sizeof(int)/4;

const int DEAD_CLIPS[][4] = {
    {   0, 0, 160, 128},
    { 160, 0, 160, 128},
    { 320, 0, 160, 128}};
const int DEAD_FRAMES = sizeof(DEAD_CLIPS)/sizeof(int)/4;

const int ATTACK_CLIPS[][4] = {
    {   0, 0, 160, 128},
    { 160, 0, 160, 128},
    { 320, 0, 160, 128},
    { 480, 0, 160, 128},
    { 640, 0, 160, 128},
    { 800, 0, 160, 128},
    { 960, 0, 160, 128},
    {1120, 0, 160, 128},
    {1280, 0, 160, 128},
    {1440, 0, 160, 128}};
const int ATTACK_FRAMES = sizeof(ATTACK_CLIPS)/sizeof(int)/4;

const int JUMP_CLIPS[][4] = {
    {   0, 0, 160, 230},
    { 160, 0, 160, 230},
    { 320, 0, 160, 230},
    { 480, 0, 160, 230},
    { 640, 0, 160, 230},
    { 800, 0, 160, 230}};
const int JUMP_FRAMES = sizeof(JUMP_CLIPS)/sizeof(int)/4;

const int PLAY_X = SCRW/2-68;
const int PLAY_Y = SCRH/2-50;
const int BACK_X = 0;
const int BACK_Y = 0;
const int BACK_W = 70;
const int BACK_H = 70;
const int SOUND_X = 100;
const int SOUND_Y = 0;
const int SOUND_W = 110;
const int SOUND_H = 110;
const int MUSIC_X = 197;
const int MUSIC_Y = 80;
const int MUSIC_W = 110;
const int MUSIC_H = 110;
const int PAUSE_X = 31;
const int PAUSE_Y = 29;
const int CONTINUE_X = 31;
const int CONTINUE_Y = 29;

const int GROUNDFX = 100;
const int GROUNDFY = 320;
const int GROUNDSPEED = 1;
const int JUMP_SPEED = 6;
const int MAX_HEIGHT = 200;
const int FALL_SPEED = 8;
/*
const int SCREEN_BPP = 64;
const double SCREEN_SPEED = 4;
const double ENEMY_SPEED = 4 ;

const int MAX_JUMP = 240;

const int JUMP_POW = 18;
const double GRAVITY_FALL = 0.41;
const int MAX_ACCELERATION = 9;

const int RUNNING_FRAMES = 6;
static SDL_Rect fox_frame[RUNNING_FRAMES];

const int FONT_SIZE = 30;

const int RENDER_DRAW_COLOR = 255;

const int PLAY_BUTTON_POSX = 389;
const int PLAY_BUTTON_POSY = 186;
const int HELP_BUTTON_POSX = 389;
const int HELP_BUTTON_POSY = 293;
const int EXIT_BUTTON_POSX = 389;
const int EXIT_BUTTON_POSY = 402;
const int BACK_BUTTON_POSX = 31;
const int BACK_BUTTON_POSY = 29;
const int PAUSE_BUTTON_POSX = 31;
const int PAUSE_BUTTON_POSY = 29;
const int CONTINUE_BUTTON_POSX = 31;
const int CONTINUE_BUTTON_POSY = 29;
*/
#endif // DEF_H_INCLUDED
