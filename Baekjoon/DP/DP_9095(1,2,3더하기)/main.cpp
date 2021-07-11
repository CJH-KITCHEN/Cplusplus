#include <iostream>
#include <vector>

#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)
using namespace std;

int main() {
	FIO;
	int orderNum;
	int Num;
	cin >> orderNum;
	cin.ignore();
	for (int i = 0; i < orderNum; i++) {
		cin >> Num;
		cin.ignore();
		vector<int> v;
		v.push_back(1); //1일 때 1개
		v.push_back(2); //2일 때 2개
		v.push_back(4); //3일 때 4개
		if (Num >= 1 && Num <= 3) {
			cout << v[Num-1] << "\n";
		}
		else if (Num >= 4) {
			for (int i = 3; i < Num; i++) {
				v.push_back(v[i - 3] + v[i - 2] + v[i - 1]);
			}
			cout << v[Num - 1] << "\n";
		}
	}
}
