#include "Header.h"
void PrintGameover(Player& link, bool& isPlaying) {
	system("cls");
	if (link.isAlive)
	{
		printf("---- Princess Eduina ----\n");
		printf("\n  my hero!\n");
		printf("     _____         ____   \n");
		printf("    || UwU|   <3  |UwU |     \n");
		printf("    ||  ) )       |  __|      \n");
		printf("     |    |      || |   |  \n");
		printf("    (_____|      ||_|___|      \n");
		printf("      |  |        _|  _|     \n\n");
		printf("You have WIN Eduina's heart! Congratulations!\n > You have %d Gold\n\n", link.gold);
	}
	else
	{
		printf("---- Princess Eduina ----\n");
		printf("\n  I dont come out with losers\n");
		printf("      _____         ____   \n");
		printf("     |-.- ||       |T.T |     \n");
		printf("    ( (   ||       |  __|      \n");
		printf("     |    |       || |   |  \n");
		printf("     |_____)      ||_|___|      \n");
		printf("      |  |        _|  _|     \n\n");
		cout << "You have LOST Eduina's heart! You're a LOSEEEER!\n" << endl;
	}
	link.isAlive = true;

	system("pause");
	system("cls");
}