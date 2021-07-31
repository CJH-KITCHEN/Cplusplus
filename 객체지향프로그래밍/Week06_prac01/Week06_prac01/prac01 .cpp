#include <iostream>
#include "ArrayData.h"
#include <vector>



namespace CJH {
	void printName() {
		cout << "학번 : 201711430 이름 : 차준혁" << endl << endl;
	}
}

using namespace std;

void showArr(ArrayData& arr1) {
	cout << __FUNCTION__ << "(&)" << endl;
	arr1.showData();
}

void showArr(ArrayData&& arr1) {
	cout << __FUNCTION__ << "(&&)" << endl;
	arr1.showData();
}

ArrayData getArr(const int& num) {
	ArrayData arr(num);
	return arr;
 	 //return ArrayData(num);
}

void showArr(const ArrayData& arr) {
	for (size_t i = 0; i < arr.getUsed(); i++) {
		cout << arr[i] << endl;
	}
}

int main() {
	CJH::printName();

	ArrayData arr1(5);
	arr1.addElement(10.5);
	arr1.addElement(10.5);
	showArr(arr1);

	cout << "=================" << endl;
	ArrayData arr2;
	arr2 = arr1;
	for (int i = 0; i < arr2.getUsed(); i++) {
		cout << arr2[i] << endl;
	}
	cout << "===============" << endl;

	ArrayData arr3;
	arr3 = move(arr2);
	for (int i = arr3.getUsed(); i < arr3.getCapacity(); i++) {
		arr3[i] = 10.0;
		arr3.setUsed();
	}
	cout << arr3 << endl;

	/*ArrayData arr1 = getArr(10);
	arr1.addElement(5.5);
	arr1.addElement(2.5);
	arr1.showData();*/

	/*ArrayData arr1(10);
	ArrayData arr2(move(arr1));
	arr2.addElement(5.5);
	arr2.addElement(2.5);
	arr2.showData();*/

	/*vector<ArrayData> vec;
	for (size_t i = 0; i < 4; i++) {
		cout << "iteration" << i << endl;
		vec.push_back(ArrayData(5));
		cout << endl;
	}*/


	/*showArr(getArr(10));*/

	/*CJH::printName();
	ArrayData arr1(10);
	arr1.addElement(5.5);
	arr1.addElement(2.5);

	ArrayData arr2(arr1);
	arr2.addElement(3.5);

	arr1.showData();
	arr2.showData();*/

	//ArrayData data1;
	//data1.addElement(5.5);
	//data1.addElement(5.5);
	//data1.addElement(5.5);
	//data1.showData();
	//cout << "==============" << endl;
	//ArrayData copy1 (data1);
	////copy1.showData();
	//showArr(copy1);
	//cout << "==============" << endl;
	//ArrayData copy2 = getArr(10);

	/*ArrayData* parr = new ArrayData(10);
	parr->addElement(10.5);
	parr->addElement(10.5);
	parr->addElement(10.5);
	parr->addElement(10.5);
	parr->showData();
	
	delete parr;*/
}