#include <iostream>
#include <string>
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

int* makeArray(const int SIZE) {
	int* temp = new int[SIZE];
	for (int i = 0; i < SIZE; i++) {
		temp[i] = rand() % 10;
	}
	return temp;
}

void printArray(int*(& arr),const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	int* arr = makeArray(10);
	printArray(arr, 10);

	delete[] arr;
	arr = nullptr;

	/*cout << typeid(arr).name() << endl;
	cout << typeid(arr[0]).name() << endl;
	cout << typeid(arr[0][0]).name() << endl;*/
	//int* parr = arr; //int[3][4]
	//int(*parr)[3][4] = &arr;
	//int(*parr)[4] = arr; //arr==> &arr[0] ==> & int[4]
	/*int col;
	cin >> col;
	int* parr = new int[col];
	delete[] parr;
	parr = nullptr;*/

	/*int row, col;
	cin >> row >> col;
	int*(*parr) = new int* [row];
	for (int i = 0; i < row; i++) {
		parr[i] = new int[col];
	}

	for (int i = 0; i < row; i++)
		delete[] parr[i];
	delete[] parr;
	parr = nullptr; 
	*/
	return 0;
}
