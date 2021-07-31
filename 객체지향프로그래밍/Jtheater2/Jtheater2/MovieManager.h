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
	
	MovieManager() = delete; //디폴트 생성자 삭제
	MovieManager(string fileloc);			//생성자 
	~MovieManager(); //소멸자
	MovieManager(const MovieManager& moviemanager);//복사생성자
	MovieManager(MovieManager&& moviemanager)noexcept;//이동생성자
	void startMenu();
	void reserveMovie();
	void cancelMovie();
	void checkMovie();
}; 

