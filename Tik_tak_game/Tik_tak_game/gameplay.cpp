#include "board.h"
#include "defines.h"
#include "files.h"

void bot(char board[TABLE_LENGHT][TABLE_LENGHT]) {
	int num1 = rand() % 3;
	int num2 = rand() % 3;

	while (board[num1][num2] != ' ') {
		num1 = rand() % 3;
		num2 = rand() % 3;
	}
	board[num1][num2] = 'O';
}

void turns(short& truenumber_1, short& truenumber_2, char& userinput_1, char& userinput_2, char board[TABLE_LENGHT][TABLE_LENGHT], bool turnplayer_1) {

	bool timer = true;
	while (timer) {

		if (turnplayer_1) {
			std::cout << std::endl << "PLAYER 1 TURN! 'X'" << std::endl;
			std::cout << std::endl << "Press (Q) to Save & Quit." << std::endl << std::endl << "In what position do you want to add the numbers (Row): " << std::endl;
			std::cin >> userinput_1;
			if (userinput_1 == 'q' || userinput_1 == 'Q') {
				timer = false;
			}
			else {
				if (userinput_1 < '1' || userinput_1>'3') {
					system("cls");
					printBoard(board);
					std::cout << std::endl << "Invalid character error!" << std::endl;
				}
				else {
					std::cout << std::endl << "In what position do you want to add the numbers (Column): " << std::endl;
					std::cin >> userinput_2;
					if (userinput_1 == 'q' || userinput_1 == 'Q') {
						timer = false;
					}
					else {
						if (userinput_2 < '1' || userinput_2>'3') {
							system("cls");
							printBoard(board);
							std::cout << std::endl << "Invalid character error!" << std::endl;

						}
						else {
							truenumber_1 = ((short)userinput_1 + CHAR_TRANSFOMATION);
							truenumber_2 = ((short)userinput_2 + CHAR_TRANSFOMATION);
						}
					}
				}
			}
			if (board[truenumber_1][truenumber_2] != ' ') {
				system("cls");
				printBoard(board);
				std::cout << std::endl << "Position alredy ocupied!" << std::endl;

			}
			else if (turnplayer_1 && timer) {
				board[truenumber_1][truenumber_2] = 'X';
				timer = false;

			}
			else if (!turnplayer_1 && timer) {
				board[truenumber_1][truenumber_2] = 'O';
				timer = false;

			}
		}
		else {
			std::cout << std::endl << "PLAYER 2 TURN! 'O'" << std::endl;
			bot(board);
			timer = false;
			system("pause");
		}
	}
}

bool check(char board[TABLE_LENGHT][TABLE_LENGHT], short truenumber_1, short truenumber_2) {
	for (int i = 0; i < TABLE_LENGHT; i++) {
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			return true;
		}
		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			return true;
		}
	}
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		return true;
	}
	if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		return true;
	}
	return false;
}

void newGame(bool gameover, char board[TABLE_LENGHT][TABLE_LENGHT], char userinput_1, char userinput_2, short truenumber_1, short truenumber_2, bool turnplayer_1) {
	gameover = false;
	turnplayer_1 = true;
	createBoard(board);

	while (!gameover) {
		printBoard(board);
		turns(truenumber_1, truenumber_2, userinput_1, userinput_2, board, turnplayer_1);
		turnplayer_1 = !turnplayer_1;
		gameover = check(board, truenumber_1, truenumber_2);

		if (userinput_1 == 'q' || userinput_1 == 'Q' || userinput_2 == 'q' || userinput_2 == 'Q') {
			saveFile(board);
			gameover = true;
		}
		if (gameover) {
			if (!turnplayer_1) {
				std::cout << std::endl << "PLAYER 1 WINS!" << std::endl;
			}
			else {
				std::cout << std::endl << "PLAYER 2 WINS!" << std::endl;
			}
			system("cls");
			printBoard(board);
			system("pause");
		}
		system("cls");
	}
}

void loadGame(bool gameover, char board[TABLE_LENGHT][TABLE_LENGHT], char userinput_1, char userinput_2, short truenumber_1, short truenumber_2, bool turnplayer_1) {

	gameover = false;
	readFile(board);
	while (!gameover) {
		printBoard(board);
		turns(truenumber_1, truenumber_2, userinput_1, userinput_2, board, turnplayer_1);
		turnplayer_1 = !turnplayer_1;
		gameover = check(board, truenumber_1, truenumber_2);
		if (userinput_1 == 'q' || userinput_1 == 'Q' || userinput_2 == 'q' || userinput_2 == 'Q') {
			saveFile(board);
			gameover = true;
		}
		if (gameover) {
			if (!turnplayer_1) {
				std::cout << std::endl << "PLAYER 1 WINS!" << std::endl;
			}
			else {
				std::cout << std::endl << "PLAYER 2 WINS!" << std::endl;
			}
			system("pause");
		}
		system("cls");
	}
}

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
	srand(time(NULL));

	createBoard(board);

	while (menu) {

		std::cout << "CHOOSE AN OPTION!" << std::endl;
		std::cout << "1.PLAY NEW GAME" << std::endl;
		std::cout << "2.LOAD GAME" << std::endl;
		std::cout << "3.QUIT" << std::endl;
		std::cin >> option;

		system("cls");
		if (option == '1') {
			newGame(gameover, board, userinput_1, userinput_2, truenumber_1, truenumber_2, turnplayer_1);
		}
		else  if (option == '2') {
			loadGame(gameover, board, userinput_1, userinput_2, truenumber_1, truenumber_2, turnplayer_1);
		}
		else if (option == '3') {
			std::cout << std::endl << "BYE! <3" << std::endl;
			menu = !menu;
		}
	}
}