#include <iostream>
using namespace std;

namespace CJH {
	void printName() {
		cout << "�й� : 201711430 �̸� : ������" << endl << endl;
	}
}

int main() {

	CJH::printName();

	int score[5] = { 10,5,8,20,12 };

	for (int n = 0; n<5; n++) {
		cout << "��ȣ "<< n <<" : ";
		for (int j = 0; j<score[n]; j++) {
				cout << "*";
		}
		cout << endl;
	}

	return 0;
}