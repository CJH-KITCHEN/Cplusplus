#include "MovieManager.h"
#include <iomanip>
namespace CJH {
	void printName() {
		cout << "학번 : 201711430 이름 : 차준혁" << endl << endl;
	}
}

MovieManager::MovieManager(string fileloc):fileloc(fileloc)
{
	cout << "MovieManager 생성자" << endl;
	this->menuNum = -1;
	this->MovieNum = -1;
	ifstream fin(fileloc);
	if (!fin.is_open()) {
		cerr << "파일 오픈 실패";
		exit(0);
	}
	fin >> (this->MovieNum);
	if ((this->MovieNum) > 0) {
		this->movie = new Movie * [this->MovieNum];
		while (!fin.eof()) {
			for (int i = 0; i < (this->MovieNum); i++) {
				string mname;
				int row, col;
				fin >> mname;
				fin >> row;
				fin >> col;
				movie[i] = new Movie(i, mname, row, col); //Movie객체 동적 생성
				//cout << "Movie객체 동적 생성" << endl;
			}
		}
	}
	else {
		movie = nullptr;
	}
}

MovieManager::~MovieManager()
{
	cout << "MovieManager 소멸자" << endl;
	if (movie != nullptr) {
		for (int i = 0; i < (this->MovieNum); i++) {
			delete movie[i];
			//cout << "delete Movie객체" << endl;
		}
		delete[] movie;
		//cout << "delete Movie객체의 포인터 배열" << endl;
	}
	movie = nullptr;
}

MovieManager::MovieManager(const MovieManager& moviemanager)
	:fileloc(moviemanager.fileloc),MovieNum(moviemanager.MovieNum), menuNum(moviemanager.menuNum)
{
	cout << "MovieManager 복사생성자" << endl;
	if ((moviemanager.MovieNum) > 0) {
		this->movie = new Movie * [moviemanager.MovieNum];
			for (int i = 0; i < (moviemanager.MovieNum); i++) {
				movie[i] = new Movie(*(moviemanager.movie[i])); //Movie객체 복사 생성자
				//cout << "Movie객체 동적 생성" << endl;
			}
	}
	else {
		movie = nullptr;
	}
}

MovieManager::MovieManager(MovieManager&& moviemanager) noexcept 
	:fileloc(moviemanager.fileloc),MovieNum(moviemanager.MovieNum), menuNum(moviemanager.menuNum)
{	
	cout << "MovieManager 이동생성자" << endl;
	this->movie = moviemanager.movie;
	moviemanager.movie = nullptr;
}

void MovieManager::startMenu()
{
	if (this->movie != nullptr) {
		do {
			CJH::printName();
			cout << "================차준혁 시네마=================" << endl;
			cout << "1) 영화 예매 2) 예매 취소 3) 예매 확인 4) 종료" << endl;
			cout << "\n메뉴를 선택하세요 : ";
			cin >> this->menuNum;
			switch (this->menuNum) {
			case 1:
				reserveMovie();
				break;
			case 2:
				cancelMovie();
				break;
			case 3:
				checkMovie();
				break;

			case 4:
				cout << "\n예매 프로그램을 종료합니다. 안녕히 가세요 ^.^\n";
				break;
			default:
				cout << "잘못 입력하셨습니다.\n";
				break;
			}
			cout << "\n";
		} while (this->menuNum != 4);
	}
}

void MovieManager::reserveMovie()
{
	int select;
	cout << "\n=================영화 예매==================\n";
	for (int i = 0; i < MovieNum; i++) {
		movie[i]->showMovieData();
	}
	cout << endl << "예매할 영화를 선택하세요 : ";
	cin >> select;
	movie[select - 1]->showSeats();
	movie[select - 1]->reserveSeats();
}

void MovieManager::cancelMovie()
{
	char c1, c2, c3;
	cout << "취소할 영화의 예약번호를 입력해주세요(ex) 예약번호가 AEF라면 입력: AEF): ";
	cin >> c1 >> c2 >> c3;
	int dNum1 = static_cast<int>(c1 - 'A');
	if (dNum1 <0 || dNum1>(this->MovieNum)-1) {
		cout << "\n예약번호가 존재하지 않습니다." << endl;
	}
	else {
		movie[dNum1]->cancelSeats(c2, c3);
	}
}

void MovieManager::checkMovie()
{
	char c1, c2, c3;
	cout << "\n=================예약 확인==================\n";
	cout << "예약번호를 입력하세요(ex) 예약번호가 AEF라면 입력: AEF): ";
	cin >> c1 >> c2 >> c3;
	int searchNum1 = static_cast<int>(c1 - 'A');
	if (searchNum1 <0 || searchNum1>(this->MovieNum) - 1) {
		cout << "\n예약번호가 존재하지 않습니다." << endl;
	}
	else {
		movie[searchNum1]->checkSeats(c2, c3);
	}
}





