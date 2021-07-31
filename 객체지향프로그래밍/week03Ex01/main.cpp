#include <iostream>
#include <string>
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

int* makeArray(int& num) {
	cout << "학생 수 : ";
	cin >> num;
	int* temp = new int[num];
	for (int i = 0; i < num; i++) {
		cout << i + 1 << "번 학생 성적 : ";
		cin >> temp[i];
	}
	return temp;
}

void printSortedArray(int** (&arr), const int SIZE) {
	cout << "정렬 데이터 : ";
	for (int i = 0; i < SIZE; i++) {
		cout << *arr[i] << "\t";
	}
	cout << endl;
}


void printArray(int* (&arr), const int SIZE) {
	cout << "원본 데이터 : ";
	for (int i = 0; i < SIZE; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int** sortArray(const int* std, const int num) {
	 int**arr = new int* [num];
	 for (int i = 0; i < num; i++) {
		 arr[i] = const_cast<int*>(&std[i]);
	 }
	 for (int i = 0; i < num - 1; i++) {
		 for (int j = i + 1; j < num; j++) {
			 if (*arr[i] > * arr[j]) {
				 int* temp = arr[i];
				 arr[i] = arr[j];
				 arr[j] = temp;
			 }
		 }
	 }
	 return arr;
}


void deleteArray(int* (&arr)) {
	delete[] arr;
	arr = nullptr;
}

void deleteSortedArray(int** (&arr)) {
	delete[] arr;
	arr = nullptr;
}

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int num;
	int* std = makeArray(num);


	printArray(std, num);
	int** sortedStd = sortArray(std, num);
	printSortedArray(sortedStd, num);
	printArray(std, num);
	deleteArray(std);
	deleteSortedArray(sortedStd);
	if (std == nullptr) {
		cout << "int* 메모리 정리 끝~~~" << endl;
	}
	if (sortedStd == nullptr) {
		cout << "int** 메모리 정리 끝~~~" << endl;
	}


	return 0;
}
