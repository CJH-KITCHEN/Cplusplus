//21.08.30
//�׸��� �˰��� #11047 ���� 0
//by CJHofficial

#include <iostream>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	FIO;
	int CoinArr[10]; //������ ��ġ�� ������ �迭
	int N; // ������ ���� ����
	int K; // ������� �ϴ� ������ ����
	int count = 0; //�ʿ��� ���� ������ �ּҰ�
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