//https://school.programmers.co.kr/learn/courses/30/lessons/43105
//정수삼각형 2
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
vector<vector<int>> memo;

//마지막줄 호출되면 t[y][x]반환 , 윗줄 점화식 n[y][x] = max (n[y+1][x],n[y+1][x+1]) + t[y][x]
int accumulation(int y, int x, const vector<vector<int>>& t) {
    if (y >= t.size()-1) {
        return t[y][x]; 
    }
    if (memo[y][x] != -1) {
        return memo[y][x];
    }
    else {
        memo[y][x] = std::max(accumulation(y + 1, x, t), accumulation(y + 1, x + 1, t)) + t[y][x];
    }
    return memo[y][x];
}


int solution(vector<vector<int>> t) {
    memo.resize(t.size(), vector<int>(t.size(), -1));
    int answer = 0;
    answer = accumulation(0, 0, t);
    return answer;
}