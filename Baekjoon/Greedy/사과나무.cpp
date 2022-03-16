//22.03.14 백준 19539 사과나무
#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int count1L = 0;
    int count2L = 0;
    int tree;
    for(int i = 0; i < N; i++){
        cin >> tree;
        count2L += (tree/2);
        count1L += (tree%2);
    }
    //count1L = count2L 여야함.
   while(count2L >= 0){
       if(count2L == count1L){
           cout << "YES";
           return 0;
       }
       count2L -= 1;
       count1L += 2;
    }
    cout << "NO";
    return 0;
}