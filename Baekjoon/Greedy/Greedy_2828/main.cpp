//21.09.07
//그리디 알고리즘 #2828 사과 담기 게임
//by CJHofficial;

#include <iostream>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	FIO;
	int N; // 스크린의 전체 크기
	int M; // 바구니의 크기
	int AppleCount; // 떨어지는 사과의 개수
	int Mpos = 1; // 바구니의 위치
	int DropPos; // 사과가 떨어지는 칸
	int Move = 0; //이동해야 하는 거리
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