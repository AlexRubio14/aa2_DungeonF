#include "Player.h"

void Player::Init() 
{
    Player link;
    position.x = 2;
    position.y = 3;

    gold = 0;

    maxHealth = RandomNumber(90, 110);
    health = maxHealth;

    maxStamina = RandomNumber(90, 110);
    stamina = maxStamina;

    maxMoves = 3;
    moves = maxMoves;

    maxPotion = 3;
    potions = maxPotion;
    isAlive = true;
}

void PrintPlayer() {
    printf("------ COMBAT ------\n---- Player ----\n");
    printf("       ____ \n");
    printf("      |._. |  \n");
    printf("      |  __|  \n");
    printf("  <==|| |   | \n");
    printf("      |_|___|  \n");
    printf("      _|  _|  \n\n");
}

void DrinkPotion(Player& link) {
    link.health += link.maxHealth * 0.4;
    if (link.health > link.maxHealth) {
        link.health = link.maxHealth;
    }
    link.potions--;
    //SI NO TIENES POTIONS
    if (link.potions <= 0)
    {
        printf("You have NO potions!");
        link.potions = 0;
    }
}