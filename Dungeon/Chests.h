#pragma once
#include "Map.h"
#include "Player.h"


struct Chest
{
	MapPosition position;

	bool looted;
	int gold; //pot tenir entre 50 - 200
	bool potion;
	struct looting
	{
		int gold;
		int HP;
		int stamina;
		int agility;
		int attack;

		void Init();
	};
	void Init();
};
void CrearCofres(Player& link, Chest cofre[]);