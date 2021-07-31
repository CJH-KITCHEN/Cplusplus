#pragma once
#include<string>
#include<iostream>
using namespace std;

class CJHClient
{private:
	string name;
	int sendprice;
public:
	CJHClient() = delete;
	CJHClient(string s1, int price);
	CJHClient(CJHClient& cjhclient);
	int returnprice();
	string returnname();
	friend ostream& operator<< (ostream& out, const CJHClient& client);
};

