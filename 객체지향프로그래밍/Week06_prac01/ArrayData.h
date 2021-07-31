#pragma once
#include <memory>
using namespace std;

class ArrayData
{
private:			
	//double* data=nullptr;
	unique_ptr<double[]> data;
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
	double& operator[](size_t num);
	const double& operator[](size_t num)const;
	friend ostream& operator<< (ostream& out, const ArrayData& arr);

	~ArrayData();
	void addElement(const double& num);
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


