#include "defines.h"
#include "board.h"
#define AMOUNT 4


void main() {
	srand(time(NULL));
	char bottles[HEIGHT][LENGHT];
	char LIQUIDS[AMOUNT] = { 'X', 'O', '#', 'S' };
	int options[AMOUNT] = { 3, 2, 4, 3 };
	create_board(bottles);
	show_board(bottles);
	int num1 = rand() % AMOUNT;


}