//21.08.30
//그리디 알고리즘 #11047 동전 0
//by CJHofficial

#include <iostream>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	FIO;
	int CoinArr[10]; //동전의 가치를 저장할 배열
	int N; // 동전의 종류 개수
	int K; // 만들려고 하는 동전의 총합
	int count = 0; //필요한 동전 개수의 최소값
	cin >> N >> K;
	cin.clear();
	for (int i = 0; i < N; i++) {
		cin >> CoinArr[i];
	}
	
	for (int i = N-1; i >= 0; i--) {
		count += K / CoinArr[i];
		K = K % CoinArr[i];
	}
	
	cout << count;
}