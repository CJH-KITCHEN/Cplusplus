//21.08.31
//그리디 알고리즘 #5585 거스름돈
//by CJHofficial

#include <iostream>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	FIO;
	int pay = 1000; //지불하는 돈
	int price; //제품 가격
	int count = 0; //거스롬돈 개수
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