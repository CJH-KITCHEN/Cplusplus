//21.09.10
//�׸��� �˰��� #2810 ��Ȧ��
//by CJHofficial;

#include <iostream>
//#include <vector>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;
char c[55];
int main() {
	FIO;
	int N; //�¼��� ��
	cin >> N;
	cin.clear();
	int count = 0;
	cin >> c;
	for (int i = 0; i < N; i++) {
		if (c[i] == 'L') {
			count++; //L�� ����
		}
	}
	count = (count == 0) ? N : N + 1 -count/2;
	/* ���� ���� ó���� Ǭ��
	vector<bool> v;//�¼��� ��Ȧ��
	
	v.assign(N+N+1, false);
	char T;
	int flag = 0;  //LL���� üũ ����
	int count = 0; //���� ��Ȧ���� ���� �� �ִ� �ִ� ����� ��
	for (int i = 0; i < N; i+2) {
		cin >> T;
		i += 1;
		if (flag == 1) {
			flag = 0;
			if (!v[i + 1]) {
				v[i + 1] = true;
				count++;
			}
			continue;
		}
		if (T == 'L') {
			if (flag == 0) {
				v[i + 1] = true;
			}
			flag = 1;
			if (!v[i - 1]) {
				v[i - 1] = true;
				count++;
			}
		}
		else if (T == 'S') {
			if (!v[i - 1]) {
				v[i - 1] = true;
				count++;
			}
			else if (!v[i + 1]) {
				v[i + 1] = true;
				count++;
			}
		}
	}*/
	cout << count;
}	