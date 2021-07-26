#include <iostream>
#include <list>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	list <int> v;
	int N;
	int temp;
	cin >> N;
	cin.clear();
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	v.sort();
	v.unique();
	for (auto i : v) {
		cout << i << "\n";
	}
}