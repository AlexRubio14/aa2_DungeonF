#include "Enemy.h"
#include "Header.h"

void Enemy::Init() {

    position.x = RandomNumber(0, 4);
    position.y = RandomNumber(0, 4);

    maxHealth = RandomNumber(60, 90);
    health = maxHealth;

    maxStamina = RandomNumber(60, 90);
    stamina = maxStamina;

    isAlive = true;
}

bool EnemyFounded(Player& link, Enemy goblin[], bool& goblinFounded) {

	for (int i = 0; i < 5; i++)
	{
		if (link.position.x == goblin[i].position.x && link.position.y == goblin[i].position.y)
		{
			goblin[i].position.x = 30;
			goblinFounded = true;
		}
	}
	return goblinFounded;
}

void DrawEnemy(int draw)
{
	if (draw == 0)
	{
		printf("\n---- MiniRichard  ----\n");
		printf("      ___  \n");
		printf("     |o_o|  \n");
		printf("    __|  |__ \n");
		printf("   |  |__|  |\n");
		printf("    _|    |_  \n");

	}
	else if (draw == 1)
	{
		printf("\n---- Radev's Mug ----\n\n");
		printf("   _|     | \n");
		printf("  (_| T_T | \n");
		printf("    |_____| \n");
	}
	else if (draw == 2)
	{
		printf("\n---- Suspicious Radev ----\n");
		printf("      _v__ \n");
		printf("     |-_- |  \n");
		printf("     s|    |s \n");
		printf("      |____|  \n");
		printf("     _|    |_  \n");

	}
	else
	{
		printf("\n---- Creators ----\n");
		printf("               ____  \n");
		printf(" hi! ____     | 'w'|    \n");
		printf("    | '3'|   ||    ||    \n");
		printf("   '|____|'   |____|         \n");
		printf("      L L       L L  \n");
	}
}

