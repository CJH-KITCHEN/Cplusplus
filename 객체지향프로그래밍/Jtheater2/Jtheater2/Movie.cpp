#include "Movie.h"
#include <iomanip>

Movie::Movie(const int movieselect, const string mname, const int Row, const int Col):movieselect(movieselect),MovieName(mname), row(Row), col(Col), availableNum(Row*Col) {
	loadSeats();
	cout << "Movie ������" << endl;
}

Movie::~Movie()
{	
	cout << "Movie �Ҹ���" << endl;
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
	cout << "Movie ���������" << endl;
}

Movie::Movie(Movie&& movie)noexcept:movieselect(movie.movieselect), MovieName(movie.MovieName), row(movie.row), col(movie.col), availableNum(movie.availableNum)
{
	cout << "Movie �̵�������" << endl;
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
				cout << (seats[i][j] ? "��" : "��") << '\t';
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
			cout << "����" << endl;
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
		cout << "\n������ �¼��� �����ϼ���(ex) A 1, B 2) : ";
		char x, y;
		cin >> x >> y;
		char MDRow, MDCol;//��ȭ�� �¼��� ��� ���� ����
		MDRow = static_cast<char>('A' + (this->row) - 1);
		MDCol = static_cast<char>('1' + (this->col) - 1);
		if (x < 'A' || x > MDRow) {
			cout << "\n�˼������� �������� �ʴ� �¼��Դϴ�." << endl;
		}

		else if (y < '1' || y > MDCol) {
			cout << "\n�˼������� �������� �ʴ� �¼��Դϴ�." << endl;
		}

		else if (seats[x - 'A'][y - '1']) {
			cout << "\n�̹� ����� �ڸ��Դϴ�." << endl;
		}
		else {
			seats[x - 'A'][y - '1'] = true;
			(this->availableNum)--;
			cout << "\n������ �Ϸ�Ǿ����ϴ�." << endl;
			cout << "�����ȣ�� " << static_cast<char>(this->movieselect + 'A');
			cout << static_cast<char>(x - 'A' + 'C');
			cout << static_cast<char>(y - '1' + 'D') << " �Դϴ�." << endl;
		}
	}
}

void Movie::cancelSeats(char c2, char c3)
{
	if (this->seats != nullptr) {
		int dNum2 = static_cast<int>(c2 - 'C');
		int dNum3 = static_cast<int>(c3 - 'D');
		if (dNum2 <0 || dNum2 >(this->row) - 1 || dNum3 < 0 || dNum3 >(this->col) - 1) {
			cout << "\n�����ȣ�� �������� �ʽ��ϴ�." << endl;
		}
		else {
			if (seats[dNum2][dNum3]) {
				seats[dNum2][dNum3] = 0;
				this->availableNum++;
				cout << "\n���Ű� ��ҵǾ����ϴ�." << endl;
			}
			else {
				cout << "\n�����ȣ�� �������� �ʽ��ϴ�." << endl;
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
			cout << "\n�����ȣ�� �������� �ʽ��ϴ�." << endl;
		}
		else {
			if (seats[searchNum2][searchNum3]) {
				cout << "�����Ͻ� ��ȭ : " << this->MovieName << endl;
				cout << "�����Ͻ� �¼� : " << static_cast<char>(searchNum2 + 'A') << (searchNum3 + 1) << endl;
				cout << "\n=====================��ȭ ���� �¼�====================\n";
				cout << endl;
				for (int i = 0; i < this->col; i++)
					cout << '\t' << i + 1;
				cout << "\n\n";
				for (int i = 0; i < this->row; i++) {
					cout << static_cast<char>('A' + i) << '\t';
					for (int j = 0; j < this->col; j++) {
						cout << (((i == searchNum2) && (j == searchNum3)) ? "��" : "��") << '\t';
					}
					cout << endl;
				}
				system("pause");
			}
			else {
				cout << "\n�����ȣ�� �������� �ʽ��ϴ�." << endl;
			}
		}
	}
}
