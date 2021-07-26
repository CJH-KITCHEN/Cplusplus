#include <iostream>

#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

typedef long long int DLint;

int main() {
	DLint A;
	DLint B;
	DLint rest = -1;
	cin >> A;
	cin >> B;

	if (A < B) {
		DLint temp = A;
		A = B;
		B = temp;
	}
	while (rest != 0) {
			rest = A % B;
			A = B;
			B = rest;
	}
	if (rest == 0) {
		for (DLint i = 0; i < A; i++) {
			cout << "1";
		}
	}
}