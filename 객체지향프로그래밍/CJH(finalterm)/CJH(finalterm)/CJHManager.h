#pragma once
#include "CJHClothing.h"
#include "CJHTV.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class CJHManager
{
private:
	string managername;
	vector<CJHProduct*> plist;
public:
	CJHManager() = delete;
	CJHManager(string managername);
	void addItem(CJHProduct* product);
	vector<CJHProduct*> getItems();
};

