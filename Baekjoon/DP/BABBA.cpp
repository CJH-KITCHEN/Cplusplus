//22.03.26 9625번 BABBA by HYEOKIKI

#include <iostream>

using namespace std;

int main(){

    int K, A, B;
    int nextA, nextB;
    A = 1;
    B = 0;
    cin >> K;
    while(K--){
        nextA = B;
        nextB = B + A;
        A = nextA;
        B = nextB;
    }
    cout << nextA << " " << nextB;

    return 0;
}