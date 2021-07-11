#include <iostream>
#include <utility>

#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)
using namespace std;

typedef long long int Dlint; 

//n은 자연수, 재귀쓰면 시간 초과해서 Linear하게 만듬
pair<Dlint, Dlint> Fib(Dlint n) {
	if (n <= 1) {
		pair<Dlint, Dlint> p = make_pair(n, 0);
		return p;
	}
	else{
		pair<Dlint, Dlint> temp1 = Fib(n - 1);
		pair<Dlint, Dlint> temp2 = make_pair(temp1.first+temp1.second, temp1.first);
		return temp2;
	}
}

int main() {
	FIO;
	Dlint Num;
	cin >> Num;
	cout << Fib(Num).first<<"\n";
}