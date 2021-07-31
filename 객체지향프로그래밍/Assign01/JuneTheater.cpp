#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using std::cout;
using namespace std;

namespace CJH {
	void printName() {
		cout << "�й� : 201711430 �̸� : ������" << endl << endl;
	}
}

struct MovieData {
	string MovieName;
	int row, col, soldoutnum;
};

struct MovieData* TheaterSize(int& MovieNum) {
	ifstream fin("moviedata.txt");
	if (!fin.is_open()) {
		cerr << "���� ���� ����";
		exit(0);
	}
	fin >> MovieNum;
	MovieData* md = new MovieData[MovieNum];
	//delete[] ms; ��� üũ
	while (!fin.eof()) {
		for (int i = 0; i < MovieNum; i++) {
			fin >> md[i].MovieName;
			fin >> md[i].row;
			fin >> md[i].col;
			md[i].soldoutnum = 0;//����� �ʱ�ȭ
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
	//delete�ؾߵ�

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
	//delete ����ߵ�
	return reservNum;
}

void showSeats(bool*** seats, const int row, const int col, int select) {
	for (int i = 0; i < col; i++)
		cout << '\t' << i + 1;
	cout << "\n\n";
	for (int i = 0; i < row; i++) {
		cout << static_cast<char>('A' + i) << '\t';
		for (int j = 0; j < col; j++) {
			cout << (seats[select][i][j] ? "��" : "��") << '\t';
		}
		cout << endl;
	}
}

void reserveSeats(bool ***seats, const int row, const int col, int select) {
	char x, y;
	cin >> x >> y;
	if ((x - 'Q' == 0) && (y - 'Q' == 0)) {
		cout << "�¼� ������ �����մϴ�.";
	}
	else if (x < 'A' || x > 'F') {
		cout << "�˼������� �������� �ʴ� �¼��Դϴ�." << endl;
	}

	else if (y < '1' || y >'4') {
		cout << "�˼������� �������� �ʴ� �¼��Դϴ�." << endl;
	}

	else if (seats[select][x - 'A'][y - '1']) {
		cout << "�̹� ����� �ڸ��Դϴ�." << endl;
	}
	else {
		seats[select][x - 'A'][y - '1'] = true;
		cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
	}
}

int main() {
	CJH::printName();
	int menuNum, MovieNum;
	struct MovieData* md= TheaterSize(MovieNum);
	bool*** seats = loadSeats(md, MovieNum);
	
	//cout << md[0].MovieName << md[0].row << md[0].col;

	do {
		cout << "================������ �ó׸�================="<<endl;
		cout << "1) ��ȭ ���� 2) ���� ��� 3) ���� Ȯ�� 4) ����"<<endl;
		cout << "�޴��� �����ϼ��� : ";
		cin >> menuNum;
		switch (menuNum) {
			case 1:
				int select;
				cout << "=================��ȭ ����==================\n";
				for (int i = 0; i < MovieNum; i++) {
					cout << left << (i + 1) << left << ") " << left << md[i].MovieName << '\t';
					cout << md[i].soldoutnum << right << "/" << right << (md[i].row) * (md[i].col) << endl;
				}
				cout << "������ ��ȭ�� �����ϼ��� : ";
				cin >> select;
				showSeats(seats, md[select - 1].row, md[select - 1].col, select - 1);
				cout << "������ �¼��� �����ϼ���(ex) A 1, B 2) : ";
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
	cout << "���� ���α׷��� �����մϴ�. �ȳ��� ������ ^.^\n";
}