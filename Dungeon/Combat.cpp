#include "Combat.h"

void PlayCombat(Player& link, Enemy& goblin) {

	goblin.Init();
	int pAttack, pStaminaUsed = 0;
	int eAttack = RandomNumber(goblin.maxStamina * 0.2, goblin.stamina), eStaminaUsed = 0;
	int draw = RandomNumber(0, 3);

	while (link.isAlive && goblin.isAlive) {
		system("cls");
		PrintPlayer();

		printf(" HP ");
		Barres(link.health, link.maxHealth);
		printf(" %d / %d \n", link.health, link.maxHealth);
		printf(" ST ");
		Barres(link.stamina, link.maxStamina);
		printf(" %d / %d \n", link.stamina, link.maxStamina);

		printf("\nPotions % d / 3\n-----------------------------\n", link.potions);
		DrawEnemy(draw);

		printf(" HP ");
		Barres(goblin.health, goblin.maxHealth);
		printf(" ?? / ?? \n");
		printf(" ST ");
		Barres(goblin.stamina, goblin.maxStamina);
		printf(" ?? / ?? \n");

		printf("-----------------------------\n\n A--> Attack\t D --> Defend\n R --> Rest\t P --> Potions \n\n Enter your action: ");

		char actions, eAction;
		cin >> actions;

		if (goblin.health < (goblin.maxHealth * 0.3) && goblin.stamina < (goblin.maxStamina * 0.3)) { // si pasa això l'enemic es defensara
			eAction = 'D';
		}
		else if (goblin.stamina < (goblin.maxStamina * 0.2)) { // si pasa això l'enemic descansara
			eAction = 'R';
		}
		else {					// si pasa aixo l'enemic atacara
			eAction = 'A';
		}

		switch (actions) {
		case 'A':
		case 'a':
			printf_s(" \nEnter the attack value (Max %d): ", link.stamina);
			cin >> pAttack;

			if (pAttack < 0 || pAttack > link.maxStamina) { // si posa un valor no possible
				break;
			}

			if (eAction == 'A') { // enemic ataca

				if (pAttack >= eAttack) { // attack del jugador mes gran que el del enemic
					goblin.health -= pAttack;
					goblin.stamina -= eAttack;
					link.stamina -= pAttack;
					printf("You strike the enemy with more force! The enemy receives %d damage\n", pAttack);
					system("pause");
				}
				else if (eAttack > pAttack) { // attack del enemic mes grand que le del jugador
					link.health -= eAttack;
					goblin.stamina -= eAttack;
					link.stamina -= pAttack;
					printf("The enemy strikes you with more force! You receive %d damage\n", eAttack);
					system("pause");
				}

			}
			else if (eAction == 'D') {// enemic es defensa
				goblin.stamina += goblin.stamina * 0.25;
				goblin.health -= pAttack * 0.75;
				link.stamina -= pAttack;
			//	pStaminaUsed = pAttack * 0.75;
				printf("The enemy blocks your attack, receiving only %d damage\n", (pAttack * 0.75));
				system("pause");
			}
			else if (eAction == 'R') { // l'enemic descansa
				goblin.stamina = goblin.maxStamina;
				goblin.health -= pAttack;
				link.stamina -= pAttack;
				printf("You strike the unpreparaed enemy dealing %d damage\n", pAttack);
				system("pause");
			}
			break;

		case 'D':
		case 'd':
			if (eAction == 'A') {
				link.stamina += 1 + link.stamina * 0.25;
				link.health -= (eAttack * 0.25);
				goblin.stamina -= eAttack;
				int eStaminaUsed = (eAttack * 0.25) + 1;
				printf("You defend the enemy blow, but receive %d damage\n", eStaminaUsed); // Quan passa aixo printa un 0 a la consola en el %d igual esta mal el calcul
				system("pause");
			}
			else if (eAction == 'D') {
				goblin.stamina +=  1 + goblin.stamina * 0.25;
				link.stamina += link.stamina * 0.25;
				printf("You both defend! ");
				system("pause");
			}
			else if (eAction == 'R') {
				goblin.stamina = goblin.maxStamina;
				link.stamina += link.stamina * 0.25;
				printf("You defend while the enemy cacthes a breath! It seems ready to strike! \n");
				system("pause");
			}
			break;

		case 'R':
		case 'r':
			if (eAction == 'A') {
				link.health -= eAttack;
				goblin.stamina -= eAttack;
				link.stamina = link.maxStamina;
				printf("You rest when the enemy hits you, strriking for %d damage\n", eAttack);
				system("pause");
			}
			else if (eAction == 'D') {
				link.stamina = link.maxStamina;
				goblin.stamina += goblin.stamina * 0.25;
				printf("You rest while the enemy defend\n");
				system("pause");
			}
			else if (eAction == 'R') {
				link.stamina = link.maxStamina;
				goblin.stamina = goblin.maxStamina;
				printf("You both rest, gathering up for  clash\n");
				system("pause");
			}
			break;

		case 'P':			//que no superi la vida max
		case 'p':
			if (link.potions == 0) {
				printf("You have no more potions, pobre de mierda\n ");
				system("pause");
				break;
			}

			if (eAction == 'A') {
				DrinkPotion(link);
				int recoverPotion = link.health * 0.4;
				link.health -= eAttack;
				goblin.stamina -= eAttack;
				
				eStaminaUsed = (link.maxHealth * 0.4) - eAttack;
				printf("You drink the potion (+%d HP) when the enemy hits you, striking %d damage\n", recoverPotion, eStaminaUsed);
				system("pause");
				break;

			}
			else if (eAction == 'D') {
				DrinkPotion(link);
				goblin.stamina += goblin.stamina * 0.25;
				printf("You drink the potion while the enemy defends\n");
				system("pause");
				break;
			}
			else if (eAction == 'R') {
				DrinkPotion(link);
				goblin.stamina = goblin.maxStamina;
				printf("You drink the potion while the enemy rests\n");
				system("pause");
				break;
			}
		default:
			printf_s(" ERROR\n");
			system("pause");
			system("cls");
			break;
		}
		if (link.health <= 0) {
			link.isAlive = false;
		}
		else if (goblin.health <= 0) {
			goblin.isAlive = false;
		}
		if (link.stamina > link.maxStamina) {
			link.stamina = link.maxStamina;
		}
		if (link.stamina <= 0)
			link.stamina = 1;
		if (goblin.stamina <= 0)
			goblin.stamina = 1;
	}
	system("cls");
}

int Barres(int primeraBarra, int segonaBarra) {
	int digits;
	digits = (primeraBarra * 10 / segonaBarra);
	printf("[=");
	if (digits == 0)
		printf("         ]");
	else
	{
		for (int d = digits; d > 1; d--)
			printf("=");
		for (int d = digits; d < 10; d++)
			printf(" ");
		printf("]");
	}
	
	return 0;
}





