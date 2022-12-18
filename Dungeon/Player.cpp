#include "Player.h"

void Player::Init() {
    position.x = 2;
    position.y = 3;

    gold = 0;

    maxHealth = RandomBetweenRange(90, 110);
    health = maxHealth;

    maxStamina = RandomBetweenRange(90, 110);
    stamina = maxStamina;

    maxAgility = 3;
    agility = maxAgility;
    currentAgility = maxAgility;

    maxPotion = 3;
    potions = maxPotion;
    isAlive = true;
}
