//22.03.26 피보나치 함수 by HYEOKIKI

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T; //test case의 수
    int N;

    vector<vector<int>> fiboVec(41, vector<int>(2,0)); //fiboVec에 있는 벡터의 첫번째 원소 : 0의 개수, 두번째 원소 : 1의 개수
    fiboVec[0][0] = 1;
    fiboVec[0][1] = 0;
    fiboVec[1][0] = 0;
    fiboVec[1][1] = 1;
    
    //fiboVec 초기화
    for(int i = 2; i < 41; i++){
        fiboVec[i][0] = fiboVec[i-1][0] + fiboVec[i-2][0];
        fiboVec[i][1] = fiboVec[i-1][1] + fiboVec[i-2][1];
    }
    cin >> T;
    while(T--){
        cin >> N;
        cout << fiboVec[N][0] << " " << fiboVec[N][1] << endl;
    }
    return 0;
}