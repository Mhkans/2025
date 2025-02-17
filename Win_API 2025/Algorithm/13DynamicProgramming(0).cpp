#include <iostream>
#include<vector>
#include<Windows.h>
using namespace std;
/*
��ȭ�� ã�� -> �������� üũ -> �޸������̼� -> �� ���ϱ�

��ȭ�� ã�� : ������ ���� ���� ���� ���� ���Ҷ� ���δ� -> ���� �κ� ����
�޸������̼� : ������ ���� ���� ����ص���

*/
vector<int> memo;

int Fibonacci(int n) {
    
    if (n == 0 || n == 1) {
        return 1;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int Fibonacci_DP(int n) {
    
    if (n == 0 || n == 1) {
        return 1;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    else {
        memo[n] = Fibonacci_DP(n - 1) + Fibonacci_DP(n - 2);
    }
    return memo[n];
}
int main() {
    memo.resize(100, -1);

    __int64 start = GetTickCount64();
    cout << Fibonacci(40) << endl;
    __int64 end = GetTickCount64();

    cout <<"Fibonacci :" << end - start << " ms " << endl;

    start = GetTickCount64();
    cout << Fibonacci_DP(40) << endl;
    end = GetTickCount64();

    cout <<"Fibonacci_DP :" << end - start << " ms " << endl;

    return 0;
}