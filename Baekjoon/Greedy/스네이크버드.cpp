//22.03.14 백준 16435 스네이크버드
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, L;
    cin >> N >> L;
    vector<int> fruitVec(1000 , 10001);
    int index = 0;
    for(int i = 0; i < N; i++){
        cin >> fruitVec[index++];
    }
    sort(fruitVec.begin(), fruitVec.end());
    for(auto fruit : fruitVec){
        if(fruit <= L){
            L += 1;
        }
        else{
            break;
        }
    }
    cout << L;
    return 0;
}
