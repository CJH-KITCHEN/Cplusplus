#include <iostream>
#include "MovieManager.h"
using namespace std;

//메모리 누수 체크!
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
	Movie temp(5, "라라랜드", 5, 3);
	return temp;
}

int main() {
	//메모리 누수 체크!
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	cout << "=========생성자==========" << endl<<endl;
	MovieManager June("moviedata.txt");
	June.startMenu();

	cout << "=========복사생성자==========" << endl<<endl;
	MovieManager Hyeok(June);
	Hyeok.startMenu();

	cout << "=========이동생성자==========" << endl << endl;
	MovieManager Cha = returnManager("moviedata.txt");
	Cha.startMenu();

	//Movie객체 이동생성자
	/*cout << "201711430 컴퓨터공학부 차준혁\n" << endl << endl;
	Movie testmovie = returnMovie();
	testmovie.showMovieData();
	testmovie.showSeats();
	*/

	/*MovieManager Cha(move(June));
	Cha.startMenu();
	June.startMenu();*/
}