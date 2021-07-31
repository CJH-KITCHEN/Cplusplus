#include <iostream>
#include <string>
using namespace std;
namespace CJH {
	void printName() {
		cout << "�й� : 201711430 �̸� : ������" << endl << endl;
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
				cout << (seats[i][j] ? "��" : "��") << '\t';
			}
			cout << "\n\n";
		}
		cout << "�¼� �Է� (ex=> A1, ���� : QQ�Է�) : ";
		char x, y;
		cin >> x >> y;
		if ((x - 'Q' == 0) && (y - 'Q' == 0)) {
			cout << "�¼� ������ �����մϴ�.";
			return 0;
		}
		else if (x < 'A' || x > 'F') {
			cout << "�˼������� �������� �ʴ� �¼��Դϴ�." << endl;
		}
		
		else if (y < '1' || y >'4') {
			cout << "�˼������� �������� �ʴ� �¼��Դϴ�." << endl;
		}

		else if (seats[x - 'A'][y - '1']) {
			cout << "�̹� ����� �ڸ��Դϴ�."<<endl;
		}
		else {
			seats[x - 'A'][y - '1'] = true;
			cout << "������ �Ϸ�Ǿ����ϴ�."<<endl;
		}
		system("pause");
	}
	return 0;
}