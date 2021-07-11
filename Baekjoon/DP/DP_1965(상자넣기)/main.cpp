#include <iostream>
#include <vector>

#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)

using namespace std;

int main() {
	FIO;
	int boxNum;
	int Max = 0;
	vector<int> listV;
	vector<int> dynamicV;
	cin >> boxNum;
	cin.clear();
	
	dynamicV.assign(boxNum, 1);

	for (int i = 0; i < boxNum; i++) {
		int temp;
		cin >> temp;
		listV.push_back(temp);
	}
	
	for (int i = 0; i < boxNum; i++) {
		int tempMax = 0;
		for (int j = 0; j < i; j++) {
			if (listV[j] < listV[i]) {
				if (dynamicV[j] > tempMax) {
					tempMax = dynamicV[j];
				}
				dynamicV[i] = tempMax + 1;
			}
		}
		if (Max < dynamicV[i]) {
			Max = dynamicV[i];
		}
	}
	cout << Max;
}