#pragma once
#include "MineSweeper.h"

namespace CJH {
	void printName() {
		cout << "201711430 ��ǻ�Ͱ��к� ������" << endl << endl;
	}
}

MineSweeper::MineSweeper():menuNum(3)
{
	
}

MineSweeper::~MineSweeper()
{	
	//cout << "minesweeper �Ҹ��� ����1" << endl;

	if (map != nullptr) {
		for (int i = 0; i < this->mapRow+2;i++) {
			delete[] map[i];
		}
		delete[] map;
		//cout << "map �Ҹ�" << endl;
	}
	map = nullptr;

	if (checkedmap != nullptr) {
		for (int i = 0; i < this->mapRow+2; i++) {
			delete[] checkedmap[i];
		}
		delete[] checkedmap;
		//cout << "checkedmap �Ҹ�" << endl;

	}
	checkedmap = nullptr;
	//cout << "minesweeper �Ҹ��� ����2" << endl;

}

void MineSweeper::start()
{
	printMenu();
	switch (this->menuNum) {
	case 1:
		system("cls");
		CJH::printName();
		for (int a = 0; a < 15; a++) {
			cout << "\t";
			for (int b = 0; b < 15; b++) {
				cout << "��";
			}
			cout << endl;
		}
		cout << "\nex) ���� ũ�� = 15" << endl;
		cout << "���� ũ�⸦ �Է����ּ���.(10���� 20���� ����) : ";
		int tempSize;
		cin >> tempSize;
		while (cin.fail() || tempSize < 10 || tempSize>20) {
			cout << "\n�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.(10���� 20���� ���� ����)" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "���� ũ�⸦ �Է����ּ���.(10���� 20���� ����) : ";
			cin >> tempSize;
		}
		this->mapRow = tempSize;
		this->mapCol = this->mapRow;
		this->mapSize = mapCol * mapRow;

		cout << "\n���̵��� �������ּ���.(��,��,��)" << endl << endl;
		cout << "1. ���̵� ��" << endl;
		cout << "2. ���̵� ��" << endl;
		cout << "3. ���̵� ��" << endl;
		cout << "�Է� : ";
		cin >> this->gameLevel;
		while (cin.fail() || gameLevel < 1 || gameLevel>3) {
			cout << "\n�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.(1���� 3���� ���� ����)" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "\n���̵��� �������ּ���.(��,��,��)" << endl;
			cout << "1. ���̵� ��" << endl;
			cout << "2. ���̵� ��" << endl;
			cout << "3. ���̵� ��" << endl;
			cout << "�Է� : ";
			cin >> this->gameLevel;
		}
		cout << "\n���� ũ�� : " << mapRow << " X " << mapCol << endl;
		switch (gameLevel) {
		case 1:
			this->mineNum = this->mapSize * 0.1;
			cout << "���̵� : ��" << endl;
			cout << "���� �� " << mineNum << "��" << endl;
			break;
		case 2:
			this->mineNum = this->mapSize * 0.2;
			cout << "���̵� : ��" << endl;
			cout << "���� �� " << mineNum << "��" << endl;
			break;
		case 3:
			this->mineNum = this->mapSize * 0.3;
			cout << "���̵� : ��" << endl;
			cout << "���� �� " << mineNum << "��" << endl;
			break;
		}
		system("pause");
		setMap();
		playGame(menuNum);
		break;
	case 2:
		loadData();
		this->mapCol = this->mapRow;
		this->mapSize = mapCol * mapRow;
		switch (gameLevel) {
		case 1:
			this->mineNum = this->mapSize * 0.1;
			break;
		case 2:
			this->mineNum = this->mapSize * 0.2;
			break;
		case 3:
			this->mineNum = this->mapSize * 0.3;
			break;
		}
		setMap();
		loadMap();
		printMap();
		playGame(menuNum);
		break;
	case 3:
		break;
	}

		
}

