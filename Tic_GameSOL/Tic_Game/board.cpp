#include "defines.h"

char board[SIZE_COLUMN][SIZE_ROW];

void createBoard() {
    for (int i = 0; i < SIZE_COLUMN; i++) {
        for (int j = 0; j < SIZE_ROW; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    std::cout << "  -------------" << std::endl;
    for (int i = 0; i < SIZE_ROW; i++) {
        std::cout << " ";
        for (int j = 0; j < 7; j++) {
            std::cout << board[i][j];
            if ((j % 2) == 0) {
                std::cout << " | ";
            }
            else { std::cout << " "; }
        }
        std::cout << std::endl;
        if (i < SIZE_ROW - 1) {
            std::cout << "  -------------\n";
        }
    }
    std::cout << "  -------------" << std::endl;
}