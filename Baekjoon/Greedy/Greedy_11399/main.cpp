//21.08.30
//�׸��� �˰��� #11399 ATM
//by CJHofficial

#include <iostream>
#include <vector>
#include <algorithm>

#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	int N;  //����� ��
	vector <int> v;  //��� �� �����
	int sum = 0; //�ʿ��� �ð��� ���� �ּҰ�
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