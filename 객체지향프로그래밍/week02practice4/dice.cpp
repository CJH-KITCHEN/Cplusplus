#include <iostream>
#include <ctime>
using namespace std;

namespace CJH {
	void printName() {
		cout << "�й� : 201711430 �̸� : ������" << endl << endl;
	}
}

int main() {
	CJH::printName();

	constexpr int SIZE = 6;
	constexpr int TRY = 10000;

	int dice[SIZE] = {};
	srand((unsigned)time(NULL));
	cout << "==========================" << endl;
	cout << "     �ֻ��� ���� �󵵼�   " << endl;
	cout << "==========================" << endl;
	for (int i = 0; i < TRY; i++) {
		int dicenum = (rand() % SIZE) + 1;
		dice[dicenum - 1]++;
	}
	for(int j = 0; j<SIZE; j++){
		cout << j + 1 << "�� �󵵼� : �� " << dice[j] << "�� " << endl;
	}
	
	return 0;
}