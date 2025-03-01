#include "defines.h"
#include "board.h"
#include "randoms.h"
#include "filemanagement.h"

//Chat
bool winCondition(char bottles[HEIGHT][LENGHT], int& points) {
    bool different = false;

    for (int pos1 = 0; pos1 < LENGHT; pos1++) {
        char liquid1 = VOID;
        bool found = false;
        bool complete = true;

        for (int pos2 = 0; pos2 < HEIGHT; pos2++) {
            char caracter = bottles[pos2][pos1];

            if (caracter != VOID) {
                if (!found) {
                    liquid1 = caracter;
                    found = true;
                }
                else if (caracter != liquid1) {
                    different = true;
                }
            }
            else {
                complete = false;
            }
        }
        if (complete && found) {
            points += 30;
        }
    }
    return different;
}

void firstOption(bool menu, std::string name, char option1, int points) {

    srand(time(NULL));
    char bottles[HEIGHT][LENGHT];
    char liquids[LIQUID_AMOUNT] = { 'X', 'O', '#', 'S' };
    int options[LIQUID_AMOUNT] = { 3, 2, 4, 3 };
    std::vector<int> amount_liquid;
    std::vector<char> liquid_type;
    int chosen1;
    int chosen2;
    char option2;
    short movements = 0;
    bool isname = false;

    createBoard(bottles);
    amount_liquid = integerRandom(options);
    liquid_type = charRandom(liquids);
    liquidDistribution(amount_liquid, liquid_type, bottles);
    movements = 0;
    while (menu) {
        if (!isname) {
            std::cout << "Introduce your name: ";
            std::cin >> name;
            isname = true;
        }
        system("cls");
        showBoard(bottles, movements, points);

        std::cout << "Please select bottle of origin!" << std::endl;
        std::cin >> option1;
        std::cout << "Please select destination bottle!" << std::endl;
        std::cin >> option2;
        chosen1 = int(option1 - 49);
        chosen2 = int(option2 - 49);

        if (chosen1 >= LENGHT || chosen1 < 0 || chosen2 >= LENGHT || chosen2 < 0) {
            std::cout << "Error: Try Again" << std::endl;
        }
        else {
            bool empty = true;
            bool available = false;
            int pos_destino = -1;
            int pos_origen = -1;

            for (int i = HEIGHT - 1; i >= 0; i--) {
                if (bottles[i][chosen2] == ' ') {
                    available = true;
                    pos_destino = i;
                    break;
                }
            }

            if (available) {
                for (int i = 0; i < HEIGHT; i++) {
                    if (bottles[i][chosen1] != ' ') {
                        pos_origen = i;
                        empty = false;
                        break;
                    }
                }

                if (!empty) {
                    bottles[pos_destino][chosen2] = bottles[pos_origen][chosen1];
                    bottles[pos_origen][chosen1] = ' ';
                    movements++;

                    system("cls");
                }
                else {
                    std::cout << "The bottle is empty" << std::endl;
                }
            }
            else {
                std::cout << "The bottle you want to fill is already full" << std::endl;
            }
        }
        menu = winCondition(bottles, points);
        if (!menu) {
            std::cout << "You Win thanks for playing!!!!!" << std::endl;
            system("pause");
        }
        else if (movements == 10) {
            std::cout << "Game over!!!!!" << std::endl;
            system("pause");
            menu = false;
        }
        system("cls");
    }
    menu = true;
}

void secondOption() {
    system("cls");
    std::cout << "Scores:" << std::endl;
    loadscore();
    system("pause");
    system("cls");
}