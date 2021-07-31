#include "CJHItem.h"
#include <algorithm>
CJHItem::CJHItem(string name, int num)
{
	this->itemname = name;
	this->itemnum = num;
	this->client = new CJHClient * [this->itemnum];
}

CJHItem::CJHItem(const CJHItem& cjhitem)
{
	this->itemname = cjhitem.itemname;
	this->itemnum = cjhitem.itemnum;
	this->check = cjhitem.check;
	this->sum = cjhitem.sum;
	this->client = new CJHClient * [cjhitem.itemnum];
	for (int i = 0; i < cjhitem.check; i++) {
		this->client[i] = new CJHClient(*(cjhitem.client[i]));
	}
}

CJHItem::CJHItem(CJHItem&& cjhitem) noexcept
{
	this->itemname = cjhitem.itemname;
	this->itemnum = cjhitem.itemnum;
	this->check = cjhitem.check;
	this->sum = cjhitem.sum;
	this->client = cjhitem.client;
	cjhitem.client = nullptr;
}

CJHItem::~CJHItem()
{
	if (this->client != nullptr) {
		for (int i = 0; i < (this->check); i++) {
			delete client[i];
		}
		delete[] client;
	}
	client = nullptr;
}

void CJHItem::join(CJHClient* c)
{

	if (check < this->itemnum) {
		client[check] = c;
		check++;
		this->sum += c->returnprice();
		cout << "경매에 참여했습니다." << endl;
	}
	else {
		for (int i = 0; i < itemnum; i++) {
			if ((this->client[i])->returnprice() < c->returnprice()) {
				this->sum -= client[i]->returnprice();
				delete client[i];
				client[i] = c;
				this->sum += c->returnprice();
				cout << "경매에 참여했습니다." << endl;
				return;
			}
		}
		cout << "경매에 참여하지 못했습니다." << endl;
		delete c;
		c = nullptr;
	}
	

}
void CJHItem::printdata()const
{
	
	for (int startindex = 0; startindex < this->check; ++startindex) {
		int bigindex = startindex;
		for (int currentindex = startindex + 1; currentindex < this->check; ++currentindex) {
			if (client[currentindex]->returnprice() > client[bigindex]->returnprice()) {
				bigindex = currentindex;
			}
		}
		swap(client[startindex], client[bigindex]);
	}
	
	for (int i = 0; i < this->check; i++) {
		cout << "이름 : " << client[i]->returnname()<< endl;
		cout << "입찰금액 : " << client[i]->returnprice() << endl;
		cout << "----------------------------------" << endl;
	}
}
ostream& operator<< (ostream& out, const CJHItem& item) {
	cout << "품목명 : " << item.itemname << endl;
	cout << "판매대수 : " << item.itemnum << endl;
	cout << "예상총액 : " << item.sum << endl;
	cout << "참여자 수 : " << item.check << endl;
	cout << "----------------------------------" << endl;
	item.printdata();
	out << endl;
	return out;
}

