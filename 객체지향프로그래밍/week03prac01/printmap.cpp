#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

namespace CJH {
	void printName() {
		cout << "학번 : 201711430 이름 : 차준혁" << endl << endl;
	}
}

int** loadMap(int& row, int& col){

	CJH::printName();

	ifstream fin("testdata.txt");
	if (!fin.is_open()) {
		cerr << "파일 오픈 실패";
		exit(0);
	}
	fin >> row >> col;
	int** map = new int* [row];
	for (int i = 0; i < row; i++) {
		map[i] = new int[col];
	}
	while (!fin.eof()) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				fin >> map[i][j];
			}
		}
	}
	return map;
}

void showMap(int** (&map), const int row, const int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << (map[i][j] == 0 ? "○" : "●");
		}
		cout << endl;
	}
}

void deleteMap(int** (&map), const int row) {
	for (int i = 0; i < row; i++) {
		delete[] map[i];
	}
	delete[] map;
	map = nullptr;
}


int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int row, col;
	int** map = loadMap(row, col);
	if (map != nullptr) {
		showMap(map, row, col);
		deleteMap(map, row);
	}

	return 0;
}