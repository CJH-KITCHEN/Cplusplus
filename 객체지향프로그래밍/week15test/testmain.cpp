#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <map>
#include <filesystem>

using namespace std;
using namespace std::filesystem;

void changeNumberByID(const string& filename, int id, const string& newNumber) {
	fstream data(filename);
	if (data.fail()) {
		cerr << "���� ���� ����" << endl;
		return;
	}
	while (!data.eof()) {
		int temp;
		data >> temp;
		if (data.fail()) {
			break;
		}
		if (temp == id) {
			data.seekp(data.tellg());
			data << " " << newNumber;
			break;
		}
	}
}

int main() {
	//���� �ǽ� 5
	path p1("c:/users/");
	auto begin = recursive_directory_iterator(p1);
	auto end = recursive_directory_iterator();
	for (auto it = begin; it != end; it++) {
		string spacer(it.depth() * 2, ' ');
		auto& entry = *it;
		if (is_regular_file(entry)) {
			cout << spacer << "File : " << entry.path();
			cout << "(" << file_size(entry) << "bytes)" << endl;

		}
		else if (is_directory(entry)) {
			cout << spacer << "Directory : " << entry.path() << endl;
		}

	}
	//�����ǽ� 4
	/*path p1("c:\\");
	p1.append("users");
	p1.append("greenjoa");
	p1 /= "test.txt";
	cout << p1 << endl;
	for (auto& c : p1) {
		cout << c << endl;
	}

	directory_entry file(p1);
	if (file.exists() && file.is_regular_file()) {
		cout << file.file_size() << endl;
	}
	else {
		cout << "������ �������� ����" << endl;
	}*/
	//���� �ǽ� 3
	//changeNumberByID("userlist.txt", 125, "010-1111-5555");



	//���� �ǽ� 2
	/*int a;
	cin.exceptions(ifstream::failbit);
		while (true) {
			try {
				cin >> a;
				//if (cin.fail()) {
				//	throw exception("�߸��� �� �Է�");
				//}
				cout << a << endl;
			}
			catch (exception e) {
				cerr << e.what() << endl;
				cin.clear(); //fail��Ʈ ���� ����°��� �̰� ���ϸ� ����ó�� ���ѷ��� ��
				cin.ignore(numeric_limits<streamsize>::max(), '\n');//���ۿ� �߸� �Էµ� �� ����� �Լ��� ��������
			}
		}
	*/

	/*���� �ǽ� 1
	ifstream dicfile("words.txt");
	map<string, string> dic;
	
	try {
		//if (!dicfile.fail()) {
		dicfile.exceptions(ifstream::failbit); //���� if���� ���� ����, ���� throw
			while (!dicfile.eof()) {
				string eng, kor;
				getline(dicfile, eng);
				getline(dicfile, kor);
				dic.insert({ eng, kor });
			}
			auto it = dic.find("consider");
			if (it != dic.end()) {
				cout << it->first << " : " << it->second << endl;
			}
			else {
				cout << "�ܾ� ����" << endl;
			}
		//}
		//else {
		//	//cerr << "������ �������� ����" << endl;
		//	throw exception("������ �������� ����");
		//}
	}
	catch (exception e) {
		cerr << e.what() << endl;
		cerr << dicfile.fail() << endl;
		cerr << dicfile.good() << endl;
		cerr << dicfile.bad() << endl;
		cerr << dicfile.eof() << endl;

	}*/
}