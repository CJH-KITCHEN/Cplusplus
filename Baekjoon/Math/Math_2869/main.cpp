//made by CJHofficial
//21.07.18
//���ؾ��� �ö󰡰� �ʹ�;
#include <iostream>
#include <cmath>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	double A; //���ؾ��� ���� �ö󰡴� ����
	double B; //���ؾ��� �㿡 �̲������� ����
	double V; //���� ������ ����
	double day; //���ؾ��� �ö󰡴� �Ⱓ
	cin >> A >> B >> V;
	//(A-B) * day + A  > V
	day = ceil((V - A) / (A - B));
	cout << int(day + 1);
}