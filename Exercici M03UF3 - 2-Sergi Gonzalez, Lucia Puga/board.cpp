#include "defines.h"

void create_board(char bottles[HEIGHT][LENGHT]) {

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < LENGHT; j++)
		{
			bottles[i][j] = ' ';
		}
	}
}

void show_board(char bottles[HEIGHT][LENGHT]) {

	for (int i = 0; i < LENGHT; i++) {
		for (int j = 0; j < LENGHT; j++)
		{
			if (i == 0) {
				std::cout << "\\ /" << "\t";
			}
			else if (i <= 3) {
				std::cout << "|" << bottles[i - 1][j] << "|" << "\t";
			}
			else if (i == 4) {
				std::cout << "'''" << "\t";
			}
			else if (i == 5) {
				std::cout << " " << j + 1 << " " << "\t";
			}
		}
		std::cout << std::endl;
	}
}