void MineSweeper::printMenu()
{
	CJH::printName();
	cout << "\n\n�ܢ��ܢ��ܢ����� ã�� ���ӡܢ��ܢ��ܢ�" << endl;
	cout << endl << endl << endl;
	cout << "	  1. �� ���� ����" << endl<<endl;
	cout << "	  2. �̾��ϱ�" << endl<<endl;
	cout << "	  3. ���� ����" << endl<<endl;
	cout << "�Է� : ";
	cin >> this->menuNum;
	while (cin.fail()||menuNum<1||menuNum>3) {
		cout << "\n�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.(1, 2, 3 �� ���� ����)" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "�Է� : ";
		cin >> this->menuNum;
	}
}

void MineSweeper::setMap()//���ο� ���� ������ �� map �ʱ�ȭ
{	
	// 2�� ���ؼ� ���� �����
	if (this->mapSize > 0) {
		this->map = new int* [mapRow + 2];
		this->checkedmap = new int* [mapRow + 2];
		for (int i = 0; i < mapRow + 2; i++) {
			this->map[i] = new int[mapCol + 2];
			this->checkedmap[i] = new int[mapCol + 2];
		}

		for (int m = 0; m < mapRow+2; m++) {
			for (int n = 0; n < mapCol+2; n++) {
				this->map[m][n] = 0;
				this->checkedmap[m][n] = 0;
			}
		}
	}
	else {
		this->map = nullptr;
		this->checkedmap = nullptr;
	}



	//���� ���� ����
	int makeMineNum = 0;
	srand(time(NULL));
	while (makeMineNum != this->mineNum) {
		int randRow = rand() % (this->mapRow+1);
		int randCol = rand() % (this->mapCol+1);

		if (randRow != 0 && randCol != 0) {
			if (map[randRow][randCol] != 9) {
				map[randRow][randCol] = 9;
				makeMineNum++;
			}
		}
	}

	//���� �ֺ� count
	//����� �ִ� ���ڵ� �ֺ�
	for (int i = 1; i < (this->mapRow+2); i++) {
		for (int j = 1; j < (this->mapCol+2); j++) {
			if (map[i][j] == 9) {
				if (map[i - 1][j - 1] != 9) {
					map[i - 1][j - 1]++;
				}
				if (map[i][j - 1] != 9) {
					map[i][j - 1]++;
				}
				if (map[i + 1][j - 1] != 9) {
					map[i + 1][j - 1]++;
				}
				if (map[i - 1][j] != 9) {
					map[i - 1][j]++;
				}
				if (map[i + 1][j] != 9) {
					map[i + 1][j]++;
				}
				if (map[i - 1][j + 1] != 9) {
					map[i - 1][j + 1]++;
				}
				if (map[i][j + 1] != 9) {
					map[i][j + 1]++;
				}
				if (map[i + 1][j + 1] != 9) {
					map[i + 1][j + 1]++;
				}
			}
		}
	}
	printMap();
}

void MineSweeper::loadMap()//���� ���� �ҷ��ͼ� map �ʱ�ȭ
{
	ifstream fin("lastgame.txt");
	if (!fin) {
		cout << "����� �����Ͱ� �����ϴ�." << endl;
	}
	fin >> mapRow;
	fin >> gameLevel;
	for (int i = 0; i < this->mapRow+2; i++) {
		for (int j = 0; j < this->mapCol+2; j++) {
			fin >> checkedmap[i][j];
		}
	}
	for (int i = 0; i < this->mapRow+2; i++) {
		for (int j = 0; j < this->mapCol+2; j++) {
			fin  >> map[i][j];
		}
	}
	fin.close();
}

