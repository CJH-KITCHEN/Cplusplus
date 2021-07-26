//made by CJHofficial
//21.07.18
//달팽쓰는 올라가고 싶다;
#include <iostream>
#include <cmath>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	double A; //달팽쓰가 낮에 올라가는 높이
	double B; //달팽쓰가 밤에 미끄러지는 높이
	double V; //나무 막대의 높이
	double day; //달팽쓰가 올라가는 기간
	cin >> A >> B >> V;
	//(A-B) * day + A  > V
	day = ceil((V - A) / (A - B));
	cout << int(day + 1);
}