#include <iostream>
#include <vector>
#include <algorithm>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	FIO;
	int A;
	int B;
	int C;
	cin >> A >> B >> C;
	vector <int> v;
	v.push_back(A);
	v.push_back(B);
	v.push_back(C);
	sort(v.begin(), v.end());
	for (auto i : v) {
		cout << i << " ";
	}
}