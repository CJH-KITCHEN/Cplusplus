#include <iostream>
#include <string>
#include <vector>
#include "CMyPoint.h"
#include <list>
using namespace std;

template<typename T>
void printArr(vector<T>& v) {
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
namespace CJH {
	void printName() {
		cout << "201711430 ��ǻ�Ͱ��к� ������" << endl << endl;
	}
}


template<typename T>
void printArr(list<T>& v) {
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

template<typename T>
list<T> getStudent(list<list<T>>& l, list<T> d){
	list<T> temp;
	for (auto s : l) {
		for (auto t : s) {
			temp.push_back(t);
		}
	}
	for (auto s : d) {
		temp.remove(s);
	}
	temp.sort();
	temp.unique();
	return temp;
}
int main() {
	//��¥ �ǽ� 1
	CJH::printName();
	list<list<string>> std;
	std.push_back({ "greenjoa1", "bluejoa1", "greenjoa3" });
	std.push_back({ "greenjoa1", "greenjoa3" });
	std.push_back({ "redjoa1", "greenjoa2", "bluejoa2" });
	list<string> droplist({ "greenjoa2", "bluejoa1" });

	auto student = getStudent(std, droplist);
	printArr(student);

	//�ǽ�8
	/*list<string> std1({"greenjoa1", "greenjoa2", "greenjoa3"});
	list<string> std2({ "bluejoa1", "bluejoa2"});
	list<string> std3({ "redjoa1"});

	vector<list <string>> std;
	std.push_back(std1);
	std.push_back(std2);
	std.push_back(std3);

	vector<string> stdname;
	for (auto s : std) {
		for (auto t : s) {
			stdname.push_back(t);
		}
	}
	printArr(stdname);*/

	//�ǽ�7
	list<CMyPoint> list2;
	list2.push_back(CMyPoint(10, 10));
	list2.emplace_back(20, 20);
	list2.emplace_back(20, 20);
	list2.emplace_back(20, 20);
	list2.push_front(CMyPoint(30, 30));
	list2.unique();
	printArr(list2);

	list<CMyPoint> list3;
	list3.push_back(CMyPoint(40, 40));
	list3.push_back(CMyPoint(50, 50));
	list2.splice(list2.end(), list3); //�̶� list3�� �����
	cout << list3.size() << endl;
	printArr(list2);

	//�ǽ�6
	/*list<int> list1({ 1,2,3,3,3,4,5 });
	list1.unique();
	printArr(list1);*/

	//�ǽ�5
	/*vector<unique_ptr<CMyPoint>> arr;
	arr.push_back(make_unique<CMyPoint>(10, 10));
	arr.push_back(make_unique<CMyPoint>(10, 10));
	arr.push_back(make_unique<CMyPoint>(10, 10));
	arr.push_back(make_unique<CMyPoint>(10, 10));

	for (auto it = arr.begin(); it != arr.end(); it++) {
		cout << **it << " ";
		//delete* it; //���� ����Ʈ �����Ͷ� ��������� delete���ص���
	}*/

	//�ǽ�4
	/*vector<CMyPoint*> arr;
	arr.push_back(new CMyPoint(10, 10));
	arr.push_back(new CMyPoint(10, 10));
	arr.push_back(new CMyPoint(10, 10));
	for (auto it = arr.begin(); it != arr.end(); it++) {
		cout << **it << " ";
		delete* it; //���� ��������� ����ߵ� �ּҰ��� ����� �迭�̹Ƿ� ��
	}
	cout << endl;
	//printArr(arr); �ּҰ� ��µ�
	*/


	//�ǽ�3
	/*vector<CMyPoint> arr;
	for (int i = 0; i < 5; i++) {
		//arr.push_back(CMyPoint(i * 10, i * 10)); //��� �ӽð�ü�ִ°�
		arr.emplace_back(i * 10, i * 10);			//��� ������ ��ü ���� �༭ �����ϴ°�, �̰� ���� ������ 
		cout << endl << endl;
	}*/

	//�ǽ�2
	//CMyPoint arr[] = { CMyPoint(10,20), CMyPoint(10,20),CMyPoint(10,20) };
	//vector<CMyPoint> arr3(&arr[0], &arr[3]); // arr[3]�ձ����� �� �ּҰ� �ִ� ����
	//printArr(arr3);
	
	//�ǽ�1
	/*vector<int> arr1({ 1,2,3,4,5 });

	vector<double> arr2;
	//arr2.insert(arr2.begin(), 2.5); //�����Ͱ� �ְų� ó�� ��ġ�� �������� insert����
	//arr2.insert(arr2.begin()++, 2.5); ���� ������ �����Ͱ� �ִ� ���� �־�ߵ�
	arr2.push_back(10.5);
	arr2.push_back(10.5);
	arr2.push_back(10.5);
	arr2.insert(arr2.begin(), 2.5);

	printArr(arr1);
	cout << "====================" << endl;
	printArr(arr2);
	*/
	vector<int> intarr1;
	for (int i = 0; i < 10; i++) {
		intarr1.push_back(i);
		cout << intarr1.size() << endl;
		cout << intarr1.capacity() << endl;
		cout << intarr1.data() << endl; //������ �߰��ϰų� �����ϸ� �ּҰ��� �޶��� �׷��� iteraotr ���� ��������
		cout << endl;
	}
	

}