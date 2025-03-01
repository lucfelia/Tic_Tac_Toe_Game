#include "defines.h"
#include "board.h"
#define AMOUNT 4

std::vector<int> randomer(int options[AMOUNT]) {
    std::vector<int> positions;
    for (int i = 0; i < AMOUNT; ++i) {
        positions.push_back(options[i]);
    }

    for (int i = AMOUNT - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        int temp = positions[i];
        positions[i] = positions[j];
        positions[j] = temp;
    }
    return positions;
}

std::vector<char> randomer2(char options[AMOUNT]) {
    std::vector<char> positions;
    for (int i = 0; i < AMOUNT; ++i) {
        positions.push_back(options[i]);
    }

    for (int i = AMOUNT - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        int temp = positions[i];
        positions[i] = positions[j];
        positions[j] = temp;
    }
    return positions;
}

void generation(std::vector<int> amount_liquid, std::vector<char> liquid_type, char bottles[HEIGHT][LENGHT]) {
    int num1 = 0;
    for (size_t i = 0; i < amount_liquid.size(); ++i) {
        num1 = amount_liquid[i];
        char char1 = ' ';
        char1 = liquid_type[i];
        for (int j = 0; j < num1; ++j) {
            bool bucle = true;
            while (bucle) {
                int randnum = rand() % LENGHT;
                if (bottles[2][randnum] == ' ') {
                    bottles[2][randnum] = char1;
                    bucle = false;
                }
                else if (bottles[1][randnum] == ' ') {
                    bottles[1][randnum] = char1;
                    bucle = false;
                }
                else if (bottles[0][randnum] == ' ') {
                    bottles[0][randnum] = char1;
                    bucle = false;
                }
            }
        }
    }
}

bool wincondition(char bottles[HEIGHT][LENGHT], int &puntos) {
    bool diferentes = false; 

    for (int pos1 = 0; pos1 < LENGHT; pos1++) {
        char liquido1 = ' ';
        bool encontrado = false;
        bool completa = true; 

        for (int pos2 = 0; pos2 < HEIGHT; pos2++) {
            char caracter = bottles[pos2][pos1];

            if (caracter != ' ') {
                if (!encontrado) {
                    liquido1 = caracter;
                    encontrado = true;
                }
                else if (caracter != liquido1) {
                    diferentes = true; 
                }
            }
            else {
                completa = false; 
            }
        }
        if (completa && encontrado) {
            puntos += 30;
        }
    }
    return diferentes;
}

void savescore(std::string name, int puntos) {


    std::ofstream writeFile;
    writeFile.open("score.bin", std::ios::out | std::ios::binary |std::ios::app);

    size_t longitud = name.size();
    writeFile.write(reinterpret_cast<const char*>(&longitud), sizeof(size_t)); 
    writeFile.write(name.c_str(), longitud); 
    writeFile.write(reinterpret_cast<const char*>(&puntos), sizeof(int)); 

    writeFile.close();
}

void loadscore() {
    std::ifstream readFile;
    readFile.open("score.bin", std::ios::in | std::ios::binary);

    if (!readFile) {
        std::cerr << "Error with reading the file." << std::endl;
        return;  
    }

    while (readFile.peek() != EOF) {  
        size_t large;
        readFile.read(reinterpret_cast<char*>(&large), sizeof(size_t));

        if (readFile.eof()) break;  

        std::string name;
        name.resize(large); 
        readFile.read(&name[0], large);

        int puntos;
        readFile.read(reinterpret_cast<char*>(&puntos), sizeof(int));

        std::cout << name << ": " << puntos << std::endl;
    }

    readFile.close();
}

void main() {
	srand(time(NULL));
	char bottles[HEIGHT][LENGHT];
	char liquids[AMOUNT] = { 'X', 'O', '#', 'S' };
	int options[AMOUNT] = { 3, 2, 4, 3 };
    std::vector<int> amount_liquid;
    std::vector<char> liquid_type;
    bool menu = true;
    int chosen1;
    int chosen2;
    char option1;
    char option2;
    short movements=0;
    int puntos=0;
    bool isname = false;
    std::string name;

    while (menu) {
        std::cout << "1-NEW GAME" << std::endl;
        std::cout << "2-SCORES" << std::endl;
        std::cout << "3-SORTIR" << std::endl << std::endl;
        std::cout << "Decision:";
        std::cin >> option1;

        if (option1 == '1') {
            create_board(bottles);
            amount_liquid = randomer(options);
            liquid_type = randomer2(liquids);
            generation(amount_liquid, liquid_type, bottles);
            movements = 0;
            while (menu) {
                if (!isname) {
                    std::cout << "Introduce your name: ";
                    std::cin >> name;
                    isname = true;
                }
                system("cls");
                show_board(bottles,movements,puntos);

                std::cout << "Please select the bottle you want to fill other bottles with your hot liquid!" << std::endl;
                std::cin >> option1;
                std::cout << "Please select the bottle that is gonna be filled with your hot liquid!" << std::endl;
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
                menu = wincondition(bottles,puntos);
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
        else if (option1 == '2') {
            system("cls");
            std::cout << "Scores:" << std::endl;
            loadscore();
            system("pause");
            system("cls");
        }
        else if (option1 == '3') {
            menu = false;
        }
    }
    savescore(name, puntos);
}