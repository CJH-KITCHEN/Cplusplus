#include <iostream>
#include <vector>

#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	int Num;
	int Max = 0;
	int tempM = 0;
	vector <int> NumList;
	vector <int> Dp;
	cin >> Num;
	cin.clear();
	for (int i = 0; i < Num; i++) {
		int temp;
		cin >> temp;
		NumList.push_back(temp);
	}
	NumList.swap();
	/*
	O(n^2)¿œµÌ
	Dp.assign(Num, 1);
	for (int i = 0; i < Num; i++) {           
		for (int j = 0; j < i; j++) {
			if (NumList[j] > NumList[i]) {
				if (tempM <= Dp[j]) {
					Dp[i] = Dp[j] + 1;
					tempM = Dp[j];
				}
			}
		}
		tempM = 0;
		if (Max < Dp[i]) {
			Max = Dp[i];
		}
	}
	cout << Max;*/
}