#include <iostream>
#include <string>
#include <fstream>
using namespace std;

namespace CJH {
	void printName() {
		cout << "학번 : 201711430 이름 : 차준혁" << endl<<endl;
	}
}

int main() {
	
	CJH::printName();

	ifstream fin("testdata.txt");
	if (!fin.is_open()) {
		cerr << "파일 읽기 실패\n";
		return 1;
	}
	string data;
	while (!fin.eof()) {
		string str;
		getline(fin, str);
		data += str + '\n';
	}
	cout << data << '\n';
	cout << "찾을 문자열을 입력하세요 : ";
	string findstr;
	getline(cin, findstr);
	cout << "바꿀 문자열을 입력하세요 : ";
	string replacestr;
	getline(cin, replacestr);
	int startpos = 0;
	size_t pos = data.find(findstr, startpos);
	while (true) {
		if (pos == string::npos) {
			cerr << "\n찾는 문자열이 없음" << endl;
		}
		else {
			data = data.replace(pos, findstr.length(), replacestr);
			startpos = pos + findstr.length();
		}
		pos = data.find(findstr, startpos);
		if (pos == string::npos) {
			break;
		}
	}
	cout << endl << data << endl;

	return 0;
}