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
	cout << "201711430 ��ǻ�Ͱ��к� ������" << endl << endl;
	CJHMart cjh1("product.txt");
	CJHMart cjh2("product.txt", "wnsgur");
	
	string itemCode = cjh1.findItems("�����");
	cjh1.sellItem("A0005", "������");
	cjh1.sellItem("A0005", "������");
	cjh1.sellItem("A0005", "������");

	if (cjh1.sellItem(itemCode, "�Ǵ���")) {
		cout << "��ǰ�� �Ϸ�Ǿ����ϴ�." << endl << endl;
	}
	else {
		cout << "��ǰ�� �Ϸ���� �ʾҽ��ϴ�." << endl << endl;
	}
	cjh1.showItems();
	cjh1.showItems("0000");

	CJHMart greenjoa(cjh1);
	greenjoa.showItems();

	CJHMart cjh = makeMart("product.txt", "1234");
	cjh.showItems();

}