#include "defines.h"

// Función para randomizar la cantidad de caracteres, el número:
std::vector<int> integerRandom(int options[LIQUID_AMOUNT]) {

    std::vector<int> positions;

    for (int i = 0; i < LIQUID_AMOUNT; ++i) {
        positions.push_back(options[i]);
    }

    for (int i = LIQUID_AMOUNT - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        int temp = positions[i];
        positions[i] = positions[j];
        positions[j] = temp;
    }

    return positions;
}

// Función para randomizar la letra, el caracter:
std::vector<char> charRandom(char options[LIQUID_AMOUNT]) {

    std::vector<char> positions;

    for (int i = 0; i < LIQUID_AMOUNT; ++i) {
        positions.push_back(options[i]);
    }

    for (int i = LIQUID_AMOUNT - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        int temp = positions[i];
        positions[i] = positions[j];
        positions[j] = temp;
    }

    return positions;
}

// Función para poner de forma aletoria los líquidos en las botellas:
void liquidDistribution(std::vector<int> amount_liquid, std::vector<char> liquid_type, char bottles[HEIGHT][LENGHT]) {

    int num1 = 0;

    for (size_t i = 0; i < amount_liquid.size(); ++i) {

        num1 = amount_liquid[i];
        char char1 = VOID;
        char1 = liquid_type[i];

        for (int j = 0; j < num1; ++j) {

            bool loop = true;

            while (loop) {
                int randnum = rand() % LENGHT;

                if (bottles[2][randnum] == VOID) {
                    bottles[2][randnum] = char1;
                    loop = false;
                }

                else if (bottles[1][randnum] == VOID) {
                    bottles[1][randnum] = char1;
                    loop = false;
                }

                else if (bottles[0][randnum] == VOID) {
                    bottles[0][randnum] = char1;
                    loop = false;
                }
            }
        }
    }
}