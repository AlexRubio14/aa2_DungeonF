#pragma once
#include "Map.h"

struct Player 
{
    MapPosition position;
    int gold;

    int health;
    int maxHealth;

    int stamina;
    int maxStamina;

    int agility;
    int maxAgility;
    int currentAgility;

    int potions;
    int maxPotion;

    bool isAlive;

    void Init();
};

void DrinkPotion(Player& link);