#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using std::cout;
using namespace std;

//메모리 누수 체크!
/*#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif*/

namespace CJH {
	void printName() {
		cout << "학번 : 201711430 이름 : 차준혁" << endl << endl;
	}
}

struct MovieData {
	string MovieName;
	int row, col, availableNum;
};//영화 정보 구조체틀

struct MovieData* TheaterSize(int& MovieNum) {
	ifstream fin("moviedata.txt");
	if (!fin.is_open()) {
		cerr << "파일 오픈 실패";
		exit(0);
	}
	fin >> MovieNum;
	MovieData* md = new MovieData[MovieNum];
	//delete 체크
	while (!fin.eof()) {
		for (int i = 0; i < MovieNum; i++) {
			fin >> md[i].MovieName;
			fin >> md[i].row;
			fin >> md[i].col;
			md[i].availableNum = (md[i].row)*(md[i].col);//예약 가능한 좌석 수 초기화
		}
	}
	return md;
}

void deleteMovieData(struct MovieData* (&md)) {
	delete[]md;
	md = nullptr;
}

bool*** loadSeats(struct MovieData* (&md), int& MovieNum) {
	bool*** seats = new bool** [MovieNum];
	for (int i = 0; i < MovieNum; i++) {
		seats[i] = new bool* [md[i].row];
		for (int j = 0; j < md[i].row; j++) {
			seats[i][j] = new bool[md[i].col];
		}
	}
	//delete해야됨

	for (int n = 0; n < MovieNum; n++) {
		for (int i = 0; i < md[n].row; i++) {
			for (int j = 0; j < md[n].col; j++) {
				seats[n][i][j] = false;
			}
		}
	}
	return seats;
}

void deleteSeats(struct MovieData* (&md), bool*** (&seats), const int MovieNum) {
	for (int i = 0; i < MovieNum; i++) {
		for (int j = 0; j < md[i].row; j++)
			delete[] seats[i][j];
		delete[] seats[i];
	}
	delete[] seats;
	seats = nullptr;
}

void showMovieList(struct MovieData* (&md), int &select, const int MovieNum) {
	cout << "\n=================영화 예매==================\n";
	for (int i = 0; i < MovieNum; i++) {
		string name = md[i].MovieName;
		int namelen =(38 - name.length());
		cout << (i + 1) << ") " << md[i].MovieName;
		if (md[i].availableNum == 0) {
			cout << setfill(' ') << setw(namelen+3);
			cout << "매진" << endl;
		}
		else {
			cout << setfill(' ') << setw(namelen);
			cout << md[i].availableNum << "/" << (md[i].row) * (md[i].col) << endl;
		}
	}
	cout << endl << "예매할 영화를 선택하세요 : ";
	cin >> select;
}

void showSeats(bool*** (&seats), const int row, const int col, int select) {
	cout << endl;
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

void reserveSeats(struct MovieData* (&md), bool*** (&seats), int select) {
	cout << "\n예매할 좌석을 선택하세요(ex) A 1, B 2) : ";
	char x, y;
	cin >> x >> y;
	char MDRow, MDCol;//영화관 좌석의 행과 열을 뜻함
	MDRow = static_cast<char>('A' + (md[select].row) - 1);
	MDCol = static_cast<char>('1' + (md[select].col) - 1);
	if (x < 'A' || x > MDRow) {
		cout << "\n죄송하지만 존재하지 않는 좌석입니다." << endl;
	}

	else if (y < '1' || y > MDCol) {
		cout << "\n죄송하지만 존재하지 않는 좌석입니다." << endl;
	}

	else if (seats[select][x - 'A'][y - '1']) {
		cout << "\n이미 예약된 자리입니다." << endl;
	}
	else {
		seats[select][x - 'A'][y - '1'] = true;
		(md[select].availableNum)--;
		cout << "\n예약이 완료되었습니다." << endl;
		cout << "예약번호는 " << static_cast<char>(select + 'A');
		cout << static_cast<char>(x - 'A' + 'C');
		cout << static_cast<char>(y - '1' + 'D') << " 입니다." << endl;
	}
}

void cancelSeats(struct MovieData* (&md), bool*** (&seats)) {
	char c1, c2, c3;
	cout << "취소할 영화의 예약번호를 입력해주세요(ex) 예약번호가 AEF라면 입력: AEF): ";
	cin >> c1 >> c2 >> c3;
	int dNum1 = static_cast<int>(c1 - 'A');
	int dNum2 = static_cast<int>(c2 - 'C');
	int dNum3 = static_cast<int>(c3 - 'D');

	if (seats[dNum1][dNum2][dNum3]) {
		seats[dNum1][dNum2][dNum3] = 0;
		(md[dNum1].availableNum)++;
		cout << "\n예매가 취소되었습니다." << endl;
	}
	else {
		cout << "\n예약번호가 존재하지 않습니다." << endl;
	}
}

void checkSeats(struct MovieData* (&md), bool*** (&seats)) {
	char c1, c2, c3;
	cout << "\n=================예약 확인==================\n";
	cout << "예약번호를 입력하세요(ex) 예약번호가 AEF라면 입력: AEF): ";
	cin >> c1 >> c2 >> c3;
	int searchNum1 = static_cast<int>(c1 - 'A');
	int searchNum2 = static_cast<int>(c2 - 'C');
	int searchNum3 = static_cast<int>(c3 - 'D');
	if (seats[searchNum1][searchNum2][searchNum3]) {
		cout << "예매하신 영화 : " << md[searchNum1].MovieName << endl;
		cout << "예매하신 좌석 : " << static_cast<char>(searchNum2  + 'A') << (searchNum3 + 1) << endl;
		cout << "\n=====================영화 예매 좌석====================\n";
		cout << endl;
		for (int i = 0; i < md[searchNum1].col; i++)
			cout << '\t' << i + 1;
		cout << "\n\n";
		for (int i = 0; i < md[searchNum1].row; i++) {
			cout << static_cast<char>('A' + i) << '\t';
			for (int j = 0; j < md[searchNum1].col; j++) {
				cout << ( ( (i== searchNum2)&&(j==searchNum3) )? "☆" : "○") << '\t';
			}
			cout << endl;
		}
		system("pause");
	}
	else {
		cout << "\n예약번호가 존재하지 않습니다." << endl;
	}

}

int main() {
	//메모리 누수 체크!
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int menuNum, MovieNum;
	struct MovieData* md = TheaterSize(MovieNum);
	bool*** seats = loadSeats(md, MovieNum);

	do {
		CJH::printName();
		cout << "================차준혁 시네마=================" << endl;
		cout << "1) 영화 예매 2) 예매 취소 3) 예매 확인 4) 종료" << endl;
		cout << "\n메뉴를 선택하세요 : ";
		cin >> menuNum;
		switch (menuNum) {
		case 1:
			int select;
			showMovieList(md, select, MovieNum);
			showSeats(seats, md[select - 1].row, md[select - 1].col, select - 1);
			reserveSeats(md, seats, select - 1);
			break;
		case 2:
			cancelSeats(md, seats);
			break;
		case 3:
			checkSeats(md, seats);
			break;

		case 4:
			deleteSeats(md, seats, MovieNum);
			deleteMovieData(md);
			break;
		default:
			cout << "잘못 입력하셨습니다.\n";
			break;
		}
		cout << "\n";
	} while (menuNum != 4);
	cout << "예매 프로그램을 종료합니다. 안녕히 가세요 ^.^\n";
}