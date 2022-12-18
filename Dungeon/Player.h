#pragma once
#include "Header.h"
#include "MapPosition.h"
struct Player {
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

void DrinkPotion(Player& link) {
    link.health += link.maxHealth * 0.4;
    if (link.health > link.maxHealth) {
        link.health = link.maxHealth;
    }
    link.potions--;
}