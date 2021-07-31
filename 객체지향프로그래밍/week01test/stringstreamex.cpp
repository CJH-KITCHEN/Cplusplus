#include <iostream>
#include <string>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;

namespace CJH {
	void printName() {
		cout << "학번 : 201711430 이름 : 차준혁" << endl << endl;
	}
}

int main(void) {
	
	CJH::printName();

	int sum = 0;
	int a;
	string mystr;
	string name;
	cout << "Enter your data(name kor eng math) : ";
	getline(cin, mystr);
	stringstream ss;
	ss.str(mystr);
	ss >> name;
	while (ss >> a) {
		sum += a;
	}
	cout << name << " : " << sum << endl;
	return 0;
}