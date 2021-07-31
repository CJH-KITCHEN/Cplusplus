#pragma once
#include <memory>
using namespace std;
template<typename T>
class ArrayData
{
protected:
	//double* data=nullptr;
	unique_ptr<T[]> data;
	//shared_ptr<double[]> data;
	int capacity;
	int used;	
public:
	ArrayData();	
	ArrayData(const int& capacity, const int& used=0);
	ArrayData(ArrayData& arr);
	ArrayData(ArrayData&& arr)noexcept;
	ArrayData& operator=(ArrayData&& rhs) noexcept;
	ArrayData& operator=(const ArrayData& rhs);
	T& operator[](size_t num);
	const T& operator[](size_t num)const;
	
	template<typename T1>
	friend ostream& operator<< (ostream& out, const ArrayData<T1>& arr);

	~ArrayData();
	void addElement(const T& num);
	bool full() const;
	void emptyArray();
	void showData() const;

	
	int getCapacity() const {
		return this->capacity;
	};

	int getUsed() const {
		return this->used;
	};

	void setUsed() {
		used++;
	}
};

//ostream& operator<< (ostream& out, const ArrayData& arr);
#include "ArrayDataDef.h"

