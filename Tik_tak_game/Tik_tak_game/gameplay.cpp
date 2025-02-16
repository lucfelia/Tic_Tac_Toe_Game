#include "board.h"
#include "defines.h"
#include "files.h"

// Función para colocar las piezas de forma random:
void bot(char board[TABLE_LENGHT][TABLE_LENGHT]) {

	// 1. Generamos dos números aleatorios entre 0 y 2 (para un tablero de 3x3).
	int num1 = rand() % TABLE_LENGHT;
	int num2 = rand() % TABLE_LENGHT;

	// 2. Verificamos si la casilla seleccionada ya está ocupada.
	while (board[num1][num2] != EMPTY) {
		num1 = rand() % TABLE_LENGHT;
		num2 = rand() % TABLE_LENGHT;
	}
	// 3. Una vez encontrada una casilla vacía, la marcamos con 'O'.
	board[num1][num2] = CRICLE;
}

// Función que gestiona los turnos:
void turns(short& truenumber_1, short& truenumber_2, char& userinput_1, char& userinput_2, char board[TABLE_LENGHT][TABLE_LENGHT], bool turnplayer_1) {

	bool tourn = true;
	while (tourn) {

		// Si es el turno del jugador 1 (humano):
		if (turnplayer_1) {
			std::cout << std::endl << "PLAYER 1 TURN! 'X'" << std::endl;
			// Pedir la fila en la que quiere jugar:
			std::cout << std::endl << "Press (Q) to Save & Quit." << std::endl << std::endl << "In what position do you want to add the numbers (Row): " << std::endl;
			std::cin >> userinput_1;

			// Opción de salir y guardar la partida:
			if (userinput_1 == QUIT_L || userinput_1 == QUIT) {
				tourn = false;
			}
			else {
				// Validamos que la fila esté entre 1 y 3:
				if (userinput_1 < LOWER_OPTION || userinput_1> HIGHEST_OPTION) {
					system("cls");
					printBoard(board);
					std::cout << std::endl << "Invalid character error!" << std::endl;
				}
				else {	// Pedir la columna en la que quiere jugar:
					std::cout << std::endl << "In what position do you want to add the numbers (Column): " << std::endl;
					std::cin >> userinput_2;
					// Opción de salir y guardar la partida:
					if (userinput_1 == QUIT_L || userinput_1 == QUIT) {
						tourn = false;
					}
					else {
						// Validamos que la columna esté entre 1 y 3:
						if (userinput_2 < LOWER_OPTION || userinput_2> HIGHEST_OPTION) {
							system("cls");
							printBoard(board);
							std::cout << std::endl << "Invalid character error!" << std::endl;
						}
						else {
							// Convertimos las entradas de char a índice de array (restando '1'):
							truenumber_1 = ((short)userinput_1 + CHAR_TRANSFOMATION);
							truenumber_2 = ((short)userinput_2 + CHAR_TRANSFOMATION);
						}
						// Comprobamos si la casilla está ocupada:
						if (board[truenumber_1][truenumber_2] != EMPTY) {
							system("cls");
							printBoard(board);
							std::cout << std::endl << "Position alredy ocupied!" << std::endl;

						}
						// Si la posición está libre, asignamos la jugada correspondiente:
						else if (turnplayer_1 && tourn) {
							board[truenumber_1][truenumber_2] = CROSS;
							tourn = false;

						}
					}
				}
			}
			
		}
		// Si es el turno del jugador 2 (la IA):
		else {
			std::cout << std::endl << "PLAYER 2 TURN! 'O'" << std::endl;
			bot(board); // La IA hace su jugada automáticamente.
			tourn = false;
			system("pause");
		}
	}
}

// Función para comprobar si se ha conseguido tres fichas en raya:
bool check(char board[TABLE_LENGHT][TABLE_LENGHT], short truenumber_1, short truenumber_2) {
	
	// Se verifican las filas:
	for (int i = 0; i < TABLE_LENGHT; i++) {
		if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			return true;
		}
		// Y las columnas:
		if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			return true;
		}
	}
	// Se comprueba la primera diagonal:
	if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		return true;
	}
	// Y la segunda:
	if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		return true;
	}
	return false;
}

