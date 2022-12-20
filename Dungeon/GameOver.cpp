#include "Header.h"
void PrintGameover(Player& link, bool& isPlaying) {
	system("cls");
	if (link.isAlive)
		cout << "You have win!!" << endl;
	else
		cout << "You have lost!" << endl;
	isPlaying = false;
	system("pause");
}