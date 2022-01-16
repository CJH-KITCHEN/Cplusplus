//22.01.16 
//#17390 이건 꼭 풀어야 해!
//by CJHofficial

#include <iostream>
#include <vector>
#include <algorithm>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)
using namespace std;

int main() {
	FIO;
	int N, Q;
	int temp, left, right;
	vector <int> v;
 	cin >> N >> Q;
	v.push_back(0);
	for (int i = 1; i < N + 1; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < N + 1; i++) {
		v[i] += v[i - 1];
	}
	while (Q--) {
		cin >> left >> right;
		cout << v[right] - v[left - 1] << "\n";
	}

}