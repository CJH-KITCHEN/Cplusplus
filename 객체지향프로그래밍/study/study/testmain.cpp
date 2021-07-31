#include <iostream>
#include "CJHMart.h"
using namespace std;

CJHMart makeMart(string file, string pwd) {
	CJHMart temp(file, pwd);
	return temp;
}
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	cout << "201711430 컴퓨터공학부 차준혁" << endl << endl;
	CJHMart cjh1("product.txt");
	CJHMart cjh2("product.txt", "wnsgur");
	
	string itemCode = cjh1.findItems("새우깡");
	cjh1.sellItem("A0005", "세종점");
	cjh1.sellItem("A0005", "강남점");
	cjh1.sellItem("A0005", "논현점");

	if (cjh1.sellItem(itemCode, "건대점")) {
		cout << "납품이 완료되었습니다." << endl << endl;
	}
	else {
		cout << "납품이 완료되지 않았습니다." << endl << endl;
	}
	cjh1.showItems();
	cjh1.showItems("0000");

	CJHMart greenjoa(cjh1);
	greenjoa.showItems();

	CJHMart cjh = makeMart("product.txt", "1234");
	cjh.showItems();

}