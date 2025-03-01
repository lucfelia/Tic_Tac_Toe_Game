#include "defines.h"
#include "filemanagement.h"
#include "gameplay.h"

void main() {

    bool menu = true;
    char option1;
    int points = 0;
    std::string name;
    bool isname = false;

    while (menu) {
        std::cout << "1-NEW GAME" << std::endl;
        std::cout << "2-SCORES" << std::endl;
        std::cout << "3-SORTIR" << std::endl << std::endl;
        std::cout << "Decision:";
        std::cin >> option1;

        if (option1 == '1') {
            firstOption(menu, name, option1, points, isname);
        }
        else if (option1 == '2') {
            secondOption(name,points);
        }
        else if (option1 == '3') {
            menu = false;
        }
    }
    saveScores(name, points);
}