void MineSweeper::printMap()
{	
	system("cls");
	CJH::printName();
	for (int a = 0; a < mapRow+2; a++) {
		cout << "\t";
		for (int b = 0; b < mapCol+2; b++) {
			int show = map[a][b];
			int check = checkedmap[a][b];
			if (a == 0 || b == 0 || a == mapRow+1 || b == mapCol+1) {
				cout << "  ";//1 �����ذ� �Ⱥ��̰� �ҷ���
			}
			else {
				switch (show) {
				case 0:
					if (check) {
						cout << " 0";
						openClean(a, b);//���� 8���� open
					}
					else {
						cout << "��";
					}
					break;
				case 9:
					if (check) {
						cout << "��";	
					}
					else {
						cout << "��";
					}
					break;
				default:
					if (check) {
						cout << " " << show;
					}
					else {
						cout << "��";
					}
					break;
				}
			}
		}
		cout << endl;
	}
	cout << endl << endl;
	//Ȯ�ο� printMap
	/*for (int a = 0; a < mapRow + 2; a++) {
		cout << "\t";
		for (int b = 0; b < mapCol + 2; b++) {
			int show = map[a][b];
			int check = checkedmap[a][b];
			if (a == 0 || b == 0 || a == mapRow + 1 || b == mapCol + 1) {
				cout << "  ";//1 �����ذ� �Ⱥ��̰� �ҷ���
			}
			else {
				switch (show) {
				case 0:
					cout << " 0";
					break;
				case 9:
					cout << "��";
					break;
				default:
					cout << " " << show;
					break;
				}
			}
		}
		cout << endl;
	}*/
	cout << endl << endl;
	if (GameOver == 1) {
		cout << "���ڸ� �����߽��ϴ�................�� " << endl;
	}
	else if (GameOver ==2) {//Gameover=2 ->win
		cout << "\n��� ���ڸ� �������� �ʰ� ã�ҽ��ϴ�!!!!!" << endl;
		system("pause");

	}
	else if (GameOver == 3) {// GameOver=3 ->Q�Է��ؼ� ������ ���
		cout << "���������������ʿ� ������ �ִ� ���ڵ� �Դϴ٢�������������" << endl;
	}
	else{
		cout << "�ʿ� �ִ� ��� ���ڢ��� �������� �ʰ� ã���� �¸�, ���ڸ� �ϳ��� �����ϸ� �й�" << endl << endl;
		cout << "===============================�� ��=================================" << endl;
		cout << "���� : ENTER\n�����¿� �̵� : ����Ű����� " << endl;
		cout << "�÷��̾� : ��" << endl;
		cout << "���� ====> Q" << endl;
		//cout << "x : " << this->x << endl;
		//cout << "y : " << this->y << endl;
	}
}

void MineSweeper::playGame(int mNum)
{	
	if (mNum == 1) {
		resetReplay();
	}
	else if (mNum==2) {
		saveLastReplay();
	}
	gotoxy(x, y);
	setCursorView(false);
	cout << "��";
	while (true) {
		if (GameOver == 1) {//�й��� ���
			loadReplay();
			cout << "\n�ȳ��������� :D." << endl;
			break;
		}
		else if (GameOver == 3) {//���߿� ������ ���
			cout << "\n�ȳ��������� :D." << endl;
			break;
		}
		else if (GameOver == 2) {//�¸��� ���
			system("cls");
			CJH::printName();
			printMineMap();
			loadReplay();
			break;
		}
		gameRefree();
		if (_kbhit()) {
			int keycode = _getch();
			switch (keycode) {
			case 224://����Ű �Է�
				keycode = _getch();
				switch (keycode) {
				case 75:
					if(x != 10)
					x -= 2; 
					break;
				case 77:
					if(x != 10 + 2*mapRow - 2)
					x += 2; 
					break;
				case 72:
					if(y != 3)
					y -= 1; 
					break;
				case 80:
					if(y != 3 + mapCol - 1)
					y += 1; 
					break;
				}
				printMap();
				gotoxy(x, y);
				cout << "��";
				break;
			case 13://����Ű �Է�
				checkMine();
				for (int i = 0; i < this->drawCount; i++) {
				printMap();
				}
				this->drawCount = 1;
				gotoxy(x, y);
				cout << "��";
				saveReplay();
				break;
			case 81://Q�Է�
				this->GameOver = 3;
				system("cls");
				CJH::printName();
				cout << "\n1. ������� �����ϰ� �����ϱ�" << endl;
				cout << "2. �������� �ʰ� �����ϱ�" << endl;
				int temp4;
				cin >> temp4;
				while (cin.fail() || temp4 < 1 || temp4>2) {
					cout << "\n�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.(1, 2�߿� ���� ����)" << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "\n1. ������� �����ϰ� �����ϱ�" << endl;
					cout << "2. �������� �ʰ� �����ϱ�" << endl;
					cin >> temp4;
				}
				switch (temp4) {
				case 1:
					saveGame();
					CJH::printName();
					cout << "\n���� �Ϸ�" << endl;
					break;
				case 2:
					CJH::printName();
					cout << "\n�������� �ʰ� �����մϴ�." << endl;
					printMineMap();
					break;
				}
				system("pause");
				break;
			}
		}
	}
}

