//21.09.01
//�׸��� �˰��� #10162 ���ڷ�����
//by CJHofficial

#include <iostream>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	FIO;
	int T; //�丮�ؾ��� �ð� T
	int A; //300��
	int B; //60��
	int C; //10��

	cin >> T;

	A = T / 300;
	T = T % 300;

	B = T / 60;
	T = T % 60;

	C = T / 10;
	T = T % 10;

	if (T != 0) {
		cout << -1;
	}
	else {
		cout << A << " " << B << " " << C;
	}
}