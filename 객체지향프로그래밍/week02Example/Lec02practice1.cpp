#include <iostream>
#include <string>
#include <fstream>
using namespace std;

namespace CJH {
	void printName() {
		cout << "�й� : 201711430 �̸� : ������" << endl<<endl;
	}
}

int main() {
	
	CJH::printName();

	ifstream fin("testdata.txt");
	if (!fin.is_open()) {
		cerr << "���� �б� ����\n";
		return 1;
	}
	string data;
	while (!fin.eof()) {
		string str;
		getline(fin, str);
		data += str + '\n';
	}
	cout << data << '\n';
	cout << "ã�� ���ڿ��� �Է��ϼ��� : ";
	string findstr;
	getline(cin, findstr);
	cout << "�ٲ� ���ڿ��� �Է��ϼ��� : ";
	string replacestr;
	getline(cin, replacestr);
	int startpos = 0;
	size_t pos = data.find(findstr, startpos);
	while (true) {
		if (pos == string::npos) {
			cerr << "\nã�� ���ڿ��� ����" << endl;
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