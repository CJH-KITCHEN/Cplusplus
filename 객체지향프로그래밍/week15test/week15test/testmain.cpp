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
		cerr << "파일 열기 실패" << endl;
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
	//수업 실습 5
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
	//수업실습 4
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
		cout << "파일이 존재하지 않음" << endl;
	}*/
	//수업 실습 3
	//changeNumberByID("userlist.txt", 125, "010-1111-5555");



	//수업 실습 2
	/*int a;
	cin.exceptions(ifstream::failbit);
		while (true) {
			try {
				cin >> a;
				//if (cin.fail()) {
				//	throw exception("잘못된 값 입력");
				//}
				cout << a << endl;
			}
			catch (exception e) {
				cerr << e.what() << endl;
				cin.clear(); //fail비트 세팅 지우는거임 이거 안하면 예외처리 무한루프 ㅋ
				cin.ignore(numeric_limits<streamsize>::max(), '\n');//버퍼에 잘못 입력된 값 지우는 함수임 ㅋㅎㅋㅎ
			}
		}
	*/

	/*수업 실습 1
	ifstream dicfile("words.txt");
	map<string, string> dic;
	
	try {
		//if (!dicfile.fail()) {
		dicfile.exceptions(ifstream::failbit); //위의 if문과 같은 역할, 예외 throw
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
				cout << "단어 없음" << endl;
			}
		//}
		//else {
		//	//cerr << "파일이 존재하지 않음" << endl;
		//	throw exception("파일이 존재하지 않음");
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