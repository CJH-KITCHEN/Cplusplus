#pragma once
#include "ArrayData.h"
class ArrayDataSmart :
	public ArrayData
{
private:
	//unique_ptr<double[]> backdata;
	double* backdata = nullptr;
	int usedB;
public:
	ArrayDataSmart();
	ArrayDataSmart(ArrayDataSmart& arr);
	ArrayDataSmart(ArrayDataSmart&& arr)noexcept;
	ArrayDataSmart(const int& capacity, const int& used = 0);
	~ArrayDataSmart();
	void backup();
	void restore();
	ArrayDataSmart& operator=(const ArrayDataSmart& rhs);
	ArrayDataSmart& operator=(ArrayDataSmart&& rhs) noexcept;
};

