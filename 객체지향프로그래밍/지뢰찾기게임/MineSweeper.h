#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class MineSweeper
{
private:
	int menuNum;
	int** map; //1~8 : 주변에 있을 지뢰 개수 //0: 주변에 지뢰가 없는 상태 //9:지뢰가 있음
	int** checkedmap; //0: 미확인상태, 1: 확인상태
	int mapSize;
	int mapRow;
	int mapCol;
	int gameLevel;
	int mineNum=0;
	int x = 10;
	int y = 3;
	int GameOver = 0;
	int WinPoint = 0;
	int drawCount = 1;
public:
	MineSweeper();
	~MineSweeper();
	void start();
private:
	void printMenu();
	void setMap();
	void loadMap();
	void printMap();
	void playGame(int mNum);
	void checkMine(); //이 칸에 mine이 있는지 check
	void setCursorView(bool visible);
	void gotoxy(int x, int y);
	void gameRefree();
	int openClean(int row, int col);//0인곳 선택 자동 펼침 함수
	void saveGame();//게임 저장 함수
	void loadData();
	void saveReplay();//게임 진행하면서 진행과정 저장
	void loadReplay();//게임 종료시 진행과정 리플레이
	void printReplayMap();
	void resetReplay();
	void printMineMap();
	void saveLastReplay();
};

