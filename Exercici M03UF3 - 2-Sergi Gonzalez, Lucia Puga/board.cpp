#include "defines.h"

// Función para generar el tablero y llenarlo de espacios:
void createBoard(char bottles[HEIGHT][LENGHT]) {

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < LENGHT; j++)
		{
			bottles[i][j] = VOID;
		}
	}
}

// Función para printearlo:
void showBoard(char bottles[HEIGHT][LENGHT],short movements,int puntos) {
	std::cout << "Movements until 10: " << movements << std::endl;
	std::cout << "Points: " << puntos << std::endl;
	std::cout << MARGINS << std::endl << std::endl;
	for (int i = 0; i < LENGHT; i++) {
		std::cout << "\t";
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
	std::cout << MARGINS << std::endl;
}