//	#2609 최대공약수와 최소공배수
//	21.07.12 by CJHofficial
#include <iostream>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	int A;
	int B;
	int originA;
	int originB;
	int rest = -1;
	cin >> A;
	cin >> B;
	if (A < B) {
		int temp;
		temp = A;
		A = B;
		B = temp;
	}
	originA = A;
	originB = B;
	while(rest != 0) {
		rest = A % B;
		A = B;
		B = rest;
	}
	if (rest == 0) {
		cout << A << "\n";
	}
	cout << (originA / A) * (originB / A) * A; //최소 공배수
	
}