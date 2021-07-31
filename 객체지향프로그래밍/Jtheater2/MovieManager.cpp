#include "MovieManager.h"
#include <iomanip>
namespace CJH {
	void printName() {
		cout << "�й� : 201711430 �̸� : ������" << endl << endl;
	}
}

MovieManager::MovieManager(string fileloc):fileloc(fileloc)
{
	cout << "MovieManager ������" << endl;
	this->menuNum = -1;
	this->MovieNum = -1;
	ifstream fin(fileloc);
	if (!fin.is_open()) {
		cerr << "���� ���� ����";
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
				movie[i] = new Movie(i, mname, row, col); //Movie��ü ���� ����
				//cout << "Movie��ü ���� ����" << endl;
			}
		}
	}
	else {
		movie = nullptr;
	}
}

MovieManager::~MovieManager()
{
	cout << "MovieManager �Ҹ���" << endl;
	if (movie != nullptr) {
		for (int i = 0; i < (this->MovieNum); i++) {
			delete movie[i];
			//cout << "delete Movie��ü" << endl;
		}
		delete[] movie;
		//cout << "delete Movie��ü�� ������ �迭" << endl;
	}
	movie = nullptr;
}

MovieManager::MovieManager(const MovieManager& moviemanager)
	:fileloc(moviemanager.fileloc),MovieNum(moviemanager.MovieNum), menuNum(moviemanager.menuNum)
{
	cout << "MovieManager ���������" << endl;
	if ((moviemanager.MovieNum) > 0) {
		this->movie = new Movie * [moviemanager.MovieNum];
			for (int i = 0; i < (moviemanager.MovieNum); i++) {
				movie[i] = new Movie(*(moviemanager.movie[i])); //Movie��ü ���� ������
				//cout << "Movie��ü ���� ����" << endl;
			}
	}
	else {
		movie = nullptr;
	}
}

MovieManager::MovieManager(MovieManager&& moviemanager) noexcept 
	:fileloc(moviemanager.fileloc),MovieNum(moviemanager.MovieNum), menuNum(moviemanager.menuNum)
{	
	cout << "MovieManager �̵�������" << endl;
	this->movie = moviemanager.movie;
	moviemanager.movie = nullptr;
}

void MovieManager::startMenu()
{
	if (this->movie != nullptr) {
		do {
			CJH::printName();
			cout << "================������ �ó׸�=================" << endl;
			cout << "1) ��ȭ ���� 2) ���� ��� 3) ���� Ȯ�� 4) ����" << endl;
			cout << "\n�޴��� �����ϼ��� : ";
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
				cout << "\n���� ���α׷��� �����մϴ�. �ȳ��� ������ ^.^\n";
				break;
			default:
				cout << "�߸� �Է��ϼ̽��ϴ�.\n";
				break;
			}
			cout << "\n";
		} while (this->menuNum != 4);
	}
}

void MovieManager::reserveMovie()
{
	int select;
	cout << "\n=================��ȭ ����==================\n";
	for (int i = 0; i < MovieNum; i++) {
		movie[i]->showMovieData();
	}
	cout << endl << "������ ��ȭ�� �����ϼ��� : ";
	cin >> select;
	movie[select - 1]->showSeats();
	movie[select - 1]->reserveSeats();
}

void MovieManager::cancelMovie()
{
	char c1, c2, c3;
	cout << "����� ��ȭ�� �����ȣ�� �Է����ּ���(ex) �����ȣ�� AEF��� �Է�: AEF): ";
	cin >> c1 >> c2 >> c3;
	int dNum1 = static_cast<int>(c1 - 'A');
	if (dNum1 <0 || dNum1>(this->MovieNum)-1) {
		cout << "\n�����ȣ�� �������� �ʽ��ϴ�." << endl;
	}
	else {
		movie[dNum1]->cancelSeats(c2, c3);
	}
}

void MovieManager::checkMovie()
{
	char c1, c2, c3;
	cout << "\n=================���� Ȯ��==================\n";
	cout << "�����ȣ�� �Է��ϼ���(ex) �����ȣ�� AEF��� �Է�: AEF): ";
	cin >> c1 >> c2 >> c3;
	int searchNum1 = static_cast<int>(c1 - 'A');
	if (searchNum1 <0 || searchNum1>(this->MovieNum) - 1) {
		cout << "\n�����ȣ�� �������� �ʽ��ϴ�." << endl;
	}
	else {
		movie[searchNum1]->checkSeats(c2, c3);
	}
}





