#pragma once
#include "MineSweeper.h"

namespace CJH {
	void printName() {
		cout << "201711430 컴퓨터공학부 차준혁" << endl << endl;
	}
}

MineSweeper::MineSweeper():menuNum(3)
{
	
}

MineSweeper::~MineSweeper()
{	
	//cout << "minesweeper 소멸자 생성1" << endl;

	if (map != nullptr) {
		for (int i = 0; i < this->mapRow+2;i++) {
			delete[] map[i];
		}
		delete[] map;
		//cout << "map 소멸" << endl;
	}
	map = nullptr;

	if (checkedmap != nullptr) {
		for (int i = 0; i < this->mapRow+2; i++) {
			delete[] checkedmap[i];
		}
		delete[] checkedmap;
		//cout << "checkedmap 소멸" << endl;

	}
	checkedmap = nullptr;
	//cout << "minesweeper 소멸자 생성2" << endl;

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
				cout << "■";
			}
			cout << endl;
		}
		cout << "\nex) 맵의 크기 = 15" << endl;
		cout << "맵의 크기를 입력해주세요.(10부터 20까지 가능) : ";
		int tempSize;
		cin >> tempSize;
		while (cin.fail() || tempSize < 10 || tempSize>20) {
			cout << "\n잘못 입력하셨습니다. 다시 입력해주세요.(10에서 20까지 선택 가능)" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "맵의 크기를 입력해주세요.(10부터 20까지 가능) : ";
			cin >> tempSize;
		}
		this->mapRow = tempSize;
		this->mapCol = this->mapRow;
		this->mapSize = mapCol * mapRow;

		cout << "\n난이도를 선택해주세요.(하,중,상)" << endl << endl;
		cout << "1. 난이도 하" << endl;
		cout << "2. 난이도 중" << endl;
		cout << "3. 난이도 상" << endl;
		cout << "입력 : ";
		cin >> this->gameLevel;
		while (cin.fail() || gameLevel < 1 || gameLevel>3) {
			cout << "\n잘못 입력하셨습니다. 다시 입력해주세요.(1에서 3까지 선택 가능)" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "\n난이도를 선택해주세요.(하,중,상)" << endl;
			cout << "1. 난이도 하" << endl;
			cout << "2. 난이도 중" << endl;
			cout << "3. 난이도 상" << endl;
			cout << "입력 : ";
			cin >> this->gameLevel;
		}
		cout << "\n맵의 크기 : " << mapRow << " X " << mapCol << endl;
		switch (gameLevel) {
		case 1:
			this->mineNum = this->mapSize * 0.1;
			cout << "난이도 : 하" << endl;
			cout << "지뢰 총 " << mineNum << "개" << endl;
			break;
		case 2:
			this->mineNum = this->mapSize * 0.2;
			cout << "난이도 : 중" << endl;
			cout << "지뢰 총 " << mineNum << "개" << endl;
			break;
		case 3:
			this->mineNum = this->mapSize * 0.3;
			cout << "난이도 : 상" << endl;
			cout << "지뢰 총 " << mineNum << "개" << endl;
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
	cout << "\n\n●⊙●⊙●⊙지뢰 찾기 게임●⊙●⊙●⊙" << endl;
	cout << endl << endl << endl;
	cout << "	  1. 새 게임 시작" << endl<<endl;
	cout << "	  2. 이어하기" << endl<<endl;
	cout << "	  3. 게임 종료" << endl<<endl;
	cout << "입력 : ";
	cin >> this->menuNum;
	while (cin.fail()||menuNum<1||menuNum>3) {
		cout << "\n잘못 입력하셨습니다. 다시 입력해주세요.(1, 2, 3 중 선택 가능)" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "입력 : ";
		cin >> this->menuNum;
	}
}

