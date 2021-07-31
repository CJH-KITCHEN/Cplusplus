#pragma once
#include <string>
using std::string;
class Salesman
{
private:
	string m_name;
	double m_sales;
	static inline int count = 0;
	//int count = 0; 요고는 객체 생성때마다 초기화됨1
public:
	Salesman();
	Salesman(const Salesman& man);
	//Salesman(const char* name);
	explicit Salesman(const string& name);
	Salesman(const string& name, const double& sales);
	~Salesman();
	void setName(const string& name);
	string getName() {
		return this->m_name;
	}
	string getName() const {
		return this->m_name;
	}
	void readInput();
	string getSalesmanInfo();
	void setSales(const double& sales);
	double getSales();
	friend void show(const Salesman& s);
	static int getCount() {
		return count;
	}
	void showFriend(Salesman s); //Salesman s = s3; 이 실행되는거임 ㅋ 복사생성자 ㅇㅇ
};

