//21.09.01
//그리디 알고리즘 #10162 전자레인지
//by CJHofficial

#include <iostream>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	FIO;
	int T; //요리해야할 시간 T
	int A; //300초
	int B; //60초
	int C; //10초

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