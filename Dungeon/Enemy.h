#pragma once
#include "Header.h"
#include "MapPosition.h"

struct Enemy {
    MapPosition position;

    bool isAlive;

    int health;
    int maxHealth;

    int stamina;
    int maxStamina;

    void Initialize();
};