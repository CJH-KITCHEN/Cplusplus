#include <iostream>
#include "MovieManager.h"
using namespace std;

//�޸� ���� üũ!
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

MovieManager returnManager(string fileloc) {
	MovieManager temp(fileloc);
	return temp;
}
Movie returnMovie() {
	Movie temp(5, "��󷣵�", 5, 3);
	return temp;
}

int main() {
	//�޸� ���� üũ!
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	cout << "=========������==========" << endl<<endl;
	MovieManager June("moviedata.txt");
	June.startMenu();

	cout << "=========���������==========" << endl<<endl;
	MovieManager Hyeok(June);
	Hyeok.startMenu();

	cout << "=========�̵�������==========" << endl << endl;
	MovieManager Cha = returnManager("moviedata.txt");
	Cha.startMenu();

	//Movie��ü �̵�������
	/*cout << "201711430 ��ǻ�Ͱ��к� ������\n" << endl << endl;
	Movie testmovie = returnMovie();
	testmovie.showMovieData();
	testmovie.showSeats();
	*/

	/*MovieManager Cha(move(June));
	Cha.startMenu();
	June.startMenu();*/
}