// Bucle principal del juego:
void gameLoop(bool gameover, char board[TABLE_LENGHT][TABLE_LENGHT], char userinput_1, char userinput_2, short truenumber_1, short truenumber_2, bool turnplayer_1, std::string namefile) {
	std::string filetype = FILE_EXTENSION;
	int number;
	while (!gameover) {

		// Mostramos tablero:
		printBoard(board);
		// Ejecutamos el turno actual:
		turns(truenumber_1, truenumber_2, userinput_1, userinput_2, board, turnplayer_1);
		turnplayer_1 = !turnplayer_1;
		// Comprobamos si se ha acabado el turno:
		gameover = check(board, truenumber_1, truenumber_2);

		// Si el jugador quiere salir y guardar la partida:
		if (userinput_1 == QUIT_L || userinput_1 == QUIT || userinput_2 == QUIT_L || userinput_2 == QUIT) {
			
			std::cout << std::endl;
			std::cout << "Choose a name to save the file: ";
			std::cin >> namefile;
			
			namefile += filetype;
			number=saveFile(board,namefile);
			
			if (number == 0) {
				gameover = true;
			}
			else {
				turnplayer_1 = !turnplayer_1;
			}
		}

		// Cuando se acaba el juego, mostramos el jugador:
		if (gameover && check(board, truenumber_1, truenumber_2)) {
			
			if (!turnplayer_1) {
				std::cout << std::endl << "PLAYER 1 WINS!" << std::endl;
			}
			else {
				std::cout << std::endl << "PLAYER 2 WINS!" << std::endl;
			}
			system("pause");
			system("cls");
			printBoard(board);
		}
		system("cls");
	}

}

// Función para jugar una nueva partida:
void newGame(bool gameover, char board[TABLE_LENGHT][TABLE_LENGHT], char userinput_1, char userinput_2, short truenumber_1, short truenumber_2, bool turnplayer_1, std::string namefile) {
	
	// 1. Reiniciamos el estado del juego
	// y generamos un tablero:
	gameover = false;
	turnplayer_1 = true;
	createBoard(board);

	// 2. Bucle principal del juego:
	gameLoop(gameover, board, userinput_1, userinput_2, truenumber_1, truenumber_2, turnplayer_1,namefile);
}

// Función para jugar una partida guardada:
void loadGame(bool gameover, char board[TABLE_LENGHT][TABLE_LENGHT], char userinput_1, char userinput_2, short truenumber_1, short truenumber_2, bool turnplayer_1, std::string namefile) {

	// 1. Reiniciamos el bucle del juego y
	// cargamos el tablero guardado:
	gameover = false;
	readFile(board,namefile);

	// 2. Bucle principal del juego:
	gameLoop(gameover, board, userinput_1, userinput_2, truenumber_1, truenumber_2, turnplayer_1,namefile);
}

// Menú con todas las opciones:
void menu(){
	char board[TABLE_LENGHT][TABLE_LENGHT];
	char userinput_1 = '0';
	char userinput_2 = '0';
	short truenumber_1 = 0;
	short truenumber_2 = 0;
	bool gameover = false;
	bool turnplayer_1 = true;
	bool menu = true;
	char option = ' ';
	std::string namefile;
	std::string filetype = FILE_EXTENSION;

	srand(time(NULL));

	createBoard(board);

	while (menu) {

		std::cout << "CHOOSE AN OPTION!" << std::endl;
		std::cout << "1.PLAY NEW GAME" << std::endl;
		std::cout << "2.LOAD GAME" << std::endl;
		std::cout << "3.QUIT" << std::endl;
		std::cin >> option;

		system("cls");
		if (option == LOWER_OPTION) {
			newGame(gameover, board, userinput_1, userinput_2, truenumber_1, truenumber_2, turnplayer_1,namefile);
		}
		else  if (option == MIDDLE_OPTION) {
			std::cout << "Chose a name for the saved file." << std::endl;
			std::cin >> namefile;
			namefile += filetype;
			loadGame(gameover, board, userinput_1, userinput_2, truenumber_1, truenumber_2, turnplayer_1,namefile);
		}
		else if (option == HIGHEST_OPTION) {
			std::cout << std::endl << "BYE! <3" << std::endl;
			menu = !menu;
		}
	}
}