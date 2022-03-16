//22.03.14 백준 20044 Project Teams
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n; // 팀의 수
    cin >> n;
    vector<int> studentVec((n*2), 0);
    int index = 0;
    for(int i = 0; i < (n * 2); i++){
        cin >> studentVec[index++];
    }
    sort(studentVec.begin(), studentVec.end());
    int maxScore = 200000;
    for(int i = 0; i < n; i++){
        if( maxScore > (studentVec[i] + studentVec[(n * 2) - (i + 1)]) ){
            maxScore = (studentVec[i] + studentVec[(n * 2) - (i + 1)]);
        }
    }
    cout << maxScore;
    return 0;
}
