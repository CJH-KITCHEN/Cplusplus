//21.08.31
//�׸��� �˰��� #5585 �Ž�����
//by CJHofficial

#include <iostream>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	FIO;
	int pay = 1000; //�����ϴ� ��
	int price; //��ǰ ����
	int count = 0; //�Ž��ҵ� ����
	cin >> price;
	int change = pay - price;
		count += change / 500;
		change = change % 500;
		count += change / 100;
		change = change % 100;
		count += change / 50;
		change = change % 50;
		count += change / 10;
		change = change % 10;
		count += change / 5;
		change = change % 5;
		count += change / 1;
	cout << count;
}