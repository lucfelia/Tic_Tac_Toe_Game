#include "defines.h"

// Función para crear un tablero vacío:
void createBoard(char board[TABLE_LENGHT][TABLE_LENGHT]) {
	for (int i = 0; i < TABLE_LENGHT; i++) {
		for (int j = 0; j < TABLE_LENGHT; j++) {
			board[i][j] = EMPTY;
		}
	}
}

// Función para imprimir el tablero con los bordes necesarios:
void printBoard(char board[TABLE_LENGHT][TABLE_LENGHT]) {

	std::cout << TITLE << std::endl << std::endl;
	std::cout << BORDER << std::endl;

	for (int i = 0; i < TABLE_LENGHT; i++) {
		std::cout << EMPTY;
		short counter = 0;
		for (int j = 0; j < BOARD_CHARACTERS; j++) {

			if ((j % 2) == 0) {
				std::cout << WALL;
			}
			else {
				std::cout << board[i][counter];
				counter++;
			}
		}
		std::cout << std::endl;
		if (i < TABLE_LENGHT - 1) {
			std::cout << BORDER << std::endl;
		}
	}

	std::cout << BORDER << std::endl;
}