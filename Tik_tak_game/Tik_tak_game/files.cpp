#include "board.h"
#include "defines.h"
#include "gameplay.h"

// Funci�n para guardar la partida:
int saveFile(char board[TABLE_LENGHT][TABLE_LENGHT]) {

	// 1. Abrimos / creamos el archivo "save.txt":
	std::ofstream savedGame;
	savedGame.open("save.txt", std::ios::out);

	// 2. Lo llenamos de car�cteres vac�os (' '):
	savedGame << EMPTY;
	savedGame.close();

	// 3. Ahora, recorremos la array "board" y la reescribimos en el archivo "save.txt":
	savedGame.open("save.txt", std::ios::out | std::ios::app);
	for (int i = 0; i < TABLE_LENGHT; i++) {
		for (int j = 0; j < TABLE_LENGHT; j++) {

			// Si la celda del tablero est� vac�a (' '), 
            // guardamos un car�cter ('.') en su lugar en el archivo
			if (board[i][j] == EMPTY) {
				savedGame << DOT;
			}
			//Si la celda contiene otra cosa (X o O, por ejemplo), la guardamos tal cual.
			else {
				savedGame << board[i][j];
			}
		}
	}

	// Cerramos el archivo.
	savedGame.close();
	return 0;
}

// Funci�n para cargar la partida:
int readFile(char board[TABLE_LENGHT][TABLE_LENGHT]) {

	// 1. Abrimos el archivo "save.txt":
	std::ifstream savedGame;
	savedGame.open("save.txt");

	// 2. Declaramos una variable para almacenar temporalmente cada car�cter del archivo:
	char value;

	// 3. Recorremos la array de "board":
	for (int i = 0; i < TABLE_LENGHT; i++) {
		for (int j = 0; j < TABLE_LENGHT; j++) {

			// Se lee 1 car�cter del archivo y se almacena en la variable "value".
			savedGame >> value;
			
			//Si el valor le�do es un '.',
			//lo convertimos de nuevo en ' ' en el tablero.
			if (value == DOT) {
				board[i][j] = EMPTY;
			}
			// Si el valor le�do es otro (por ejemplo, 'X' o 'O'),
			// lo copiamos directamente.
			else {
				board[i][j] = value;
			}
		}
	}

	// Cerramos el archivo.
	savedGame.close();
	return 0;
}