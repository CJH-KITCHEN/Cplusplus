#include <iostream>
#include <string>
#include <sstream>
#include <stack>


using namespace std;

//문자열이 숫자인지 확인하는 함수
bool isNumber(const string& str) {
	for (char const& c : str) {
		if (std::isdigit(c) == 0)
			return false;
	}
	return true;
}

namespace CJH {
	void printName() {
		cout << "201711430 컴퓨터공학부 차준혁" << endl << endl;
	}
}


int main() {
	CJH::printName();
	stack<string> ST;
	string cals;
	cout << "후위표현식을 입력하세요 ==>";
	getline(cin, cals);
	stringstream ss(cals);
	string temp;
	
	while (getline(ss, temp, ' ')) {
		if (temp.compare("+") == 0) {
			int n2 = stoi(ST.top());
			ST.pop();
			int n1 = stoi(ST.top());
			ST.pop();
			int ctemp = n1 + n2;
			ST.push(to_string(ctemp));
		}
		else if (temp.compare("-") == 0) {
			int n2 = stoi(ST.top());
			ST.pop();
			int n1 = stoi(ST.top());
			ST.pop();
			int ctemp = n1 - n2;
			ST.push(to_string(ctemp));
		}
		else if (temp.compare("*") == 0) {
			int n2 = stoi(ST.top());
			ST.pop();
			int n1 = stoi(ST.top());
			ST.pop();
			int ctemp = n1 * n2;
			ST.push(to_string(ctemp));
		}
		else if (temp.compare("/") == 0) {
			int n2 = stoi(ST.top());
			ST.pop();
			int n1 = stoi(ST.top());
			ST.pop();
			int ctemp = n1 / n2;
			ST.push(to_string(ctemp));
		}
		else if (isNumber(temp)) {
			ST.push(temp);
		}
		else {
		}
	}
	cout << "결과 : " << ST.top() << endl;
	ST.pop();
}