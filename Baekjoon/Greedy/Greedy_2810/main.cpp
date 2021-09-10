//21.09.10
//그리디 알고리즘 #2810 컵홀더
//by CJHofficial;

#include <iostream>
//#include <vector>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;
char c[55];
int main() {
	FIO;
	int N; //좌석의 수
	cin >> N;
	cin.clear();
	int count = 0;
	cin >> c;
	for (int i = 0; i < N; i++) {
		if (c[i] == 'L') {
			count++; //L의 개수
		}
	}
	count = (count == 0) ? N : N + 1 -count/2;
	/* 요고는 내가 처음에 푼거
	vector<bool> v;//좌석과 컵홀더
	
	v.assign(N+N+1, false);
	char T;
	int flag = 0;  //LL연속 체크 기준
	int count = 0; //컵을 컵홀더에 놓을 수 있는 최대 사람의 수
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