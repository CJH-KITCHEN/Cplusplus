#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

namespace CJH {
	void printName() {
		cout << "�й� : 201711430 �̸� : ������" << endl << endl;
	}
}
int main(void) {
	CJH::printName();
	int n1, n2, im;
	cout << "�������� ����� ���ϴ� ������ �Է��ϼ���(����, ��)  : ";
	cin >> n1 >> n2;
	cout << "\n";

	if (n2 < n1) { 
		cout << "�� ��° �Է� ���ڰ� �� ũ�Ƿ�, ���۰� ���� ���� �ٲ㼭 ��� �ұ��(y/n)? ";
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

