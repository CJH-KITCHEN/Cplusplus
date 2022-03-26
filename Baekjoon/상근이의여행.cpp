//22.03.26 상근이의 여행 by HYEOKIKI

#include <iostream>

using namespace std;

int main(){
    int T; //test case의 수
    cin >> T;
    int N, M; //
    int temp1, temp2;
    while(T--){
        cin >> N >> M; //N은 국가의 수, M은 비행기의 종류
        for(int i = 0; i < M; i++){
            cin >> temp1 >> temp2;
        }
        cout << N-1 << endl;
    }
    return 0;
}