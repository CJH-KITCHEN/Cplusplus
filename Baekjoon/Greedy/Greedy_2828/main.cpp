//21.09.07
//�׸��� �˰��� #2828 ��� ��� ����
//by CJHofficial;

#include <iostream>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	FIO;
	int N; // ��ũ���� ��ü ũ��
	int M; // �ٱ����� ũ��
	int AppleCount; // �������� ����� ����
	int Mpos = 1; // �ٱ����� ��ġ
	int DropPos; // ����� �������� ĭ
	int Move = 0; //�̵��ؾ� �ϴ� �Ÿ�
	cin >> N >> M;
	cin.clear();
	cin >> AppleCount;
	cin.clear();
	for (int i = 0; i < AppleCount; i++) {
		cin >> DropPos;
		if (Mpos + M - 1 >= DropPos && Mpos <= DropPos) {

		}
		else if (Mpos + M - 1 < DropPos){
			Move += DropPos - (Mpos + M - 1);
			Mpos += DropPos - (Mpos + M - 1);
		}
		else if (Mpos > DropPos) {
			Move += Mpos - DropPos;
			Mpos -= Mpos - DropPos;
		}
	}
	cout << Move;
}