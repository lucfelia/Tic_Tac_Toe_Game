#pragma once
#include "board.h"
#include "defines.h"
#include "files.h"

void bot(char board[TABLE_LENGHT][TABLE_LENGHT]);

void turns(short& truenumber_1, short& truenumber_2, char& userinput_1, char& userinput_2, char board[TABLE_LENGHT][TABLE_LENGHT], bool turnplayer_1);

bool check(char board[TABLE_LENGHT][TABLE_LENGHT], short truenumber_1, short truenumber_2);

void gameLoop(bool gameover, char board[TABLE_LENGHT][TABLE_LENGHT], char userinput_1, char userinput_2, short truenumber_1, short truenumber_2, bool turnplayer_1);

void newGame(bool gameover, char board[TABLE_LENGHT][TABLE_LENGHT], char userinput_1, char userinput_2, short truenumber_1, short truenumber_2, bool turnplayer_1);

void loadGame(bool gameover, char board[TABLE_LENGHT][TABLE_LENGHT], char userinput_1, char userinput_2, short truenumber_1, short truenumber_2, bool turnplayer_1);

void menu();
