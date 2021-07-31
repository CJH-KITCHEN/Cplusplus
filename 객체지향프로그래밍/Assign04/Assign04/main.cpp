#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

namespace CJH {
	void printName() {
		cout << "201711430 컴퓨터공학부 차준혁" << endl << endl;
	}
}

template <typename T>
int search(T* arr, int N, T t) {
	cout << "첫번째 템플릿" << endl;
	for (int i = 0; i < N; i++) {
		if (t == arr[i]) {
			return i;
		}
	}
	return -1;
}

template<typename T1, typename T2>
int search(T1* arr, int N, T2* t){
	cout << "2번째 템플릿" << endl;

	for (int i = 0; i < N; i++) {
		if (t == arr[i]) {
			return i;
		}
	}
	return -1;
}
template<>
int search(Student* arr, int N, const char* t) {
	cout << "3번째 템플릿" << endl;

	for (int i = 0; i < N; i++) {
		if (t == arr[i].getName()) {
			return i;
		}
	}
	return -1;
}


int main() {
	CJH::printName();
	int arr[5] = { 5,4,3,2,1 };
	int idx1 = search(arr, 5, 3);
	if (idx1 != -1) {
		cout << arr[idx1] << endl;
	}

	string id[3] = { "greenjoa1", "greenjoa2", "greenjoa3" };
	int idx2 = search(id, 3, "greenjoa2");
	if (idx2 != -1) {
		cout << id[idx2] << endl;
	}
	
	Student std[3] = { Student("greenjoa1", 70), Student("greenjoa2", 50), Student("greenjoa3", 80)};
	
	int idx3 = search(std, 3, "greenjoa2");
	if (idx3 != -1) {
		cout << std[idx3] << endl;
	}

	int idx4 = search(std, 3, Student("greenjoa3", 80));
	if (idx4 != -1) {
		cout << std[idx4] << endl;
	}
}