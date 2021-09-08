//21.09.08
//그리디 알고리즘 #11034 캥거루 세마리 2
//by CJHofficial;

#include <iostream>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	FIO;
	int A;
	int B;
	int C;
	while (1) {
		cin >> A;
		if (cin.eof()) break;
		cin >> B >> C;
		int count = 0;
		while ((B - A > 1) || (C - B > 1)) {
			if (B - A <= C - B) {
				A = B;
				B = C - 1;
				count++;
			}
			else {
				C = B;
				B = A + 1;
				count++;
			}
		}
		cout << count << "\n";
	}

}