//22.03.14 백준 11509 풍선맞추기
#include <iostream>

int arrows[1000001] = {0, };

using namespace std;

int main(){
    int N;
    cin >> N;
    int temp;
    int arrowsCount = 0;
    while(N--){ 
        cin >> temp;
        if(arrows[temp + 1] != 0){
            arrows[temp + 1]--;
            arrows[temp]++;
        }
        else{
            arrows[temp]++;
            arrowsCount += 1;
        }
    }
    cout << arrowsCount;
    return 0;
}