#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED
const int SCRW = 900;
const int SCRH = 531;
const int MIX_CHANNEL = -1;
const int OBSTACLE_CLIPS[][4] = {
    {0,0,130,82},
    {130,0,130,82},
    {130*2,0,130,82},
    {130*3,0,130,121},
    {130*4,0,130+4,121},
    {130*5+4,0,130,82},
    {130*6,0,130,82}};
const int OBSTACLE_FRAMES = sizeof(OBSTACLE_CLIPS)/sizeof(int)/4;
const int WALK_CLIPS[][4] = {
    {   0, 0, 160, 64},
    { 160, 0, 160, 64},
    { 320, 0, 160, 64},
    { 480, 0, 160, 64}};
const int WALK_FRAMES = sizeof(WALK_CLIPS)/sizeof(int)/4;
const int HIT_CLIPS[][4] = {
    {   0, 0, 160, 64},
    { 160, 0, 160, 64},
    { 320, 0, 160, 64},
    { 480, 0, 160, 64}};
const int HIT_FRAMES = sizeof(HIT_CLIPS)/sizeof(int)/4;

const int DEAD_CLIPS[][4] = {
    {   0, 0, 160, 64},
    { 160, 0, 160, 64},
    { 320, 0, 160, 64}};
const int DEAD_FRAMES = sizeof(DEAD_CLIPS)/sizeof(int)/4;
const int EDEAD_CLIPS[][4] = {
    {   0, 0, 50, 40},
    {  50, 0, 50, 40}};
const int EDEAD_FRAMES = sizeof(EDEAD_CLIPS)/sizeof(int)/4;
const int ATTACK_CLIPS[][4] = {
    {   0, 0, 160, 66},
    { 160, 0, 160, 66},
    { 320, 0, 160, 66},
    { 480, 0, 160, 66},
    { 640, 0, 160, 66},
    { 800, 0, 160, 66}};
const int ATTACK_FRAMES = sizeof(ATTACK_CLIPS)/sizeof(int)/4;
const int EATTACK_CLIPS[][4] = {
    {  0, 0, 72, 40},
    { 72, 0, 72, 40},
    {144, 0, 72, 40},
    {216, 0, 72, 40},
    {288, 0, 72, 40},
    {360, 0, 72, 40}};
const int EATTACK_FRAMES = sizeof(EATTACK_CLIPS)/sizeof(int)/4;
static bool soundPlayed = false;
const int PLAY_X = SCRW/2-68;
const int PLAY_Y = SCRH/2-50;
const int BACK_X = 0;
const int BACK_Y = 0;
const int BACK_W = 70;
const int BACK_H = 70;
const int MUSIC_X = 70;
const int MUSIC_Y = 0;
const int MUSIC_W = 70;
const int MUSIC_H = 70;
const int SCOREX = 445;
const int SCOREY = 120;
const int SCOREGAP = 55;
const int GROUNDFX = 89;
const int GROUNDFY = 355;
const int MAX_HEIGHT = 200;
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
