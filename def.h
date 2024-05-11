#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED
const int SCRW = 900;
const int SCRH = 531;

const int MIX_CHANNEL = -1;
const int OBSTACLE_CLIPS[][4] = {
    {0,0,52,27}};
const int OBSTACLE_FRAMES = sizeof(OBSTACLE_CLIPS)/sizeof(int)/4;
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
const int EDEAD_CLIPS[][4] = {
    {   0, 0, 72, 72},
    {  72, 0, 72, 72},
    { 144, 0, 72, 72},
    { 216, 0, 72, 72}};
const int EDEAD_FRAMES = sizeof(EDEAD_CLIPS)/sizeof(int)/4;
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
const int EATTACK_CLIPS[][4] = {
    {  0, 0, 72, 72},
    { 72, 0, 72, 72},
    {144, 0, 72, 72},
    {216, 0, 72, 72},
    {288, 0, 72, 72},
    {360, 0, 72, 72}};
const int EATTACK_FRAMES = sizeof(EATTACK_CLIPS)/sizeof(int)/4;

const int PLAY_X = SCRW/2-68;
const int PLAY_Y = SCRH/2-50;
const int BACK_X = 0;
const int BACK_Y = 0;
const int BACK_W = 70;
const int BACK_H = 70;
const int SOUND_X = 291;
const int SOUND_Y = 259;
const int SOUND_W = 110;
const int SOUND_H = 110;
const int MUSIC_X = 291;
const int MUSIC_Y = 117;
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
const int MAX_TIME = 100;
const int MAX_DELAY = 800;
const int MIN_DELAY = 300;
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
