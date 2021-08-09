//21.08.09
//분할 정복 #2630 색종이 만들기
//by CJHofficial

#include <iostream>
#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int paper[128][128];
int Blue = 0;
int White = 0;

void makeCP(int rowStart, int colStart, int size) {
	int check = paper[rowStart][colStart];
	for (int i = rowStart ; i < rowStart + size; i++) {
		for (int j = colStart ; j < colStart + size; j++) {
			if (check != paper[i][j]) {
				makeCP(rowStart, colStart, size / 2);
				makeCP(rowStart + size / 2, colStart, size / 2);
				makeCP(rowStart, colStart + size / 2, size / 2);
				makeCP(rowStart + size / 2, colStart + size / 2, size / 2);
				return;
			}
		}
	}
	if (paper[rowStart][colStart]) {
		Blue += 1;
	}
	else {
		White += 1;
	}
}

int main() {
	FIO;
	int N; ///전체 종이의 한 변의 길이
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
		cin.clear();
	}

	makeCP(0, 0, N);

	cout << White << "\n" << Blue;
}