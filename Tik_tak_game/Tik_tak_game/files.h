#pragma once
#include "board.h"
#include "defines.h"
#include "gameplay.h"

int saveFile(char board[TABLE_LENGHT][TABLE_LENGHT]);

int readFile(char board[TABLE_LENGHT][TABLE_LENGHT]);