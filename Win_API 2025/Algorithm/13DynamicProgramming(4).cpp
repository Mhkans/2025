#include <iostream>
#include<vector>

using namespace std;
//부분증가수열 LIS : Longest Increasing Sequence 의 최대 합 구하기

vector<int> memo = vector<int>(3001, 0);
//memo[인덱스] = 인덱스가 가진 최대 축적량
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