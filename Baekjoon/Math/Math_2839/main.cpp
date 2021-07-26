//made by CJHofficial
//21.07.18
//설탕 배달;
#include <iostream>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	int N; //가져가야 되는 설탕의 총 무게
	int num5; //5kg 봉지의 개수
	cin >> N;
	if (N % 5 == 3) {
		num5 = N / 5;
		cout << num5 + 1;
	}
	else if (N % 5 == 0) {
		cout << N / 5;
	}
	else if (N % 5 == 1) {
		if ( (N / 5) >= 1) {
			num5 = (N / 5) - 1;
			cout << num5 + 2;
		}
		else {
			cout << -1;
		}
	}
	else if (N % 5 == 2) {
		if ((N / 5) >= 2) {
			num5 = (N / 5) - 2;
			cout << num5 + 4;
		}
		else if (N % 3 == 0) {
			cout << N / 3;
		}
		else {
			cout << -1;
		}
	}
	else if (N % 5 == 4) {
		if ( (N / 5) >= 1) {
			num5 = (N / 5) - 1;
			cout << num5 + 3;
		}
		else {
			cout << -1;
		}
	}
	else if (N % 3 == 0) {
		cout << N / 3;
	}
	else {
		cout << -1;
	}
}