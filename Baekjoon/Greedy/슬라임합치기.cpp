//22.03.14 백준 14241 슬라임 합치기
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    int N;
    int sum = 0;
    vector<int> scoreVec; 
    stack<int> st;
    cin >> N;
    while(N--){
        int temp;
        cin >> temp;
        scoreVec.push_back(temp);
    }
    sort(scoreVec.begin(), scoreVec.end());
    for(auto score : scoreVec){
        st.push(score);
    }
    while(st.size() != 1){
        int num1 = st.top();
        st.pop();
        int num2 = st.top();
        st.pop();
        sum += (num1*num2);
        st.push(num1 + num2);
    }
    cout << sum;
    return 0;
}
