#pragma once
#include<iostream>
#include<string>
#include<memory>

using namespace std;

class Movie
{
private:
	int movieselect; //��ȭ ����
	string MovieName; //��ȭ�̸�
	int row, col;	  //��ȭ�� �¼��� row, col
	int	availableNum; //�̿밡���� �¼� ��
	bool** seats;	//�¼� 2���� �迭 ���� �Ҵ�
public:
	Movie() = delete; //����Ʈ ������ ����
	Movie(const int movieselect, const string MovieName, const int row, const int col); //������
	~Movie(); //�Ҹ���
	Movie(Movie& movie);//���������
	Movie(Movie&& movie)noexcept;//�̵�������
	void loadSeats(); //�¼� �迭 ���� �� �ʱ�ȭ
	void showSeats(); //�¼� ���� ���
	void showMovieData();//��ȭ ������ ���
	void reserveSeats(); //�¼� ���� �Լ�
	void cancelSeats(char c2, char c3); // �¼� ��� �Լ�
	void checkSeats(char c2, char c3);// �¼� ���� Ȯ�� �Լ�
};

