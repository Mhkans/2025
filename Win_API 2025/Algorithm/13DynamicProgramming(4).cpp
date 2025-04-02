#include <iostream>
#include<vector>

using namespace std;
//부분증가수열 LIS : Longest Increasing Sequence 의 최대 합 구하기
vector<int> memo = vector<int>(1001, -1);
int LIS(int n , vector<int>& v) {
    if (n == v.size() - 1) {
        return v[n];
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = v[n];
    for (int i = n; i < v.size(); i++) {
        if (v[i] <= v[n]) {
            continue;
        }
        memo[n] = std::max(memo[n], LIS(i, v) + v[n]);
    }
    return memo[n];
}
int main() {
    
    vector<int> v = {20,10,30,40,10};
    v = { 5,4,3,2,1 };
    int answer = 0;
    for (int i = 0; i < v.size(); i++) {
        answer = std::max(answer, LIS(i, v));
    }
    cout << answer;
    return 0;
}