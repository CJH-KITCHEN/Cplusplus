#include <iostream>
#include "Salesman.h"

using namespace std;


void show(const Salesman& s) {
	//cout << s.getName() << endl;
	cout << s.m_name << endl;
}

Salesman getSalesman(const string& name) {
	Salesman s(name);
	return s;
}

Salesman getSalesman2(const string& name) {
	return Salesman(name);
}

int main(){


	Salesman s1;
	Salesman s2("greenjoa");
	Salesman s3("greenjoa", 200.0);


	Salesman copy1(s2);
	Salesman copy2 = s3;
	cout << copy1.getSalesmanInfo() << endl;
	cout << copy2.getSalesmanInfo() << endl;
	Salesman copy3 = Salesman("greenjoa");

	cout << "=====================" << endl;
	copy3.showFriend(s3);
	cout << "=====================" << endl;
	Salesman s4 = getSalesman("greenjoa4"); //s
	cout << "=====================" << endl; 
	Salesman s5 = getSalesman2("greenjoa5");//Salesman(name)
	//Salesman s4 ("greenjoa"); //자동으로 형변환해줌 
	//Salesman s4 = "greenjoa"s;


	/*auto str = "greenjoa";
	cout << typeid(str).name() << endl;
	auto str2 = "greenjoa"s;
	cout << typeid(str2).name() << endl;*/

	/*Salesman s4 = s3;
	Salesman s5(s4);*/

	//cout << s5.getSalesmanInfo() << endl;

	//Salesman s1("greenjoa", 200.0);
	////show(s1);

	//Salesman s2("greenjoa", 200.0);



	//Salesman* s3 = new Salesman();
	//cout << Salesman::getCount() << endl;
	//delete s3;
	//cout << Salesman::getCount() << endl;
	// << s1.getCount() << endl;//되기는한데 하지마라 ㅋ
	//cout << s2.getCount() << endl;//되기는한데 하지마라 ㅋ
	
	}