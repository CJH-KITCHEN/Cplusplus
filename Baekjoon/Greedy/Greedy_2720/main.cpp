//21.09.03
//�׸��� �˰��� #2720 ��Ź�� ���� ����
//by CJHofficial

#include <iostream>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	FIO;
	int T; //�׽�Ʈ ���̽��� ����
	int C; //�Ž�������
	cin >> T;
	cin.clear();
	for (int i = 0; i < T; i++) {
		cin >> C;
		cout << C / 25 << " ";
		C = C % 25;
		cout << C / 10 << " ";
		C = C % 10;
		cout << C / 5 << " ";
		C = C % 5;
		cout << C << "\n";
	}
}