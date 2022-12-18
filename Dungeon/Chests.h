#pragma once
#include "Header.h"
struct Chest
{
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

		void InitLooting();
	};
};