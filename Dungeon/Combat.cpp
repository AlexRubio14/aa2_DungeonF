#include "Combat.h"



void PlayCombat(Player& link, Enemy& goblin) {

	int pAttack, pStaminaUsed = 0;
	int eAttack = RandomNumber(goblin.maxStamina % 20,goblin.stamina), eStaminaUsed = 0;

	while (link.isAlive && goblin.isAlive) {

		printf_s("----- COMBAT -----\n\n\n ---- Player ---- \n\n");

		barres(link.health, link.maxHealth);
		barres(link.stamina, link.maxStamina);

		printf("\nPotions % d / 3\n\n-----------------------------\n\n ---- Enemy ----\n\n", link.potions);

		barres(goblin.health, goblin.maxHealth);
		barres(goblin.stamina, goblin.maxStamina);

		printf("-----------------------------\n\n A--> Attack\n D --> Defend\n R --> Rest\n P --> Potion \n\n Enter your action: ");

		char actions, eAction;
		cin >> actions;

		if (goblin.health < (goblin.maxHealth * 0.3) && goblin.stamina < (goblin.maxStamina * 0.3)) { // si pasa aix� l'enemic es defensara
			eAction = 'D';
		}
		else if (goblin.stamina < (goblin.maxStamina * 0.2)) { // si pasa aix� l'enemic descansara
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

			if (pAttack < 0 || pAttack > link.maxStamina) {
				break;
			}

			if (eAction == 'A') { // enemic ataca


				if (pAttack >= eAttack) { // attack del jugador mes gran que el del enemic
					goblin.health -= pAttack;
					goblin.stamina -= eAttack;
					link.stamina -= pAttack;
					printf("You strike the enemy with more force! The enemy receives %d damage\n", pAttack);
				}
				else if (eAttack > pAttack) { // attack del enemic mes grand que le del jugador
					link.health -= eAttack;
					goblin.stamina -= eAttack;
					link.stamina -= pAttack;
					printf("The enemy strikes you with more force! You receive %d damage\n", eAttack);
				}

			}
			else if (eAction == 'D') {//l enemic es defensa
				goblin.stamina += goblin.stamina * 0.25;
				goblin.health -= pAttack * 0.75;
				link.stamina -= pAttack;
				pStaminaUsed = pAttack * 0.75;
				printf("The enemy blocks your attack, receiving only %d damage\n", pStaminaUsed);
			}

			else if (eAction == 'R') { // l'enemic descansa
				goblin.stamina = goblin.maxStamina;
				goblin.health -= pAttack;
				link.stamina -= pAttack;
				printf("You strike the unpreparaed enemy dealing %d damage\n", pAttack);

			}
			break;

		case 'D':
		case 'd':
			if (eAction == 'A') {
				link.stamina += link.stamina * 0.25;
				link.health -= (eAttack * 0.25);
				goblin.stamina -= eAttack;
				eStaminaUsed = (eAttack * 0.25) + 1;
				printf("You defend the enemy blow, but receive %d damage\n", eStaminaUsed); // Quan passa aixo printa un 0 a la consola en el %d igual esta mal el calcul

			}
			else if (eAction == 'D') {
				goblin.stamina += goblin.stamina * 0.25;
				link.stamina += link.stamina * 0.25;
				printf("You both defend! ");
			}
			else if (eAction == 'R') {
				goblin.stamina = goblin.maxStamina;
				link.stamina += link.stamina * 0.25;
				printf("You defend while the enemy cacthes a breath! It seems ready to strike! \n");

			}
			break;

		case 'R':
		case 'r':
			if (eAction == 'A') {
				link.health -= eAttack;
				goblin.stamina -= eAttack;
				link.stamina = link.maxStamina;
				printf("You rest when the enemy hits you, strriking for %d damage\n", eAttack);

			}
			else if (eAction == 'D') {
				link.stamina = link.maxStamina;
				goblin.stamina += goblin.stamina * 0.25;

				printf("You rest while the enemy defend\n");
			}
			else if (eAction == 'R') {
				link.stamina = link.maxStamina;
				goblin.stamina = goblin.maxStamina;
				printf("You both rest, gathering up for  clash\n");
			}
			break;

		case 'P':			//que no superi la vida max
		case 'p':
			if (link.potions == 0) {
				printf("You have no more potions, pobre de mierda\n ");
				break;
			}

			if (eAction == 'A') {
				DrinkPotion(link);
				link.health -= eAttack;
				link.stamina -= eAttack;
				
				eStaminaUsed = (link.maxHealth * 0.4) - eAttack;
				printf("You drink the potion when the enemy hits you, striking %d damage\n", eStaminaUsed);
				break;

			}
			else if (eAction == 'D') {
				DrinkPotion(link);
				goblin.stamina += goblin.stamina * 0.25;
				printf("You drink the potion while the enemy defends\n");
				break;
			}
			else if (eAction == 'R') {
				DrinkPotion(link);
				goblin.stamina = goblin.maxStamina;
				printf("You drink the potion while the enemy rests\n");
				break;
			}
		default:
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
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}

int barres(int primeraBarra, int segonaBarra) {
	int digits;
	digits = (primeraBarra * 10 / segonaBarra);
	printf("[");
	for (int d = digits; d > 0; d--)
		printf("=");
	for (int d = digits; d < 10; d++)
		printf(" ");
	printf("] %d / %d\n", primeraBarra, segonaBarra);
	return 0;
}








