#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <raylib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <iostream>

#define GAME_X 240
#define GAME_Y 100
#define GAME_WIDTH 800
#define GAME_HEIGHT 600

#define SELECT_HEIGHT 32
#define SELECT_COLOR_BOX GREEN
#define SELECT_COLOR_TEXT BLACK
#define STANDR_COLOR_BOX BLACK
#define STANDR_COLOR_TEXT GREEN
#define TEXT_SIZE 30
#define MAX_GAMES 7
#define GAME_REC { GAME_X, GAME_Y, GAME_WIDTH, GAME_HEIGHT }
#define deepgray CLITERAL(Color){ 20, 20, 20, 20 }

void launchGame(char* const*);

#endif
