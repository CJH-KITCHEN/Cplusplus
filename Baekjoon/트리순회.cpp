//22.03.26 트리 순회 by HYEOKIKI

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

string preS, inS, postS;
unordered_map<char, vector<char>> treeMap;

void preorder(char c){
    if(c == '.') return;
    preS += c; 
    preorder(treeMap[c][0]);
    preorder(treeMap[c][1]);
    return;
}

void inorder(char c){
    if(c == '.') return;
    inorder(treeMap[c][0]);
    inS += c;   
    inorder(treeMap[c][1]);
}

void postorder(char c){
    if(c == '.') return;
    postorder(treeMap[c][0]);
    postorder(treeMap[c][1]);
    postS += c;
    return;
}

int main(){
    int N; //이진 트리의 노드의 개수
    cin >> N;
    char temp1, temp2, temp3;
    while(N--){
        cin >> temp1 >> temp2 >> temp3;
        treeMap[temp1].push_back(temp2);
        treeMap[temp1].push_back(temp3);
    }
    preorder('A');
    inorder('A');
    postorder('A');
    cout << preS << endl << inS << endl << postS;
    return 0;
}