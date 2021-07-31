#pragma once
#include "Salesman.h"
//#include <memory>
//using std::unique_ptr;
//using std::shared_ptr;
class SalesReport
{
private:
	//Salesman* team;
	//unique_ptr<Salesman[]> team;
	
	double highestSales;
	double averageSales;
	Salesman** team;
	size_t m_number;
	size_t count = 0;
	//shared_ptr<Salesman[]> team;
	

public:
	SalesReport();
	SalesReport(const size_t& number);
	~SalesReport();
	void computeStats();
	Salesman* getBestClerk();
	string getTeamInfo();
	size_t getNumber();
	void addMember();
};

