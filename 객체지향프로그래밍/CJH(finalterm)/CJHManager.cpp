#include "CJHManager.h"

CJHManager::CJHManager(string managername)
{
	this->managername = managername;
}

void CJHManager::addItem(CJHProduct* product)
{
	plist.push_back(move(product));
}

vector<CJHProduct*> CJHManager::getItems()
{
	return this->plist;
}

