#include "Movie.h"
#include <iomanip>

Movie::Movie(const int movieselect, const string mname, const int Row, const int Col):movieselect(movieselect),MovieName(mname), row(Row), col(Col), availableNum(Row*Col) {
	loadSeats();
	cout << "Movie 생성자" << endl;
}

Movie::~Movie()
{	
	cout << "Movie 소멸자" << endl;
	if (seats != nullptr) {
		for (int i = 0; i < this->row; i++) {
			delete[] seats[i];
		}
		delete[] seats;
	}
	seats = nullptr;
}

Movie::Movie(Movie& movie) :movieselect(movie.movieselect), MovieName(movie.MovieName), row(movie.row), col(movie.col), availableNum(movie.availableNum)
{
	loadSeats();
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			this->seats[i][j] = movie.seats[i][j];
		}
	}
	cout << "Movie 복사생성자" << endl;
}

Movie::Movie(Movie&& movie)noexcept:movieselect(movie.movieselect), MovieName(movie.MovieName), row(movie.row), col(movie.col), availableNum(movie.availableNum)
{
	cout << "Movie 이동생성자" << endl;
	this->seats = movie.seats;
	movie.seats = nullptr; 
}

void Movie::loadSeats()
{
	this->seats = new bool* [this->row];
	for (int i = 0; i < this->row; i++) {
		this->seats[i] = new bool[this->col];
	}

	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j <this->col; j++) {
		this->seats[i][j] = false;
		}
	}
}

void Movie::showSeats()
{
	if (this->seats != nullptr) {
		cout << endl;
		for (int i = 0; i < col; i++)
			cout << '\t' << i + 1;
		cout << "\n\n";
		for (int i = 0; i < row; i++) {
			cout << static_cast<char>('A' + i) << '\t';
			for (int j = 0; j < col; j++) {
				cout << (seats[i][j] ? "●" : "○") << '\t';
			}
			cout << endl;
		}
	}
}

void Movie::showMovieData()
{
	if (this->seats != nullptr) {
		string name = this->MovieName;
		int namelen = (38 - name.length());
		cout << (this->movieselect + 1) << ") " << this->MovieName;
		if (this->availableNum == 0) {
			cout << setfill(' ') << setw(namelen + 3);
			cout << "매진" << endl;
		}
		else {
			cout << setfill(' ') << setw(namelen);
			cout << this->availableNum << "/" << (this->row) * (this->col) << endl;
		}
	}
}

void Movie::reserveSeats()
{
	if (this->seats != nullptr) {
		cout << "\n예매할 좌석을 선택하세요(ex) A 1, B 2) : ";
		char x, y;
		cin >> x >> y;
		char MDRow, MDCol;//영화관 좌석의 행과 열을 뜻함
		MDRow = static_cast<char>('A' + (this->row) - 1);
		MDCol = static_cast<char>('1' + (this->col) - 1);
		if (x < 'A' || x > MDRow) {
			cout << "\n죄송하지만 존재하지 않는 좌석입니다." << endl;
		}

		else if (y < '1' || y > MDCol) {
			cout << "\n죄송하지만 존재하지 않는 좌석입니다." << endl;
		}

		else if (seats[x - 'A'][y - '1']) {
			cout << "\n이미 예약된 자리입니다." << endl;
		}
		else {
			seats[x - 'A'][y - '1'] = true;
			(this->availableNum)--;
			cout << "\n예약이 완료되었습니다." << endl;
			cout << "예약번호는 " << static_cast<char>(this->movieselect + 'A');
			cout << static_cast<char>(x - 'A' + 'C');
			cout << static_cast<char>(y - '1' + 'D') << " 입니다." << endl;
		}
	}
}

void Movie::cancelSeats(char c2, char c3)
{
	if (this->seats != nullptr) {
		int dNum2 = static_cast<int>(c2 - 'C');
		int dNum3 = static_cast<int>(c3 - 'D');
		if (dNum2 <0 || dNum2 >(this->row) - 1 || dNum3 < 0 || dNum3 >(this->col) - 1) {
			cout << "\n예약번호가 존재하지 않습니다." << endl;
		}
		else {
			if (seats[dNum2][dNum3]) {
				seats[dNum2][dNum3] = 0;
				this->availableNum++;
				cout << "\n예매가 취소되었습니다." << endl;
			}
			else {
				cout << "\n예약번호가 존재하지 않습니다." << endl;
			}
		}
	}
}

void Movie::checkSeats(char c2, char c3)
{
	if (this->seats != nullptr) {
		int searchNum2 = static_cast<int>(c2 - 'C');
		int searchNum3 = static_cast<int>(c3 - 'D');
		if (searchNum2 <0 || searchNum2 >(this->row) - 1 || searchNum3 < 0 || searchNum3 >(this->col) - 1) {
			cout << "\n예약번호가 존재하지 않습니다." << endl;
		}
		else {
			if (seats[searchNum2][searchNum3]) {
				cout << "예매하신 영화 : " << this->MovieName << endl;
				cout << "예매하신 좌석 : " << static_cast<char>(searchNum2 + 'A') << (searchNum3 + 1) << endl;
				cout << "\n=====================영화 예매 좌석====================\n";
				cout << endl;
				for (int i = 0; i < this->col; i++)
					cout << '\t' << i + 1;
				cout << "\n\n";
				for (int i = 0; i < this->row; i++) {
					cout << static_cast<char>('A' + i) << '\t';
					for (int j = 0; j < this->col; j++) {
						cout << (((i == searchNum2) && (j == searchNum3)) ? "☆" : "○") << '\t';
					}
					cout << endl;
				}
				system("pause");
			}
			else {
				cout << "\n예약번호가 존재하지 않습니다." << endl;
			}
		}
	}
}
