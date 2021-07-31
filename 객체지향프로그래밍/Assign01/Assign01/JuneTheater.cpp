#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using std::cout;
using namespace std;

namespace CJH {
	void printName() {
		cout << "학번 : 201711430 이름 : 차준혁" << endl << endl;
	}
}

struct MovieData {
	string MovieName;
	int row, col, soldoutnum;
};

struct MovieData* TheaterSize(int& MovieNum) {
	ifstream fin("moviedata.txt");
	if (!fin.is_open()) {
		cerr << "파일 오픈 실패";
		exit(0);
	}
	fin >> MovieNum;
	MovieData* md = new MovieData[MovieNum];
	//delete[] ms; 요고 체크
	while (!fin.eof()) {
		for (int i = 0; i < MovieNum; i++) {
			fin >> md[i].MovieName;
			fin >> md[i].row;
			fin >> md[i].col;
			md[i].soldoutnum = 0;//예약수 초기화
		}
	}
	return md;
}

bool*** loadSeats(struct MovieData*& md, int &MovieNum) {
	bool*** seats = new bool** [MovieNum];
	for (int i = 0; i < MovieNum; i++) {
		seats[i] = new bool*[md[i].row];
		for (int j = 0; j < md[i].row; j++) {
			seats[i][j] = new bool[md[i].col];
		}
	}
	//delete해야됨

	for (int n = 0; n < MovieNum; n++) {
		for (int i = 0; i < md[n].row; i++) {
			for (int j = 0; j < md[n].col; j++) {
				seats[n][i][j] = 0;
			}
		}
	}
	return seats;
}


int *reservNum(struct MovieData*& md, const int MovieNum, const int row, const int col) {
	int ArrSize = 0;
	for (int i = 0; i < MovieNum ; i++) {
		ArrSize += (md[i].row) * (md[i].col);
	}
	int* reservNum = new int[ArrSize];
	//delete 해줘야됨
	return reservNum;
}

void showSeats(bool*** seats, const int row, const int col, int select) {
	for (int i = 0; i < col; i++)
		cout << '\t' << i + 1;
	cout << "\n\n";
	for (int i = 0; i < row; i++) {
		cout << static_cast<char>('A' + i) << '\t';
		for (int j = 0; j < col; j++) {
			cout << (seats[select][i][j] ? "●" : "○") << '\t';
		}
		cout << endl;
	}
}

void reserveSeats(bool ***seats, const int row, const int col, int select) {
	char x, y;
	cin >> x >> y;
	if ((x - 'Q' == 0) && (y - 'Q' == 0)) {
		cout << "좌석 예약을 종료합니다.";
	}
	else if (x < 'A' || x > 'F') {
		cout << "죄송하지만 존재하지 않는 좌석입니다." << endl;
	}

	else if (y < '1' || y >'4') {
		cout << "죄송하지만 존재하지 않는 좌석입니다." << endl;
	}

	else if (seats[select][x - 'A'][y - '1']) {
		cout << "이미 예약된 자리입니다." << endl;
	}
	else {
		seats[select][x - 'A'][y - '1'] = true;
		cout << "예약이 완료되었습니다." << endl;
	}
}

int main() {
	CJH::printName();
	int menuNum, MovieNum;
	struct MovieData* md= TheaterSize(MovieNum);
	bool*** seats = loadSeats(md, MovieNum);
	
	//cout << md[0].MovieName << md[0].row << md[0].col;

	do {
		cout << "================차준혁 시네마================="<<endl;
		cout << "1) 영화 예매 2) 예매 취소 3) 예매 확인 4) 종료"<<endl;
		cout << "메뉴를 선택하세요 : ";
		cin >> menuNum;
		switch (menuNum) {
			case 1:
				int select;
				cout << "=================영화 예매==================\n";
				for (int i = 0; i < MovieNum; i++) {
					cout << left << (i + 1) << left << ") " << left << md[i].MovieName << '\t';
					cout << md[i].soldoutnum << right << "/" << right << (md[i].row) * (md[i].col) << endl;
				}
				cout << "예매할 영화를 선택하세요 : ";
				cin >> select;
				showSeats(seats, md[select - 1].row, md[select - 1].col, select - 1);
				cout << "예매할 좌석을 선택하세요(ex) A 1, B 2) : ";
				reserveSeats(seats, md[select - 1].row, md[select - 1].col, select);
				
			break;
			case 2:

			break;
			case 3:

			break;

			case 4:
			
			break;
		}
		cout << "\n";
	} while (menuNum != 4);
	cout << "예매 프로그램을 종료합니다. 안녕히 가세요 ^.^\n";
}