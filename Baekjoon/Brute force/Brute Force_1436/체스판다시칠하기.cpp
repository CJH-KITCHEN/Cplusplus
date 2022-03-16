//22.03.13 백준 1018 체스판 다시 칠하기
#include <iostream>

#define FIO cin.tie(NULL), cout.tie(NULL) ,ios_base :: sync_with_stdio(false)
using namespace std;

char Board[50][50] = {'N', };

int checkSquare(int startRow, int startCol){
    int tempSum1 = 0;
    int tempSum2 = 0;
    for(int i = startRow; i < startRow + 8; i++){
        for(int j = startCol; j < startCol + 8; j++){
            if((i+j)%2 == 0){
                if(Board[i][j] == 'W') tempSum1 += 1; //B자리인데 W라는 뜻.
                else tempSum2 += 1; //W자리인데 B라는 뜻.
            }
            else{
                if(Board[i][j] == 'B') tempSum1 += 1; //W자리인데 B라는 뜻.
                else tempSum2 += 1; //B자리인데 W라는 뜻.
            }
        }
    }
    return (tempSum1 < tempSum2) ? tempSum1 : tempSum2;
}

int main(){
    FIO;
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Board[i][j];
        }
    }
    int maxRow, maxCol;
    int result = 32;
    maxRow = N - 7;
    maxCol = M - 7;
    for(int row = 0; row < maxRow; row++){
        for(int col = 0; col < maxCol; col++){
            int tempMin = checkSquare(row, col);
            if(tempMin < result) result = tempMin;
        }
    }
    cout << result;
}