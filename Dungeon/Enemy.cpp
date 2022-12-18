#include "Enemy.h"

void Enemy::Initialize() {
    position.x = RandomBetweenRange(0, 4);
    position.y = RandomBetweenRange(0, 4);

    maxHealth = RandomBetweenRange(60, 90);
    health = maxHealth;

    maxStamina = RandomBetweenRange(60, 90);
    stamina = maxStamina;

    isAlive = true;
}