//https://school.programmers.co.kr/learn/courses/30/lessons/120840
//구슬을 나누는 경우의 수
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <stack>
#include <queue>
#include <memory>

using namespace std;
vector<vector<unsigned long long>> memo;
int combination(int n, int r) {
    if (n == r || r == 0) {
        return 1;
    }
    if (memo[n][r] != -1) {
        return memo[n][r];
    }
    else {
        memo[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
    }
    return memo[n][r];
}
int solution(int balls, int share) {
    int answer = 0;
    memo.resize(balls + 1, vector<unsigned long long>(balls + 1, -1));
    answer = combination(balls, share);

    return answer;
}