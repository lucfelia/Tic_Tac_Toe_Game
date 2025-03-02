#include "defines.h"
#include "board.h"
#include "randoms.h"
#include "filemanagement.h"

// Función para mostrar el menú principal:
void showMenu() {
    std::cout << "             .                    .                        .  " << std::endl;
    std::cout << "   . , , ,-. |- ,-. ,-.   ,-. ,-. |  ,-. ,-.   ,-. ,-. ,-. |- " << std::endl;
    std::cout << "   |/|/  ,-| |  |-' |     |   | | |  | | |     `-. | | |   |  " << std::endl;
    std::cout << "   ' '   `-^ `' `-' '     `-' `-' `' `-' '     `-' `-' '   `'" << std::endl;
    std::cout << "                    Made by Lucia and Sergi <3" << std::endl << std::endl;
    std::cout << MARGINS << std::endl ;
    std::cout << "|                         1- NEW GAME                         |" << std::endl;
    std::cout << "|                         2- SCORES                           |" << std::endl;
    std::cout << "|                         3- EXIT                             |" << std::endl ;
    std::cout << MARGINS << std::endl ;
    std::cout << "\tOPTION: ";
}

// Función que retorna un booleano si el juego ha acabado:
bool winCondition(char bottles[HEIGHT][LENGHT], int& points,int rows[LENGHT]) {
    bool different = false;
    for (int pos1 = 0; pos1 < LENGHT; pos1++) {
        char liquid1 = VOID;
        bool found = false;
        bool complete = true;

        for (int pos2 = 0; pos2 < HEIGHT; pos2++) {
            char character = bottles[pos2][pos1];

            if (character != VOID) {
                if (!found) {
                    liquid1 = character;
                    found = true;
                }
                else if (character != liquid1) {
                    different = true;
                }
            }

            if (bottles[pos2][pos1] != bottles[2][pos1] && rows[pos1]!=1) {
                    complete = false;              
            }

        }
        if (complete) {
            rows[pos1] = 1;
            char amount_points = bottles[2][pos1];
            if (amount_points == VOID) {
                points += 50;

            }
            else {
                points += 30;
            }
        }
    }
    return different;
}

// Función principal del juegos, donde hacemos los turnos y recogemos las opciones de los jugadores:
void firstOption(bool menu, std::string &name, char origin, int &points,bool isname) {

    srand(time(NULL));
    char bottles[HEIGHT][LENGHT];
    char liquid_char[LIQUID_AMOUNT] = { 'X', 'O', '#', 'S' };
    int liquid_num[LIQUID_AMOUNT] = { 3, 2, 4, 3 };
    std::vector<int> amount_liquid;
    std::vector<char> liquid_type;
    int numeric_origin;
    int numeric_destination;
    char destination;
    short movements = 0;
    int rows[LENGHT] = { 0,0,0,0,0,0 };

    createBoard(bottles);
    amount_liquid = integerRandom(liquid_num);
    liquid_type = charRandom(liquid_char);
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

        std::cout << "Please select bottle of origin: ";
        std::cin >> origin;
        std::cout << "Please select destination bottle: ";
        std::cin >> destination;
        numeric_origin = int(origin - 49);
        numeric_destination = int(destination - 49);

        if (numeric_origin >= LENGHT || numeric_origin < 0 || numeric_destination >= LENGHT || numeric_destination < 0 || numeric_origin == numeric_destination||bottles[0][numeric_destination]!=VOID) {
            std::cout << "Error: Try Again" << std::endl;
            system("pause");
        }
        else {
            bool empty = true;
            bool available = false;
            int pos_destino = -1;
            int pos_origen = -1;

            for (int i = HEIGHT - 1; i >= 0; i--) {
                if (bottles[i][numeric_destination] == ' ') {
                    available = true;
                    pos_destino = i;
                    break;
                }
            }

            if (available) {
                for (int i = 0; i < HEIGHT; i++) {
                    if (bottles[i][numeric_origin] != ' ') {
                        pos_origen = i;
                        empty = false;
                        break;
                    }
                }

                if (!empty) {
                    bottles[pos_destino][numeric_destination] = bottles[pos_origen][numeric_origin];
                    bottles[pos_origen][numeric_origin] = ' ';
                    movements++;

                    system("cls");
                }
                else {
                    std::cout << "The bottle is empty." << std::endl;
                }
            }
            else {
                std::cout << "The bottle you want to fill is already full." << std::endl;
            }
            menu = winCondition(bottles, points, rows);
        }
        if (!menu) {
            std::cout << "You Win. Thanks for playing!" << std::endl;
            system("pause");
        }
        else if (movements == 10) {
            std::cout << "Game over!" << std::endl;
            system("pause");
            menu = false;
        }
        system("cls");
    }
    menu = true;
}

// Función para recoger y mostrar las puntuaciones:
void secondOption(std::string name, int puntos) {

    saveScores(name,puntos);
    system("cls");

    std::cout << MARGINS << std::endl;
    std::cout << "|                         2- SCORES                           |" << std::endl;
    std::cout << MARGINS << std::endl;
    loadscore();

    system("pause");
    system("cls");
}