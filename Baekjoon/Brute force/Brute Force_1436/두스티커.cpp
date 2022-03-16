//22.03.14 백준 16937 두 스티커
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool checkSticker(pair<int,int> p1, pair<int,int> p2, int H, int W){
    int H1 = p1.first + p2.first;
    int W1 = (p1.second < p2.second) ? p2.second : p1.second;
    
    int H2 = p1.first + p2.second;
    int W2 = (p1.second < p2.first) ? p2.first : p1.second;

    int H3 = p1.second + p2.first;
    int W3 = (p1.first < p2.second) ? p2.second : p1.first;

    int H4 = p1.second + p2.second;
    int W4 = (p1.first < p2.first) ? p2.first : p1.first;

    if(H1 > W1){
        int temp = H1;
        H1 = W1;
        W1 = temp;
    }
    if(H2 > W2){
        int temp = H2;
        H2 = W2;
        W2 = temp;
    }
    if(H3 > W3){
        int temp = H3;
        H3 = W3;
        W3 = temp;
    }
    if(H4 > W4){
        int temp = H4;
        H4 = W4;
        W4 = temp;
    }
    if(H1 <= H && W1 <= W) return true;
    if(H2 <= H && W2 <= W) return true;
    if(H3 <= H && W3 <= W) return true;
    if(H4 <= H && W4 <= W) return true;
    
    return false;
}

int main(){
    int H, W, N;
    cin >> H >> W >> N;
    if(H > W){
        int t = H;
        H = W;
        W = t;
    }
    vector<pair<int,int>> stickerVec(N, {0,0});
    vector<bool> checked(N, false);
    checked[0] = true; checked[1] = true;
    int index = 0;
    int temp1, temp2;
    int paperSize = (H*W);
    int result = 0;
    if(N == 1){
        cout << result;
        return 0;
    } 
    for(int i = 0; i < N; i++){
        cin >> temp1 >> temp2;
        stickerVec[index].first = (temp1 < temp2) ? temp1 : temp2;
        stickerVec[index++].second = (temp1 < temp2) ? temp2 : temp1;
    }
    sort(checked.begin(), checked.end());
    pair<int,int> tempArr[2] = {{0,0}, {0,0}};
    do{ 
        index = 0;
        for(int i = 0; i < N; i++) if(checked[i]) tempArr[index++] = stickerVec[i];
        auto p1 = tempArr[0];
        auto p2 = tempArr[1]; 
        int tempSize = (p1.first*p1.second + p2.first*p2.second);
        if(tempSize <= paperSize && tempSize > result){
            if(checkSticker(p1, p2, H, W)) result = tempSize;
        }
    }while(next_permutation(checked.begin(), checked.end()));
    cout << result;
    return 0;
}
