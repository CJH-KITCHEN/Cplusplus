#include <iostream>
#include <string>
using namespace std;
namespace CJH {
	void printName() {
		cout << "학번 : 201711430 이름 : 차준혁" << endl << endl;
	}
}

int main() {
	constexpr int ROW = 6;
	constexpr int COL = 4;
	bool seats[ROW][COL]{};
	while (true) {
		system("cls");
		CJH::printName();
		for (int i = 0; i < COL; i++)
			cout << '\t' << i + 1;
		cout << "\n\n";
		for (int i = 0; i < ROW; i++) {
			cout << static_cast<char>('A' + i) << '\t';
			for (int j = 0; j < COL; j++) {
				cout << (seats[i][j] ? "●" : "○") << '\t';
			}
			cout << "\n\n";
		}
		cout << "좌석 입력 (ex=> A1, 종료 : QQ입력) : ";
		char x, y;
		cin >> x >> y;
		if ((x - 'Q' == 0) && (y - 'Q' == 0)) {
			cout << "좌석 예약을 종료합니다.";
			return 0;
		}
		else if (x < 'A' || x > 'F') {
			cout << "죄송하지만 존재하지 않는 좌석입니다." << endl;
		}
		
		else if (y < '1' || y >'4') {
			cout << "죄송하지만 존재하지 않는 좌석입니다." << endl;
		}

		else if (seats[x - 'A'][y - '1']) {
			cout << "이미 예약된 자리입니다."<<endl;
		}
		else {
			seats[x - 'A'][y - '1'] = true;
			cout << "예약이 완료되었습니다."<<endl;
		}
		system("pause");
	}
	return 0;
}