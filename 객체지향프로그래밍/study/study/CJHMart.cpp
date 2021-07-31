#include "CJHMart.h"

CJHMart::CJHMart(string filename):CJHMart(filename, "0000")
{
}

CJHMart::CJHMart(string filename, string pwd)
{	
	this->pwd = pwd;
	this->filename = filename;
	ifstream fin(this->filename);
	if (!fin.is_open()) {
		cerr << "파일오픈실패";
		exit(0);
	}
	fin >> (this->itemnum);
	if (itemnum > 0) {
		this->item = new Item * [itemnum];
		while (!fin.eof()) {
			for (int i = 0; i < this->itemnum; i++) {
				string iname;
				string icode;
				int inum;
				int iprice;
				fin >> icode >> iname >> inum >> iprice;
				item[i] = new Item(icode, iname, inum, iprice);
			}
		}
	}
	else {
		item = nullptr;
	}
}

CJHMart::CJHMart(CJHMart& cjhmart)
	:filename(cjhmart.filename), itemnum(cjhmart.itemnum), pricesum(cjhmart.pricesum), pwd(cjhmart.pwd)
{	
	if (itemnum>0) {
		this->item = new Item * [cjhmart.itemnum];
		for (int i = 0; i < cjhmart.itemnum; i++) {
			item[i] = new Item(*(cjhmart.item[i]));
		}
	}
	else {
	item = nullptr;
}
}

CJHMart::CJHMart(CJHMart&& cjhmart) noexcept
	:filename(cjhmart.filename), itemnum(cjhmart.itemnum), pricesum(cjhmart.pricesum), pwd(cjhmart.pwd)
{
	this->item = cjhmart.item;
	cjhmart.item = nullptr;
}

CJHMart::~CJHMart()
{
	if (item != nullptr) {
		for (int i = 0; i < itemnum; i++) {
			delete item[i];
		}
		delete[] item;
		item = nullptr;

	}
}

void CJHMart::showItems()
{
	cout << "***** CJHMart 제품 현황 *****" << endl;
	cout << "*****************************" << endl;
	cout << "코드	제품명	재고	가격	" << endl;
	cout << "*****************************" << endl;
	for (int i = 0; i < itemnum; i++) {
		item[i]->print();
	}
	cout << "*****************************" << endl;

}

void CJHMart::showItems(string pwd)
{
	if (this->pwd == pwd) {
		cout << "***** CJHMart 제품 현황 *****" << endl;
		cout << "*****************************" << endl;
		cout << "코드	제품명	재고	가격	누적금액		주문자" << endl;
		cout << "*****************************" << endl;
		for (int i = 0; i < itemnum; i++) {
			item[i]->print(true);
		}
		cout << "*****************************" << endl;
		cout << "총 판매 금액 : " << pricesum << endl;
		cout << "*****************************" << endl;

	}
	else {
		cout << "***** CJHMart 제품 현황 *****" << endl;
		cout << "*****************************" << endl;
		cout << "코드	제품명	재고	가격	" << endl;
		cout << "*****************************" << endl;
		for (int i = 0; i < itemnum; i++) {
			item[i]->print();
		}
		cout << "*****************************" << endl;
	}
}

string CJHMart::findItems(string name)
{
	int k = 0;
	for (int i = 0; i < itemnum; i++) {
		if (name == item[i]->returnname()) {
			k++;
			cout << "찾는 제품의 코드는 " << item[i]->returcode() << "입니다." << endl;
			return item[i]->returcode();
		}
	}
	if (k == 0) {
		cout << "판매하지 않는 제품입니다.\n" << endl;
		return "-1";
	}
	
}

bool CJHMart::sellItem(string code, string mart)
{	
	for (int i = 0; i < itemnum; i++) {
		if (code == item[i]->returcode()) {
			if (item[i]->remainitem()) {
				item[i]->sellitem(mart);
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}
