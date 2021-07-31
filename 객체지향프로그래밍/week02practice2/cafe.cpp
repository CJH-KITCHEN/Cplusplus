#include <iostream>
using namespace std;

namespace CJH {
	void printName() {
		cout << "학번 : 201711430 이름 : 차준혁" << endl << endl;
	}
}

int main() {

	CJH::printName();

	int select;
	int ame = 0, latte = 0;
	do {
		cout << "1) 아메리카노(100원) 2)카페라떼(200원) 3)결제 4)종료\n";
		cout << "선택하세요 : ";
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "아메리카노를 주문하셨습니다.\n\n";
			ame++;
			break;
		case 2:
			cout << "카페라떼를 주문하셨습니다.\n\n";
			latte++;
			break;
		case 3:
			cout << "==================\n결제금액\n==================\n";
			cout << "아메리카노 " << ame << "잔 " << ame * 100 << "원" << endl;
			cout << "카페라떼 " << latte << "잔 " << latte * 200 << "원" << endl;
			cout << "==================\n총 " << (ame * 100) + (latte * 200) << "원\n==================\n\n";
			cout << "결제가 완료되었습니다.\n\n";
			ame = 0, latte = 0;
			break;
		}
	} while (select != 4);

	return 0;
}