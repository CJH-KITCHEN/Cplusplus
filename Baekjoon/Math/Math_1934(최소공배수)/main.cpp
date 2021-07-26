#include <iostream>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	int testNum;
	int A;
	int B;
	int originA;
	int originB;
	int rest = -1;

	cin >> testNum;
	cin.clear();
	for (int i = 0; i < testNum; i++) {
		cin >> A;
		cin >> B;
		if (B > A) {
			int temp;
			temp = A;
			A = B;
			B = temp;
		}
		originA = A;
		originB = B;
		while (rest != 0) {
			rest = A % B;
			A = B;
			B = rest;
		}
		if (rest == 0) {
			cout << A * (originA / A) * (originB / A) << "\n";
		}
		rest = -1;
	}
}