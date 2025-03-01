#include "defines.h"
#pragma once

std::vector<int> integerRandom(int options[LIQUID_AMOUNT]);

std::vector<char> charRandom(char options[LIQUID_AMOUNT]);

void liquidDistribution(std::vector<int> amount_liquid, std::vector<char> liquid_type, char bottles[HEIGHT][LENGHT]);