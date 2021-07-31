#include "CJHClient.h"


CJHClient::CJHClient(string s1, int price)
{
	this->name = s1;
	this->sendprice = price;
}

CJHClient::CJHClient(CJHClient& cjhclient)
{
	this->name = cjhclient.name;
	this->sendprice = cjhclient.sendprice;
}


int CJHClient::returnprice()
{
	return this->sendprice;
}

string CJHClient::returnname()
{
	return this->name;
}


ostream& operator<< (ostream& out, const CJHClient& client) {
	cout << "------------------------" << endl;
	cout << "�̸� : " << client.name << endl;
	cout << "�����ݾ� : " << client.sendprice << endl;
	out << endl;
	return out;
}
