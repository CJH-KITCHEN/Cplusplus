#include <iostream>
#include <map>
#include <list>
#include "Student.h"
#include <functional>
using namespace std;
using namespace std::placeholders;

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int calculate(int a, int b, int (*func)(int, int)) {
	return func(a, b);
}

template<typename T>
auto calculate(int a, int b, T func) {
	return func(a, b);
}

//auto calculate(int a, int b, minus<int> func) {
//	return func(a, b);
//}

bool sortdesc(int a, int b) {
	return a > b;
}

bool removescore(int a) {
	return a < 40;
}

int main() {
	//���� �ǽ� 5
	//list<int> mylist = { 50, 60, 10, 30, 40, 90 };
	////mylist.sort(greater<>());
	////mylist.remove_if(removescore);
	////mylist.remove_if(bind(less<>(), _1, 40)); // less<>()�� < ��
	//mylist.remove_if([](auto i) {return i < 40; });
	//for (auto it = mylist.begin(); it != mylist.end(); it++) {
	//		cout << *it << endl;
	//}

	//���� �ǽ� 4
	list<Student> stdlist;
	stdlist.push_back(Student("greenjoa1", "ȫ�浿", 80));
	stdlist.push_back(Student("greenjoa2", "�̱浿", 90));
	stdlist.push_back(Student("greenjoa3", "���浿", 60));
	stdlist.push_back(Student("greenjoa4", "�ֱ浿", 50));
	//stdlist.sort(greater<>());

	//stdlist.remove_if(bind(equal_to<>(), _1, Student("greenjoa3", "���浿", 60)));
	stdlist.remove_if([](auto i) {return i == Student("greenjoa3", "���浿", 60); });
	for(auto it = stdlist.begin(); it!=stdlist.end();it++){
		cout << *it << endl;
	}

	//���� �ǽ� 3
	//list<int> mylist = { 50, 60, 10, 30, 40, 90 };
	////mylist.sort(sortdesc); // default�� ���� less<>()
	//mylist.sort(greater<>());

	//for(auto it = mylist.begin(); it!=mylist.end();it++){
	//	cout << *it << endl;
	//}


	//���� �ǽ� 2
	//plus<int> p1;
	//minus<int> m1;

	////cout << p1(10, 20) << endl;

	//cout << calculate(10, 20, p1) << endl;
	//cout << calculate(10, 20, m1) << endl;
	
	//cout << calculate(10, 20, add) << endl;
	//cout << calculate(10, 20, sub) << endl;



	//���� �ǽ� 1
	//map<string, Student> cppclassA;
	//cppclassA["greenjoa1"] = Student("greenjoa1", "ȫ�浿", 60);
	//cppclassA.insert({ "greenjoa2", Student("greenjoa2", "��浿", 70) });
	//cppclassA.insert({ "greenjoa3", Student("greenjoa3", "�̱浿", 80) });
	//cppclassA.emplace("greenjoa4", Student("greenjoa4", "�ֱ浿", 90));


	//cout << "------------------cppclassA-------------------------" << endl;
	//for (const auto& p : cppclassA) {
	//	cout << p.first << " : " << p.second << endl;
	//}

	//auto pos = cppclassA.find("greenjoa3"); //iterator�� ��ȯ
	//if (pos != cppclassA.end()) {
	//	//cout << *pos <<endl; �̷��� �ϸ� pair��ü�� cout���� ����� ���� ����
	//	cout << pos->first << " : " << pos->second << endl;
	//}

	//map<string, Student> cppclassB;
	//cppclassB.insert({ "greenjoa5", Student("greenjoa5", "�ڱ浿", 77) });
	//cppclassB.emplace("greenjoa6", Student("greenjoa6", "��浿", 85));
	//cppclassB.insert({ "greenjoa3", Student("greenjoa3", "�̱浿", 80) });

	//cout << "------------------cppclassB-------------------------" << endl;
	//for (const auto& p : cppclassB) {
	//	cout << p.first << " : " << p.second << endl;
	//}

	//cppclassA.merge(cppclassB); //�Ӽ����� �����Ϸ��� c++17�� �ٲ���� ���� ����
	//cout << "------------------cppclassA-------------------------" << endl;
	//for (const auto& p : cppclassA) {
	//	cout << p.first << " : " << p.second << endl;
	//}

	//cout << "------------------cppclassB-------------------------" << endl;
	//for (const auto& p : cppclassB) {
	//	cout << p.first << " : " << p.second << endl;
	//}

	//auto node = cppclassA.extract("greenjoa1");
	//cout << node.key() << "," << node.mapped() << endl;
	//cppclassB.insert(move(node)); //A map������ ���ŵ�

	//cout << "------------------cppclassA-------------------------" << endl;
	//for (const auto& p : cppclassA) {
	//	cout << p.first << " : " << p.second << endl;
	//}

	//cout << "------------------cppclassB-------------------------" << endl;
	//for (const auto& [key, value] : cppclassB) {
	//	cout << key << " : " << value << endl; // ������ ���ε� ����
	//}
}