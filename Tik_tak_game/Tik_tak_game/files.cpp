#include "board.h"
#include "defines.h"
#include "gameplay.h"

// Función para guardar la partida:
int saveFile(char board[TABLE_LENGHT][TABLE_LENGHT]) {

	// 1. Abrimos / creamos el archivo "save.txt"
	std::ofstream savedGame;
	savedGame.open("save.txt", std::ios::out);
	savedGame << EMPTY;
	savedGame.close();

	savedGame.open("save.txt", std::ios::out | std::ios::app);
	for (int i = 0; i < TABLE_LENGHT; i++) {
		for (int j = 0; j < TABLE_LENGHT; j++) {
			if (board[i][j] == EMPTY) {
				savedGame << DOT;
			}
			else {
				savedGame << board[i][j];
			}
		}
	}
	savedGame.close();
	return 0;
}

// Función para cargar la partida:
int readFile(char board[TABLE_LENGHT][TABLE_LENGHT]) {
	std::ifstream savedGame;
	savedGame.open("save.txt");
	char value;
	for (int i = 0; i < TABLE_LENGHT; i++) {
		for (int j = 0; j < TABLE_LENGHT; j++) {
			savedGame >> value;
			if (value == DOT) {
				board[i][j] = EMPTY;
			}
			else {
				board[i][j] = value;
			}

		}
	}
	savedGame.close();
	return 0;
}