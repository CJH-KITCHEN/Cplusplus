#include <iostream>
#include <ctime>
using namespace std;

namespace CJH {
	void printName() {
		cout << "ÇÐ¹ø : 201711430 ÀÌ¸§ : Â÷ÁØÇõ" << endl << endl;
	}
}

int main() {
	CJH::printName();

	constexpr int SIZE = 6;
	constexpr int TRY = 10000;

	int dice[SIZE] = {};
	srand((unsigned)time(NULL));
	cout << "==========================" << endl;
	cout << "     ÁÖ»çÀ§ ¸éÀÇ ºóµµ¼ö   " << endl;
	cout << "==========================" << endl;
	for (int i = 0; i < TRY; i++) {
		int dicenum = (rand() % SIZE) + 1;
		dice[dicenum - 1]++;
	}
	for(int j = 0; j<SIZE; j++){
		cout << j + 1 << "ÀÇ ºóµµ¼ö : ÃÑ " << dice[j] << "°³ " << endl;
	}
	
	return 0;
}