void MineSweeper::checkMine()
{
	int checkedRow = (y - 3) + 1;
	int checkedCol = ((x - 10) / 2) + 1;
	if (!checkedmap[checkedRow][checkedCol]) {
		checkedmap[checkedRow][checkedCol] = 1;//�����Ѱ� �����ְ� �ٲ�

		if (map[checkedRow][checkedCol] == 9) {
			this->GameOver = 1;
			printMineMap();
			system("pause");
		}
		else if (map[checkedRow][checkedCol] == 0) {
			printMap();
		}
	}
}

void MineSweeper::setCursorView(bool visible)
{
	CONSOLE_CURSOR_INFO cursor = { 1, visible };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void MineSweeper::gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void MineSweeper::gameRefree()
{
	this->WinPoint = 0;
	for (int i = 1; i < mapRow + 1; i++) {
		for (int j = 1; j < mapCol + 1; j++) {
			if (checkedmap[i][j] == 1) {
				this->WinPoint += 1;
			}
		}
	}
	if (WinPoint >= mapSize - mineNum) {
		this->GameOver = 2;
	}
}

int MineSweeper::openClean(int row, int col)
{	
	if (map[row][col] == 0&& row != 0 && row != this->mapRow + 1 && col != 0 && col != this->mapCol + 1) {
		/*checkedmap[row][col] = 1;
		checkedmap[row - 1][col - 1] = 1;
		checkedmap[row][col - 1] = 1;
		checkedmap[row + 1][col - 1] = 1;
		checkedmap[row - 1][col] = 1;
		checkedmap[row + 1][col] = 1;
		checkedmap[row - 1][col + 1] = 1;
		checkedmap[row][col + 1] = 1;
		checkedmap[row + 1][col + 1] = 1;*/
		int aroundcheck = 0; //0�ֺ��� 0�� �ڸ��� �� �ִ��� üũ�ϴ� �Լ�
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if ((i==-1&&j==-1)||(i==0&&j==-1)||(i==1&&j==-1)||(i==-1&&j==0)) {//üũ�� �ڸ� ���ʰ� ���ٿ��� 0�� �ڸ��� ������
					if (map[row + i][col + j] == 0&&checkedmap[row+i][col+j] == 0)
						aroundcheck += 1;
				}
				checkedmap[row + i][col + j] = 1;
			}
		}
		if (aroundcheck > 0) {
			this->drawCount += 1; //�ֺ��� 0�� �ڸ��� �� �ִٸ� printmap�� �׸�ŭ �� �ؼ� �� �����ϱ� ���� ����
		}
		return 1;
	}
	else {
		return -1;
	}
}

void MineSweeper::saveGame()
{	
	ofstream fout("lastgame.txt");
	if (fout.fail()) {
		cout << "���� ����" << endl;
	}
	fout << mapRow << endl;
	fout << gameLevel << endl;
	for (int i = 0; i < this->mapRow+2; i++) {
		for (int j = 0; j < this->mapCol+2; j++) {
			fout << checkedmap[i][j]<<' ';
		}
		fout << "\n";
	}
	for (int i = 0; i < this->mapRow+2; i++) {
		for (int j = 0; j < this->mapCol+2; j++) {
			fout << map[i][j]<<' ';
		}
		fout << "\n";
	}
	fout.close();

	//���÷��� ����
	ifstream copyin("replay.txt"); 
	ofstream copyout("lastreplay.txt"); 
	copyout << copyin.rdbuf(); 
	copyout.close(); 
	copyin.close();

}

void MineSweeper::loadData()
{
	ifstream fin1("lastgame.txt");
	if (!fin1) {
		cout << "����� �����Ͱ� �����ϴ�." << endl;
	}
	fin1 >> this->mapRow;
	fin1 >> this->gameLevel;
	fin1.close();
}



