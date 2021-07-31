#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using std::cout;
using namespace std;

//�޸� ���� üũ!
/*#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif*/

namespace CJH {
	void printName() {
		cout << "�й� : 201711430 �̸� : ������" << endl << endl;
	}
}

struct MovieData {
	string MovieName;
	int row, col, availableNum;
};//��ȭ ���� ����üƲ

struct MovieData* TheaterSize(int& MovieNum) {
	ifstream fin("moviedata.txt");
	if (!fin.is_open()) {
		cerr << "���� ���� ����";
		exit(0);
	}
	fin >> MovieNum;
	MovieData* md = new MovieData[MovieNum];
	//delete üũ
	while (!fin.eof()) {
		for (int i = 0; i < MovieNum; i++) {
			fin >> md[i].MovieName;
			fin >> md[i].row;
			fin >> md[i].col;
			md[i].availableNum = (md[i].row)*(md[i].col);//���� ������ �¼� �� �ʱ�ȭ
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
	//delete�ؾߵ�

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
	cout << "\n=================��ȭ ����==================\n";
	for (int i = 0; i < MovieNum; i++) {
		string name = md[i].MovieName;
		int namelen =(38 - name.length());
		cout << (i + 1) << ") " << md[i].MovieName;
		if (md[i].availableNum == 0) {
			cout << setfill(' ') << setw(namelen+3);
			cout << "����" << endl;
		}
		else {
			cout << setfill(' ') << setw(namelen);
			cout << md[i].availableNum << "/" << (md[i].row) * (md[i].col) << endl;
		}
	}
	cout << endl << "������ ��ȭ�� �����ϼ��� : ";
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
			cout << (seats[select][i][j] ? "��" : "��") << '\t';
		}
		cout << endl;
	}
}

void reserveSeats(struct MovieData* (&md), bool*** (&seats), int select) {
	cout << "\n������ �¼��� �����ϼ���(ex) A 1, B 2) : ";
	char x, y;
	cin >> x >> y;
	char MDRow, MDCol;//��ȭ�� �¼��� ��� ���� ����
	MDRow = static_cast<char>('A' + (md[select].row) - 1);
	MDCol = static_cast<char>('1' + (md[select].col) - 1);
	if (x < 'A' || x > MDRow) {
		cout << "\n�˼������� �������� �ʴ� �¼��Դϴ�." << endl;
	}

	else if (y < '1' || y > MDCol) {
		cout << "\n�˼������� �������� �ʴ� �¼��Դϴ�." << endl;
	}

	else if (seats[select][x - 'A'][y - '1']) {
		cout << "\n�̹� ����� �ڸ��Դϴ�." << endl;
	}
	else {
		seats[select][x - 'A'][y - '1'] = true;
		(md[select].availableNum)--;
		cout << "\n������ �Ϸ�Ǿ����ϴ�." << endl;
		cout << "�����ȣ�� " << static_cast<char>(select + 'A');
		cout << static_cast<char>(x - 'A' + 'C');
		cout << static_cast<char>(y - '1' + 'D') << " �Դϴ�." << endl;
	}
}

void cancelSeats(struct MovieData* (&md), bool*** (&seats)) {
	char c1, c2, c3;
	cout << "����� ��ȭ�� �����ȣ�� �Է����ּ���(ex) �����ȣ�� AEF��� �Է�: AEF): ";
	cin >> c1 >> c2 >> c3;
	int dNum1 = static_cast<int>(c1 - 'A');
	int dNum2 = static_cast<int>(c2 - 'C');
	int dNum3 = static_cast<int>(c3 - 'D');

	if (seats[dNum1][dNum2][dNum3]) {
		seats[dNum1][dNum2][dNum3] = 0;
		(md[dNum1].availableNum)++;
		cout << "\n���Ű� ��ҵǾ����ϴ�." << endl;
	}
	else {
		cout << "\n�����ȣ�� �������� �ʽ��ϴ�." << endl;
	}
}

void checkSeats(struct MovieData* (&md), bool*** (&seats)) {
	char c1, c2, c3;
	cout << "\n=================���� Ȯ��==================\n";
	cout << "�����ȣ�� �Է��ϼ���(ex) �����ȣ�� AEF��� �Է�: AEF): ";
	cin >> c1 >> c2 >> c3;
	int searchNum1 = static_cast<int>(c1 - 'A');
	int searchNum2 = static_cast<int>(c2 - 'C');
	int searchNum3 = static_cast<int>(c3 - 'D');
	if (seats[searchNum1][searchNum2][searchNum3]) {
		cout << "�����Ͻ� ��ȭ : " << md[searchNum1].MovieName << endl;
		cout << "�����Ͻ� �¼� : " << static_cast<char>(searchNum2  + 'A') << (searchNum3 + 1) << endl;
		cout << "\n=====================��ȭ ���� �¼�====================\n";
		cout << endl;
		for (int i = 0; i < md[searchNum1].col; i++)
			cout << '\t' << i + 1;
		cout << "\n\n";
		for (int i = 0; i < md[searchNum1].row; i++) {
			cout << static_cast<char>('A' + i) << '\t';
			for (int j = 0; j < md[searchNum1].col; j++) {
				cout << ( ( (i== searchNum2)&&(j==searchNum3) )? "��" : "��") << '\t';
			}
			cout << endl;
		}
		system("pause");
	}
	else {
		cout << "\n�����ȣ�� �������� �ʽ��ϴ�." << endl;
	}

}

int main() {
	//�޸� ���� üũ!
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int menuNum, MovieNum;
	struct MovieData* md = TheaterSize(MovieNum);
	bool*** seats = loadSeats(md, MovieNum);

	do {
		CJH::printName();
		cout << "================������ �ó׸�=================" << endl;
		cout << "1) ��ȭ ���� 2) ���� ��� 3) ���� Ȯ�� 4) ����" << endl;
		cout << "\n�޴��� �����ϼ��� : ";
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
			cout << "�߸� �Է��ϼ̽��ϴ�.\n";
			break;
		}
		cout << "\n";
	} while (menuNum != 4);
	cout << "���� ���α׷��� �����մϴ�. �ȳ��� ������ ^.^\n";
}