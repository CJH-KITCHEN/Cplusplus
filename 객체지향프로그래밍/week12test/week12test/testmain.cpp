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
		cout << "201711430 컴퓨터공학부 차준혁" << endl << endl;
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
	//진짜 실습 1
	CJH::printName();
	list<list<string>> std;
	std.push_back({ "greenjoa1", "bluejoa1", "greenjoa3" });
	std.push_back({ "greenjoa1", "greenjoa3" });
	std.push_back({ "redjoa1", "greenjoa2", "bluejoa2" });
	list<string> droplist({ "greenjoa2", "bluejoa1" });

	auto student = getStudent(std, droplist);
	printArr(student);

	//실습8
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

	//실습7
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
	list2.splice(list2.end(), list3); //이때 list3는 비워짐
	cout << list3.size() << endl;
	printArr(list2);

	//실습6
	/*list<int> list1({ 1,2,3,3,3,4,5 });
	list1.unique();
	printArr(list1);*/

	//실습5
	/*vector<unique_ptr<CMyPoint>> arr;
	arr.push_back(make_unique<CMyPoint>(10, 10));
	arr.push_back(make_unique<CMyPoint>(10, 10));
	arr.push_back(make_unique<CMyPoint>(10, 10));
	arr.push_back(make_unique<CMyPoint>(10, 10));

	for (auto it = arr.begin(); it != arr.end(); it++) {
		cout << **it << " ";
		//delete* it; //요고는 스마트 포인터라 명시적으로 delete안해도됨
	}*/

	//실습4
	/*vector<CMyPoint*> arr;
	arr.push_back(new CMyPoint(10, 10));
	arr.push_back(new CMyPoint(10, 10));
	arr.push_back(new CMyPoint(10, 10));
	for (auto it = arr.begin(); it != arr.end(); it++) {
		cout << **it << " ";
		delete* it; //삭제 명시적으로 해줘야됨 주소값이 저장된 배열이므로 ㅋ
	}
	cout << endl;
	//printArr(arr); 주소값 출력됨
	*/


	//실습3
	/*vector<CMyPoint> arr;
	for (int i = 0; i < 5; i++) {
		//arr.push_back(CMyPoint(i * 10, i * 10)); //얘는 임시객체넣는거
		arr.emplace_back(i * 10, i * 10);			//얘는 생성할 객체 인자 줘서 생성하는거, 이게 제일 가벼움 
		cout << endl << endl;
	}*/

	//실습2
	//CMyPoint arr[] = { CMyPoint(10,20), CMyPoint(10,20),CMyPoint(10,20) };
	//vector<CMyPoint> arr3(&arr[0], &arr[3]); // arr[3]앞까지만 들어감 주소값 주는 거임
	//printArr(arr3);
	
	//실습1
	/*vector<int> arr1({ 1,2,3,4,5 });

	vector<double> arr2;
	//arr2.insert(arr2.begin(), 2.5); //데이터가 있거나 처음 위치에 넣을때만 insert가능
	//arr2.insert(arr2.begin()++, 2.5); 요고는 오류남 데이터가 있는 곳에 넣어야됨
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
		cout << intarr1.data() << endl; //데이터 추가하거나 삭제하면 주소값이 달라짐 그래서 iteraotr 새로 만들어야함
		cout << endl;
	}
	

}