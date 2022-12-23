#include "Header.h"

bool ChestFounded(Player& link, Chest cofre[], bool& chestFounded) {

	for (int i = 0; i < 2; i++)
	{
		if (link.position.x == cofre[i].position.x && link.position.y == cofre[i].position.y)
		{
			cofre[i].position.x = 30;
			chestFounded = true;
		}
	}
	return chestFounded;
}

void Chest::Init() 
{
	position.x = RandomNumber(0, 4);
	position.y = RandomNumber(0, 4);

	gold = RandomNumber(50, 200);
}

void InitLooting(Player& link)
{
	enum looting { triforce, tunic, masterSword, shield, minishCap, epona, brokenLeaf, majorasMask, navi, bomb };
	int objects = RandomNumber (0,9);
	switch (objects)
	{
	case triforce:
		link.gold += 400;
		link.maxHealth += 50;
		link.maxStamina += 50;
		link.maxMoves += 1;
		cout << "		> Triforce   +50 HP, +50 Stamina, +1 Move" << endl;
		break;
	case tunic:	
		link.gold += 150;
		link.maxHealth += 25;
		link.maxStamina -= 10;
		cout << "		> Tunic   +25 HP, -10 Stamina" << endl;
		if (link.stamina > link.maxStamina)
			link.stamina = link.maxStamina;
		break;
	case masterSword:
		link.gold += 275;
		link.maxStamina += 10;
		cout << "		> Master Sword   +10 Stamina" << endl;
		break;
	case shield:
		link.gold += 100;
		link.maxHealth += 30;
		link.maxMoves -= 1;
		cout << "		> Shield   +30 HP, -1 Move" << endl;
		if (link.moves > link.maxMoves)
			link.moves = link.maxMoves;
		break;
	case minishCap:
		link.gold += 80;
		link.maxHealth += 5;
		link.maxMoves += 1;
		cout << "		> Minish Cap   +5 HP, +1 Move" << endl;
		break;
	case epona:
		link.gold += 120;
		link.maxStamina += 30;
		link.maxMoves += 2;
		cout << "		> Epona   +30 Stamina, +2 Move" << endl;
		break;
	case brokenLeaf:
		link.gold += 10;
		link.maxStamina -= 10;
		cout << "		> Broken Leaf   -10 Stamina" << endl;
		if (link.stamina > link.maxStamina)
			link.stamina = link.maxStamina;
		break;
	case majorasMask:
		link.gold -= 80;
		link.maxHealth -= 40;
		link.maxStamina += 30;
		cout << "		> Majoras Mask   -40 HP, +30 Stamina" << endl;
		if (link.health > link.maxHealth)
			link.health = link.maxHealth;
		break;
	case navi:
		link.gold -= 300;
		link.maxHealth -= 10;
		link.maxStamina -= 10;
		cout << "		> Navi   -10 HP, -10 Stamina" << endl;
		if (link.health > link.maxHealth)
			link.health = link.maxHealth;
		if (link.stamina > link.maxStamina)
			link.stamina = link.maxStamina;
		break;
	case bomb:
		link.gold += 0;
		link.health -= 15;
		cout << "		> There's a booomb!!   -15 HP" << endl;
		break;
	default:
		break;
	}
}

//Aquesta funció comprova que els cofres no es col·loquin sobre el jugador //Inicialitzat al main.cpp
void CrearCofres(Player& link, Chest cofre[]) {
	for (int c = 0; c < NUM_COFRES; c++)
	{
		if (cofre[c].position.x == link.position.x && cofre[c].position.y == link.position.y)
		{
			cofre[c].position.x = RandomNumber(0, 4);
			cofre[c].position.y = RandomNumber(0, 4);
		}
		for (int z = 1; z < NUM_COFRES; z++)
		{
			if (cofre[c].position.x == cofre[c - z].position.x && cofre[c].position.y == cofre[c - c].position.y)
			{
				cofre[c].position.x = RandomNumber(0, 4);
				cofre[c].position.y = RandomNumber(0, 4);
			}
		}
	}
}

void OpenChest(Player& link, Chest cofre[], int& chestClosed) {

	chestClosed--;
	int chestGold = RandomNumber(50, 200);
	link.gold += chestGold;
	int containsPotion = RandomNumber(0,3);
	printf("----- CHEST -----\n\n > You founded a chest. You've obtained the following list of items: \n\n");
	if (containsPotion == 0){
		printf("	> %d gold!\n	> 1 Potion\n", chestGold);
		link.potions++;
	}
	else 
	{
		printf("		> %d gold!\n", chestGold);	
	}
	if (link.potions > link.maxPotion)
		link.potions = link.maxPotion;
	printf("	> This chest has gear equipment inside!\n");
	InitLooting(link);
	printf("\n---------------------------------------- \n");
	system("pause");
	system("cls");
}