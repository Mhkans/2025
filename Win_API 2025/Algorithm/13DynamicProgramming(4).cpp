#include <iostream>
#include<vector>

using namespace std;
//�κ��������� LIS : Longest Increasing Sequence �� �ִ� �� ���ϱ�

vector<int> memo = vector<int>(3001, 0);
//memo[�ε���] = �ε����� ���� �ִ� ������
int LIS(int n , vector<int> v) {
    if (n >= v.size()) {
        return 0;
    }
    if (v[n] < v[n + 1]) {
        memo[n] = LIS(n + 1, v) + v[n];
    }
    else {
        memo[n] += v[n];
    }
    return memo[n];
}
int main() {
    vector<int> v = {20,10,30,40,10};
    cout << LIS(0, v);
    return 0;
}