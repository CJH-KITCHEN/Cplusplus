//21.09.04
//#1436 ��ȭ���� ��
//by CJHofficial

#include <iostream>
#include <string>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	FIO;
	int N; // N��° ��ȭ
	cin >> N;
	int i = 1;
	int flag = 0;
	while (1) {
		i++;
		string s = to_string(i);
		if (s.find("666") != string::npos) {
			flag++;
		}
		if (flag == N) {
			cout << i;
			break;
		}
	}
}