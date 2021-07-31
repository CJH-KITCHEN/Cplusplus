#pragma once
#include <memory>
#include <fstream>
#include "Movie.h"
class MovieManager
{
private:
	Movie** movie;
	int menuNum;
	int MovieNum;
	string fileloc;
public:
	
	MovieManager() = delete; //����Ʈ ������ ����
	MovieManager(string fileloc);			//������ 
	~MovieManager(); //�Ҹ���
	MovieManager(const MovieManager& moviemanager);//���������
	MovieManager(MovieManager&& moviemanager)noexcept;//�̵�������
	void startMenu();
	void reserveMovie();
	void cancelMovie();
	void checkMovie();
}; 

