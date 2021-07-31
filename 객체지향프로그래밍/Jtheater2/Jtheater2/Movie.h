#pragma once
#include<iostream>
#include<string>
#include<memory>

using namespace std;

class Movie
{
private:
	int movieselect; //영화 순서
	string MovieName; //영화이름
	int row, col;	  //영화관 좌석의 row, col
	int	availableNum; //이용가능한 좌석 수
	bool** seats;	//좌석 2차원 배열 동적 할당
public:
	Movie() = delete; //디폴트 생성자 삭제
	Movie(const int movieselect, const string MovieName, const int row, const int col); //생성자
	~Movie(); //소멸자
	Movie(Movie& movie);//복사생성자
	Movie(Movie&& movie)noexcept;//이동생성자
	void loadSeats(); //좌석 배열 생성 및 초기화
	void showSeats(); //좌석 정보 출력
	void showMovieData();//영화 데이터 출력
	void reserveSeats(); //좌석 예약 함수
	void cancelSeats(char c2, char c3); // 좌석 취소 함수
	void checkSeats(char c2, char c3);// 좌석 예약 확인 함수
};

