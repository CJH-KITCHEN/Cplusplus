//22.03.13 백준 2798 블랙잭
#include <iostream>

#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)
using namespace std;

int numArr[100] = {0, };

int main(){
    FIO;
    int N, M;
    cin >> N >> M;
    int index = 0;
    int sum = 0;
    int arrSize = N;
    int tempSum;
    while(N--) cin >> numArr[index++];
    for(int i = 0; i < arrSize; i++){
        for(int j = i + 1; j < arrSize; j++){
            for(int k = j + 1; k < arrSize; k++){
                tempSum = (numArr[i]+numArr[j]+numArr[k]);
                if(tempSum > M) continue;
                if(sum < tempSum) sum = tempSum;
            }
        }
    }
    cout << sum;
}