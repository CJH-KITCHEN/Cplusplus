#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void setCursorView(bool visible) {
	CONSOLE_CURSOR_INFO cursor = { 1, visible };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void gotoxy(int x, int y) {
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main() {
	int x = 10;
	int y = 10;
	//while (true) {
	gotoxy(x, y);
	setCursorView(false);
	//	cout << _getch() << endl;
	//}
	while (true) {
		if (_kbhit()) {
			int keycode = _getch();
			if (keycode == 224) {
				//system("cls");
				keycode = _getch();
				switch (keycode){
				case 75: x -= 2; break;
				case 77: x += 2; break;
				case 72: y -= 1; break;
				case 80: y += 1; break;
				}
				gotoxy(x, y);
				cout << "бс";
			}
		}
	}
}