#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

namespace CJH {
	void printName() {
		cout << "학번 : 201711430 이름 : 차준혁" << endl << endl;
	}
}
int main(void) {
	CJH::printName();
	int n1, n2, im;
	cout << "구구단의 출력을 원하는 범위를 입력하세요(시작, 끝)  : ";
	cin >> n1 >> n2;
	cout << "\n";

	if (n2 < n1) { 
		cout << "두 번째 입력 숫자가 더 크므로, 시작과 끝의 값을 바꿔서 출력 할까요(y/n)? ";
		char choice;
		cin >> choice;
		if (choice == 'n') {
			return 0;
		}
		im = n2;
		n2 = n1;
		n1 = im;
		cout << "\n";
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = n1; j <=n2; j++) {
			cout << j << " * "<< i << " = " << setw(3) << j * i << "    ";
		}
		cout << endl;
	}
	return 0;								 
}

