#include <string>
#include <iostream>
#include "CMyPoint.h"
#include "Stack.h"
#include "ArrayData.h"

using namespace std;

namespace CJH {
	void printName() {
		cout << "201711430 컴퓨터공학부 차준혁" << endl << endl;
	}
}

template<typename T>
void printArr(T* arr, size_t N) {
	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}
	cout << endl;
}

template<>
void printArr(char* arr, size_t N) {
	cout << arr << endl;
}

template<typename T, size_t N>
void showArr(T(&arr)[N]) {
	cout << "Template showArr함수" << endl;
	for (auto i : arr) {
		cout << i << endl;
	}
	cout << endl;
}
//포인터 형태가 아닌 레퍼런스로 넘겨서  size정보도 넘겨줄 필요가 없음

//void printArr(double* arr, size_t N) {
//	for (int i = 0; i < N; i++) {
//		cout << arr[i] << endl;
//	}
//	cout << endl;
//}
//
//void printArr(string* arr, size_t N) {
//	for (int i = 0; i < N; i++) {
//		cout << arr[i] << endl;
//	}
//	cout << endl;
//}

template<typename T, size_t N>
void sortDesc(T(&arr)[N]) {
	for (size_t i = 0; i < N - 1; i++) {
		for (size_t j = i + 1; j < N; j++) {
			if (arr[i] < arr[j]) {
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

template<typename T, size_t N>
void sortAsc(T(&arr)[N]) {
	for (size_t i = 0; i < N - 1; i++) {
		for (size_t j = i + 1; j < N; j++) {
			if (arr[i] > arr[j]) {
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main() {

	CJH::printName();
	ArrayData<CMyPoint> arr;
	arr.addElement(CMyPoint(10, 50));
	arr.addElement(CMyPoint(20, 60));
	cout << arr << endl;

	/*ArrayData<CMyPoint> arr1;
	arr1.addElement(CMyPoint(10,20));
	arr1.addElement(CMyPoint(20, 20));
	arr1.addElement(CMyPoint(30, 20));


	cout << arr1 << endl;

	ArrayData<CMyPoint> arr2 = arr1;
	cout << arr2 << endl;

	ArrayData<CMyPoint> arr3 = move(arr2);
	cout << arr3 << endl;*/

	/*Stack<> stack;
	stack.push(10);
	stack.push(10); 

	Stack<int,40> istack;
	istack.push(10);
	istack.push(20);
	istack.push(30);
	istack.push(40);
	istack.push(50);
	int item;
	while (istack.pop(item)) {
		cout << item << endl;
	}

	Stack<double> dstack;
	dstack.push(10.0);
	dstack.push(20.0);
	dstack.push(30.0);
	dstack.push(40.0);
	dstack.push(50.0);
	double ditem;
	while (dstack.pop(ditem)) {
		cout << ditem << endl;
	}

	Stack<string> sstack;
	sstack.push("greenjoa1");
	sstack.push("greenjoa2");
	sstack.push("greenjoa3");
	string sitem;
	while (sstack.pop(sitem)) {
		cout << sitem << endl;
	}

	Stack<CMyPoint> ptstack;
	ptstack.push(CMyPoint(10,20));
	ptstack.push(CMyPoint(10, 20));
	ptstack.push(CMyPoint(10, 20));
	CMyPoint ptitem;
	while (ptstack.pop(ptitem)) {
		cout << ptitem << endl;
	}*/

	/*
	실습 1
	CJH::printName();
	CMyPoint arr[]{ CMyPoint(20,30), CMyPoint(10,20), CMyPoint(40,50) };
	sortAsc(arr);
	showArr(arr);*/

	/*CMyPoint arr[]{ CMyPoint(10,20), CMyPoint(25,30), CMyPoint(15,10) };
	sortDesc(arr);
	showArr(arr);*/


	/*int arr1[]{1,2,3,4,5};
	double arr2[]{ 1.1,2.2,3.3,4.4,5.5,6.6 };
	string arr3[]{ "greenjoa1","greenjoa2","greenjoa3" };
	char arr4[]{ 'a', 0, 'b', 'c' };
	sortDesc(arr1);
	showArr(arr1);
	sortDesc(arr2);
	showArr(arr2);
	sortDesc(arr3);
	showArr(arr3);*/

	/*showArr(arr1);
	showArr(arr2);*/


	/*printArr<int>(arr1, size(arr1));
	printArr(arr2, size(arr2));
	printArr(arr3, size(arr3));
	printArr(arr4, size(arr4));*/

	//cout << arr1 << endl;
	//cout << arr4 << endl; //char타입 만날땐 null값 만날 때까지 출력함
}