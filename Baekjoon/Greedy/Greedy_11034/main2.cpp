//21.09.09
//그리디 알고리즘 #11034 캥거루 세마리 2(수정)
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