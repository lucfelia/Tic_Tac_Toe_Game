#pragma once
#include "board.h"
#include "defines.h"
#include "gameplay.h"

int saveFile(char board[TABLE_LENGHT][TABLE_LENGHT], std::string namefile);

int readFile(char board[TABLE_LENGHT][TABLE_LENGHT], std::string namefile);