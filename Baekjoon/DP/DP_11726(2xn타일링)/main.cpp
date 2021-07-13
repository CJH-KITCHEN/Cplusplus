//21.07.13
//made by CJHofficial;

#include <iostream>
#include <utility>

#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

typedef long long int DLint;

using namespace std;

pair<DLint, DLint> Fib(int n) {
	if (n == 0) {
		pair<DLint, DLint> p = make_pair(1, 0);
		return p;
	}
	else {
		pair<DLint, DLint> temp1 = Fib(n - 1);
		pair<DLint, DLint> temp2 = make_pair((temp1.first + temp1.second)%10007, temp1.first%10007);
		return temp2;
	}
}

int main() {
	FIO;
	int Num;
	cin >> Num;
	cout << Fib(Num).first;
}