void MineSweeper::saveReplay()
{
	ofstream rfout("replay.txt", ios::app);
	if (rfout.fail()) {
		cerr << "replay ������ ã�� �� �����ϴ�." << endl;
	}
	for (int i = 0; i < this->mapRow + 2; i++) {
		for (int j = 0; j < this->mapCol + 2; j++) {
			rfout << checkedmap[i][j] << ' ';
		}
		rfout << "\n";
	}
	for (int i = 0; i < this->mapRow + 2; i++) {
		for (int j = 0; j < this->mapCol + 2; j++) {
			rfout << map[i][j] << ' ';
		}
		rfout << "\n";
	}
	rfout.close();
}

void MineSweeper::loadReplay()
{
	ifstream rfin("replay.txt");
	if (rfin.fail()) {
		cerr << "replay ������ ã�� �� �����ϴ�." << endl;
	}
	while (!rfin.eof()) {

		for (int i = 0; i < this->mapRow + 2; i++) {
			for (int j = 0; j < this->mapCol + 2; j++) {
				rfin >> checkedmap[i][j];
			}
		}
		for (int i = 0; i < this->mapRow + 2; i++) {
			for (int j = 0; j < this->mapCol + 2; j++) {
				rfin >> map[i][j];
			}
		}
		printReplayMap();
	}
	cout << "\nREPLAY ��\n" << endl;
	system("pause");
	rfin.close();
}

void MineSweeper::printReplayMap()
{
	system("cls");
	CJH::printName();
	cout << "�ءءءءءء�REPLAY�ءءءءءء�" << endl<<endl;
	for (int a = 0; a < mapRow + 2; a++) {
		cout << "\t";
		for (int b = 0; b < mapCol + 2; b++) {
			int show = map[a][b];
			int check = checkedmap[a][b];
			if (a == 0 || b == 0 || a == mapRow + 1 || b == mapCol + 1) {
				cout << "  ";//1 �����ذ� �Ⱥ��̰� �ҷ���
			}
			else {
				switch (show) {
				case 0:
					if (check) {
						cout << " 0";
					}
					else {
						cout << "��";
					}
					break;
				case 9:
					if (check) {
						cout << "��";
					}
					else {
						cout << "��";
					}
					break;
				default:
					if (check) {
						cout << " " << show;
					}
					else {
						cout << "��";
					}
					break;
				}
			}
		}
		cout << endl;
	}
	cout << endl << endl;
	/*Ȯ�ο� printMap
	for (int a = 0; a < mapRow + 2; a++) {
		cout << "\t";
		for (int b = 0; b < mapCol + 2; b++) {
			int show = map[a][b];
			int check = checkedmap[a][b];
			if (a == 0 || b == 0 || a == mapRow + 1 || b == mapCol + 1) {
				cout << " k";//1 �����ذ� �Ⱥ��̰� �ҷ���
			}
			else {
				switch (show) {
				case 0:
					cout << " 0";
					break;
				case 9:
					cout << "��";
					break;
				default:
					cout << " " << show;
					break;
				}
			}
		}
		cout << endl;
	}*/
	if (GameOver == 1) {
		cout << "�ءءءءءءء�LOSE�ءءءءءءء�" << endl;

	}
	else if (GameOver == 2) {
		cout << "�ءءءءءءءء�WIN�ءءءءءءء�" << endl;

	}
	system("pause");
}

void MineSweeper::resetReplay()
{
	ofstream resetfout("replay.txt", ios::out);
	if (resetfout.fail()) {
		cerr << "replay ������ ���� �� �� �����ϴ�." << endl;
	}
	resetfout.close();
}

void MineSweeper::printMineMap()
{
	for (int i = 0; i < mapRow + 2; i++) {
		for (int j = 0; j < mapCol + 2; j++) {
			if (map[i][j] == 9) {
				checkedmap[i][j] = 1;
			}
		}
	}
	printMap();
	system("pause");
}

void MineSweeper::saveLastReplay()
{
	ifstream rcopyin("lastreplay.txt");
	ofstream rcopyout("replay.txt");
	rcopyout << rcopyin.rdbuf();
	rcopyout.close();
	rcopyin.close();
}




