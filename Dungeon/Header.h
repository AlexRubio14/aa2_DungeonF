#pragma once
#include "Combat.h"
#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include "Chests.h"
#include "Random.h"
#include "Start.h"
#include "GameOver.h"

#define MAX_POTIONS 3
#define NUM_COLUMS 5
#define NUM_ROWS 5
#define NUM_COFRES 2

using namespace std;
enum Scene;

int Barres(int primeraBarra, int segonaBarra);
void PrintMap(Player& link, Enemy goblin[], Chest cofre[], int& menosEnemy);
void MoveAction(char action, Player& link, Enemy goblin[], Chest cofre[], int& menosEnemy);
bool ChestFounded(Player& link, Chest cofre[], bool& chestFounded);
bool EnemyFounded(Player& link, Enemy goblin[], bool& goblinFounded);

//system("pause");
//system("cls");