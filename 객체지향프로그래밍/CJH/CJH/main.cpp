#include<iostream>
#include "CJHClient.h"
#include "CJHItem.h"
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	cout << "201711430 ÄÄÇ»ÅÍ°øÇÐºÎ Â÷ÁØÇõ" << endl << endl;
	CJHClient cjh2("Â÷ÁØÇõ", 1000);
	cout << cjh2 << endl;

	CJHItem item1("TV", 3);
	item1.join(new CJHClient("Â÷ÁØÇõ01", 100));
	item1.join(new CJHClient("Â÷ÁØÇõ02", 200));
	item1.join(new CJHClient("Â÷ÁØÇõ03", 300));
	item1.join(new CJHClient("Â÷ÁØÇõ04", 50));
	item1.join(new CJHClient("Â÷ÁØÇõ05", 600));
	
	cout << item1 << endl;
	
	CJHItem item2(item1);
	cout << item2 << endl;

	CJHItem item3(move(item1));
	cout << item3 << endl;
}