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
	int** map; //1~8 : �ֺ��� ���� ���� ���� //0: �ֺ��� ���ڰ� ���� ���� //9:���ڰ� ����
	int** checkedmap; //0: ��Ȯ�λ���, 1: Ȯ�λ���
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
	void checkMine(); //�� ĭ�� mine�� �ִ��� check
	void setCursorView(bool visible);
	void gotoxy(int x, int y);
	void gameRefree();
	int openClean(int row, int col);//0�ΰ� ���� �ڵ� ��ħ �Լ�
	void saveGame();//���� ���� �Լ�
	void loadData();
	void saveReplay();//���� �����ϸ鼭 ������� ����
	void loadReplay();//���� ����� ������� ���÷���
	void printReplayMap();
	void resetReplay();
	void printMineMap();
	void saveLastReplay();
};

