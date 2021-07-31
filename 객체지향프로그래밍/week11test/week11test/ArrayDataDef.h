#pragma once
#include "ArrayData.h"
#include <iostream>
using namespace std;
template<typename T>
ArrayData<T>::ArrayData() :ArrayData(3)
{
}

template<typename T>
ArrayData<T>::ArrayData(const int& capacity, const int& used) : capacity(capacity), used(used)
{
	cout << "생성자" << endl;
	//data = new double[this->capacity];
	data = make_unique<T[]>(this->capacity);
	//data = shared_ptr<double[]>(new double[this->capacity]);
}

template<typename T>
ArrayData<T>::ArrayData(ArrayData& arr) :ArrayData(arr.capacity, arr.used)
{
	cout << "복사생성자" << endl;
	//data = new double[arr.capacity];
	for (size_t i = 0; i < arr.used; i++) {
		//*(data + i) = *(arr.data + i);
		data[i] = arr.data[i];
	}
}


template<typename T>
ArrayData<T>::ArrayData(ArrayData&& arr)noexcept :capacity(arr.capacity), used(arr.used), data(move(arr.data)) {
	cout << "이동생성자" << endl;
	/*if (arr.data != nullptr)
		arr.data = nullptr;*/
}

template<typename T>
ArrayData<T>& ArrayData<T>::operator=(const ArrayData<T>& rhs)
{
	cout << "대입연산자" << endl; // a = b;
	if (this == &rhs) {
		return *this;
	}
	this->capacity = rhs.capacity;
	this->used = rhs.used;
	/*if (data != nullptr) {
		delete[] data;
		data = nullptr;
	}*/
	//data = new double[capacity];
	data.reset(new T[capacity]);
	for (size_t i = 0; i < used; i++) {
		data[i] = rhs.data[i];
		//*(data + i) = *(rhs.data + i);
	}
	return *this;
}

template<typename T>
ArrayData<T>& ArrayData<T>::operator=(ArrayData<T>&& rhs) noexcept
{
	cout << "이동대입연산자" << endl;
	this->capacity = rhs.capacity;
	this->used = rhs.used;
	data = move(rhs.data);
	/*if (data != nullptr) {
		delete[] data;
		data = nullptr;
	}*/
	data = move(rhs.data);
	/*data = rhs.data;
	rhs.data = nullptr;*/
	return *this;
}


template<typename T>
T& ArrayData<T>::operator[](size_t num)
{
	if (num >= 0 && num < capacity) {
		return data[num];
	}
	else {
		cout << "배열 참조 오류" << endl;
		exit(0);
	}

}

template<typename T>
const T& ArrayData<T>::operator[](size_t num) const
{
	if (num >= 0 && num < used) {
		return data[num];
	}
	else {
		cout << "배열 참조 오류" << endl;
		exit(0);
	}

}

template<typename T1>
ostream& operator<< (ostream& out, const ArrayData<T1>& arr) {
	for (size_t i = 0; i < arr.getUsed(); i++) {
		//out << arr[i] << "\t";
		out << arr.data[i] << "\t";
	}
	out << endl;
	return out;
}

template<typename T>
ArrayData<T>::~ArrayData()
{
	cout << "소멸자" << endl;
	/*if (data != nullptr) {
		delete[] data;
		data = nullptr;
	}*/
}

template<typename T>
void ArrayData<T>::addElement(const T& num)
{
	if (!full())
		data[used++] = num;
	else
		cout << "빈방이 없음\n";
}

template<typename T>
bool ArrayData<T>::full() const
{
	return this->capacity == this->used;
}

template<typename T>
void ArrayData<T>::emptyArray()
{
	this->used = 0;
}

template<typename T>
void ArrayData<T>::showData() const
{
	for (size_t i = 0; i < used; i++)
		cout << data[i] << " ";
	cout << endl;
}

