#pragma once
#include "defines.h"

void showMenu();

bool winCondition(char bottles[HEIGHT][LENGHT], int& points, int rows[LENGHT]);

void firstOption(bool menu, std::string &name, char option1, int &points, bool isname);

void secondOption(std::string name, int puntos);