void MineSweeper::setMap()//새로운 게임 시작할 때 map 초기화
{	
	// 2씩 더해서 맵을 만든다
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



	//지뢰 랜덤 배정
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

	//지뢰 주변 count
	//가운데에 있는 지뢰들 주변
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

void MineSweeper::loadMap()//지난 게임 불러와서 map 초기화
{
	ifstream fin("lastgame.txt");
	if (!fin) {
		cout << "저장된 데이터가 없습니다." << endl;
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
				cout << "  ";//1 더해준거 안보이게 할려고
			}
			else {
				switch (show) {
				case 0:
					if (check) {
						cout << " 0";
						openClean(a, b);//연속 8방향 open
					}
					else {
						cout << "■";
					}
					break;
				case 9:
					if (check) {
						cout << "⊙";	
					}
					else {
						cout << "■";
					}
					break;
				default:
					if (check) {
						cout << " " << show;
					}
					else {
						cout << "■";
					}
					break;
				}
			}
		}
		cout << endl;
	}
	cout << endl << endl;
	//확인용 printMap
	/*for (int a = 0; a < mapRow + 2; a++) {
		cout << "\t";
		for (int b = 0; b < mapCol + 2; b++) {
			int show = map[a][b];
			int check = checkedmap[a][b];
			if (a == 0 || b == 0 || a == mapRow + 1 || b == mapCol + 1) {
				cout << "  ";//1 더해준거 안보이게 할려고
			}
			else {
				switch (show) {
				case 0:
					cout << " 0";
					break;
				case 9:
					cout << "⊙";
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
		cout << "지뢰를 선택했습니다................ㅠ " << endl;
	}
	else if (GameOver ==2) {//Gameover=2 ->win
		cout << "\n모든 지뢰를 선택하지 않고 찾았습니다!!!!!" << endl;
		system("pause");

	}
	else if (GameOver == 3) {// GameOver=3 ->Q입력해서 종료한 경우
		cout << "⊙⊙⊙⊙⊙⊙⊙맵에 숨겨져 있던 지뢰들 입니다⊙⊙⊙⊙⊙⊙⊙" << endl;
	}
	else{
		cout << "맵에 있는 모든 지뢰⊙를 선택하지 않고 찾으면 승리, 지뢰를 하나라도 선택하면 패배" << endl << endl;
		cout << "===============================조 작=================================" << endl;
		cout << "선택 : ENTER\n상하좌우 이동 : 방향키↑↓←→ " << endl;
		cout << "플레이어 : ☆" << endl;
		cout << "종료 ====> Q" << endl;
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
	cout << "☆";
	while (true) {
		if (GameOver == 1) {//패배한 경우
			loadReplay();
			cout << "\n안녕히가세요 :D." << endl;
			break;
		}
		else if (GameOver == 3) {//도중에 종료한 경우
			cout << "\n안녕히가세요 :D." << endl;
			break;
		}
		else if (GameOver == 2) {//승리한 경우
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
			case 224://방향키 입력
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
				cout << "☆";
				break;
			case 13://엔터키 입력
				checkMine();
				for (int i = 0; i < this->drawCount; i++) {
				printMap();
				}
				this->drawCount = 1;
				gotoxy(x, y);
				cout << "☆";
				saveReplay();
				break;
			case 81://Q입력
				this->GameOver = 3;
				system("cls");
				CJH::printName();
				cout << "\n1. 현재까지 저장하고 종료하기" << endl;
				cout << "2. 저장하지 않고 종료하기" << endl;
				int temp4;
				cin >> temp4;
				while (cin.fail() || temp4 < 1 || temp4>2) {
					cout << "\n잘못 입력하셨습니다. 다시 입력해주세요.(1, 2중에 선택 가능)" << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "\n1. 현재까지 저장하고 종료하기" << endl;
					cout << "2. 저장하지 않고 종료하기" << endl;
					cin >> temp4;
				}
				switch (temp4) {
				case 1:
					saveGame();
					CJH::printName();
					cout << "\n저장 완료" << endl;
					break;
				case 2:
					CJH::printName();
					cout << "\n저장하지 않고 종료합니다." << endl;
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
		checkedmap[checkedRow][checkedCol] = 1;//선택한거 보여주게 바꿈

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
		int aroundcheck = 0; //0주변에 0인 자리가 더 있는지 체크하는 함수
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if ((i==-1&&j==-1)||(i==0&&j==-1)||(i==1&&j==-1)||(i==-1&&j==0)) {//체크한 자리 왼쪽과 윗줄에서 0인 자리가 나오면
					if (map[row + i][col + j] == 0&&checkedmap[row+i][col+j] == 0)
						aroundcheck += 1;
				}
				checkedmap[row + i][col + j] = 1;
			}
		}
		if (aroundcheck > 0) {
			this->drawCount += 1; //주변에 0인 자리가 더 있다면 printmap을 그만큼 더 해서 다 오픈하기 위한 변수
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
		cout << "저장 실패" << endl;
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

	//리플레이 저장
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
		cout << "저장된 데이터가 없습니다." << endl;
	}
	fin1 >> this->mapRow;
	fin1 >> this->gameLevel;
	fin1.close();
}



void MineSweeper::saveReplay()
{
	ofstream rfout("replay.txt", ios::app);
	if (rfout.fail()) {
		cerr << "replay 파일을 찾을 수 없습니다." << endl;
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
		cerr << "replay 파일을 찾을 수 없습니다." << endl;
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
	cout << "\nREPLAY 끝\n" << endl;
	system("pause");
	rfin.close();
}

void MineSweeper::printReplayMap()
{
	system("cls");
	CJH::printName();
	cout << "※※※※※※※REPLAY※※※※※※※" << endl<<endl;
	for (int a = 0; a < mapRow + 2; a++) {
		cout << "\t";
		for (int b = 0; b < mapCol + 2; b++) {
			int show = map[a][b];
			int check = checkedmap[a][b];
			if (a == 0 || b == 0 || a == mapRow + 1 || b == mapCol + 1) {
				cout << "  ";//1 더해준거 안보이게 할려고
			}
			else {
				switch (show) {
				case 0:
					if (check) {
						cout << " 0";
					}
					else {
						cout << "■";
					}
					break;
				case 9:
					if (check) {
						cout << "⊙";
					}
					else {
						cout << "■";
					}
					break;
				default:
					if (check) {
						cout << " " << show;
					}
					else {
						cout << "■";
					}
					break;
				}
			}
		}
		cout << endl;
	}
	cout << endl << endl;
	/*확인용 printMap
	for (int a = 0; a < mapRow + 2; a++) {
		cout << "\t";
		for (int b = 0; b < mapCol + 2; b++) {
			int show = map[a][b];
			int check = checkedmap[a][b];
			if (a == 0 || b == 0 || a == mapRow + 1 || b == mapCol + 1) {
				cout << " k";//1 더해준거 안보이게 할려고
			}
			else {
				switch (show) {
				case 0:
					cout << " 0";
					break;
				case 9:
					cout << "⊙";
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
		cout << "※※※※※※※※LOSE※※※※※※※※" << endl;

	}
	else if (GameOver == 2) {
		cout << "※※※※※※※※※WIN※※※※※※※※" << endl;

	}
	system("pause");
}

void MineSweeper::resetReplay()
{
	ofstream resetfout("replay.txt", ios::out);
	if (resetfout.fail()) {
		cerr << "replay 파일을 새로 쓸 수 없습니다." << endl;
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




