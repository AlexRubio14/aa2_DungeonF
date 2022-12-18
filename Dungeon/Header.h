#pragma once
#include "Combat.h"
#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include "Chests.h"
#define MAX_POTIONS 3
#define NUM_COLUMS 5
#define NUM_ROWS 5

using namespace std;

int Barres(int primeraBarra, int segonaBarra);
void PrintMap(Player& link, Enemy e[]);

//system("pause");
//system("cls");