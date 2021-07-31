#include <iostream>
#include "Dice.h"
#include "Player.h"
#include <ctime>
using namespace std;
namespace CJH {
	void printName() {
		cout << "ÇÐ¹ø : 201711430 ÀÌ¸§ : Â÷ÁØÇõ" << endl << endl;
	}
}

int main() {
	CJH::printName();
	srand((unsigned)time(NULL));
	Dice dice1, dice2;
	Player player1("È«±æµ¿"), player2("±è±æµ¿");
	player1.roll(dice1, dice2);
	player2.roll(dice1, dice2);
	if (player1.getTotal() > player2.getTotal()) {
		cout << player1.getName() << "´Ô ½Â¸® ==> Á¡¼ö (" <<
			player1.getTotal() << "," << player2.getTotal() << ")" << endl;
	}
	else if (player1.getTotal() < player2.getTotal()) {
		cout << player2.getName() << "´Ô ½Â¸® ==> Á¡¼ö (" <<
			player1.getTotal() << "," << player2.getTotal() << ")" << endl;
	}
	else {
		cout << "¹«½ÂºÎ ==> Á¡¼ö (" <<
			player1.getTotal() << "," << player2.getTotal() << ")" << endl;
	}
	return 0;
}