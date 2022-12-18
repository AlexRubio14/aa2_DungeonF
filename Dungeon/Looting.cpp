#include "Chests.h"

void Chest::looting::InitLooting()
{
	looting triforce, tunic, masterSword, shield, minishCap, epona, brokenLeaf, majorasMask, navi, bomb;

	triforce.gold = 400;
	triforce.HP = 50;
	triforce.stamina = 50;
	triforce.agility = 1;
	triforce.attack = 0;

	tunic.gold = 150;
	tunic.HP = 25;
	tunic.stamina = -10;
	tunic.agility = 0;
	tunic.attack = 0;

	masterSword.gold = 275;
	masterSword.HP = 0;
	masterSword.stamina = 10;
	masterSword.agility = 0;
	masterSword.attack = 15;

	shield.gold = 100;
	shield.HP = 30;
	shield.stamina = 0;
	shield.agility = -1;
	shield.attack = 0;

	minishCap.gold = 80;
	minishCap.HP = 5;
	minishCap.stamina = 0;
	minishCap.agility = 1;
	minishCap.attack = 0;

	epona.gold = 120;
	epona.HP = 0;
	epona.stamina = 30;
	epona.agility = 2;
	epona.attack = 0;

	brokenLeaf.gold = 10;
	brokenLeaf.HP = 0;
	brokenLeaf.stamina = -10;
	brokenLeaf.agility = 0;
	brokenLeaf.attack = -10;

	majorasMask.gold = -80;
	majorasMask.HP = -40;
	majorasMask.stamina = 30;
	majorasMask.agility = 0;
	majorasMask.attack = 0;

	navi.gold = -300;
	navi.HP = -10;
	navi.stamina = -10;
	navi.agility = -1;
	navi.attack = 0;

	bomb.gold = 0;
	bomb.HP = -15;
	bomb.stamina = 0;
	bomb.agility = 0;
	bomb.attack = 0;
}