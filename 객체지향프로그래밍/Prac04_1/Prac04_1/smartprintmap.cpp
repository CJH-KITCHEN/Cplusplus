#include <iostream>
#include <string>
#include <fstream>
#include <memory>

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

shared_ptr<shared_ptr<int[]>[]> loadMap(int& row, int& col) {


	ifstream fin("testmap.txt");
	if (!fin.is_open()) {
		cerr << "파일 오픈 실패";
		exit(0);
	}
	fin >> row >> col;
	shared_ptr<shared_ptr<int[]>[]>map(new shared_ptr<int[]>[row]);
	for (int i = 0; i < row; i++) {
		map[i]=shared_ptr<int[]>(new int[col]);
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

void showMap(shared_ptr<shared_ptr<int[]>[]>(&map), const int row, const int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << (map[i][j] == 0 ? "○" : "●");
		}
		cout << endl;
	}
}

/*void deleteMap(shared_ptr<shared_ptr<int[]>[]>(&map)) {
	map.reset();
}*/

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CJH::printName();
	int row, col;
	auto map = loadMap(row, col);
	if (map != nullptr) {
		showMap(map, row, col);
		//deleteMap(map);
	}

	return 0;
}