#include "defines.h"
#include "filemanagement.h"
#include "gameplay.h"

// FUNCIÓN PRINCIPAL, LOOP DEL JUEGO:

void main() {

    bool menu = true;
    char option1;
    int points = 0;
    std::string name;
    bool isname = false;

    while (menu) {

        showMenu();

        std::cin >> option1;

        if (option1 == OPTION_ONE) {
            firstOption(menu, name, option1, points, isname);
        }
        else if (option1 == OPTION_TWO) {
            secondOption(name,points);
        }
        else if (option1 == OPTION_THREE) {
            menu = false;
        }
        else {
            std::cout << "Not a valid option." << std::endl;
            system("pause");
            system("cls");
        }
    }
    saveScores(name, points);
}