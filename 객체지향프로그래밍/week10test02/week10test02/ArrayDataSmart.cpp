#include "ArrayDataSmart.h"
#include <iostream>
using namespace std;

ArrayDataSmart::ArrayDataSmart()
	:ArrayDataSmart(3)
{

}

ArrayDataSmart::ArrayDataSmart(ArrayDataSmart& arr)
	:ArrayData(arr), usedB(arr.usedB), backdata(new double[arr.capacity])
{	
	cout << "ArrayDataSmart 복사생성자" << endl;
	for (size_t i = 0; i < usedB; i++) {
		*(backdata + i) = *(arr.backdata + i);
	}
}

ArrayDataSmart::ArrayDataSmart(ArrayDataSmart&& arr) noexcept
	:ArrayData(arr), usedB(arr.usedB), backdata(arr.backdata)
{
	if (arr.backdata != nullptr) {
		arr.backdata = nullptr;
	}
	cout << "ArrayDataSmart 이동생성자" << endl;
}

ArrayDataSmart::ArrayDataSmart(const int& capacity, const int& used)
	: ArrayData(capacity, used), usedB(0), backdata(new double[capacity])
{
	cout << "ArrayDataSmart 생성자" << endl;
}

ArrayDataSmart::~ArrayDataSmart()
{
	if (backdata != nullptr) {
		delete[] backdata;
		backdata = nullptr;
	}
	cout << "ArrayDataSmart 소멸자" << endl;

}

void ArrayDataSmart::backup()
{
	if (backdata != nullptr) {
		usedB = used;
		for (size_t i = 0; i < usedB; i++) {
			backdata[i] = data[i];
		}
	}
}

void ArrayDataSmart::restore()
{
	if (backdata != nullptr) {
		used = usedB;
		for (size_t i = 0; i < usedB; i++) {
			data[i] = backdata[i];
		}
	}
}

ArrayDataSmart& ArrayDataSmart::operator=(const ArrayDataSmart& rhs)
{	
	cout << "ArrayDataSmart 대입연산자" << endl;
	if (this == &rhs) {
		return *this;
	}
	ArrayData::operator=(rhs);
	usedB = rhs.usedB;
	if (backdata != nullptr) {
		delete[] backdata;
		backdata = nullptr;
	}
	backdata = new double[rhs.capacity];
	//backdata = make_unique<double[]>(rhs.capacity);
	for (size_t i = 0; i < usedB; i++) {
		*(backdata+i) = *(rhs.backdata+i);
	}
	return *this;
}

ArrayDataSmart& ArrayDataSmart::operator=(ArrayDataSmart&& rhs) noexcept
{
	cout << "ArrayDataSmart 이동대입연산자" << endl;
	if (this == &rhs) {
		return *this;
	}
	ArrayData::operator=(move(rhs));
	usedB = rhs.usedB;
	if (backdata != nullptr) {
		delete[] backdata;
		backdata = nullptr;
	}
	backdata = rhs.backdata;
	if (rhs.backdata != nullptr) {
		rhs.backdata = nullptr;
	}
	return *this;
}
