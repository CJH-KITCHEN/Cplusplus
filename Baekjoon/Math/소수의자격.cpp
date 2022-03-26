//22.03.26 6219번 소수의자격 by HYEOKIKI

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int primeArr[4000001] = {0, }; //1이 소수라는 뜻, 0은 소수 x

int main(){
    int A, B, D;    
    int result = 0;
    int arrSize = 4000001;
    cin >> A >> B >> D;

    //primeArr 초기화
    for(int i = 0; i < arrSize; i++) primeArr[i] = 1;
    //소수 체크
    for(int i = 2; i < sqrt(arrSize); i++){
        if(primeArr[i]){
            for(int j = 2; j*i < arrSize; j++){
                if(primeArr[j*i]) primeArr[j*i] = 0;
            }
        }
    }
    //숫자 유무 체크
    for(int num = A; num <= B; num++){
        if(primeArr[num]){
            string target = to_string(num);
            string stringD = to_string(D);
            if(target.find(stringD) != string::npos) result += 1;
        }
    }
    cout << result;
    return 0;
}