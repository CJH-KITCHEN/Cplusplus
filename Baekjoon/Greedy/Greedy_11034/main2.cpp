//21.09.09
//�׸��� �˰��� #11034 Ļ�ŷ� ������ 2(����)
//by CJHofficial;

#include <iostream>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	FIO;
	int A;
	int B;
	int C;
	while (cin >> A) {
		cin >> B >> C;
		if (B - A <= C - B) {
			cout << C - B - 1 << "\n";
		}
		else {
			cout << B - A - 1 << "\n";
		}
	}

}