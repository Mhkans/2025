#include <iostream>
#include<vector>
#include<Windows.h>
using namespace std;

/*
1.���� ��ȭ�� nCr = n-1Cr-1 + n-1Cr
2.�������� : n == r || n == 0-> 1 , r ==1 -> n 
3.ĳ�ü��� (�޸������̼�) 
*/
vector<vector<int>> memo = vector<vector<int>>(31, vector<int>(31, -1));//3


int Combination(int n, int r) {
    if (n == r || n == 0) {//2
        return 1;
    }
    if (r == 1) {
        return n;
    }
    if (memo[n][r] != -1) {
        return memo[n][r];
    }
    else {
        memo[n][r] = Combination(n - 1, r - 1) + Combination(n - 1, r);//1
    }
    return memo[n][r];
}
int main() {
    
    cout << Combination(30, 15) << endl;
    return 0;
}