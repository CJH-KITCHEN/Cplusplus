#include <iostream>
#include <algorithm>

#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)
using namespace std;

int countMin(int num) {
	if (num == 1) {
		return 0;
	}
	else if (num == 2) {
		return 1;
	}
	int temp = 1 + min(countMin(num / 2) + num % 2, countMin(num / 3) + num % 3);
	return temp;
}


int main() {
	FIO;
	int Num;
	cin >> Num;
	cout << countMin(Num);

}