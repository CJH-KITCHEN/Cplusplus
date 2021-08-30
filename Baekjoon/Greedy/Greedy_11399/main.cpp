//21.08.30
//그리디 알고리즘 #11399 ATM
//by CJHofficial

#include <iostream>
#include <vector>
#include <algorithm>

#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	int N;  //사람의 수
	vector <int> v;  //사람 줄 세우기
	int sum = 0; //필요한 시간의 합의 최소값
	cin >> N;
	cin.clear();
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			sum += v[j];
		}
		sum += v[i];
	}

	cout << sum;
}