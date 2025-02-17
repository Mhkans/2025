//https://school.programmers.co.kr/learn/courses/30/lessons/43105
//정수삼각형
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

//[0][0] -> [1][0] , [1][1]
//[1][0] -> [2][0] , [2][1]
//[1][1] -> [2][1] , [2][2]
//[n][r] -> [n-1][r] 과 [n-1][r-1] 중에 범위에있는것끼리 비교해서 갱신

int accumulation(int y, int x, const vector<vector<int>>& t) {
    //0,0 에서 스타트 , 메모하는 데이터는 스타트지점부터 저기까지의 축적값
    //중간에 갱신 한번 해야함

    if (y == 0 && x == 0) {
        return t[0][0];
    }
    if (memo[y][x] != -1) {
        return memo[y][x];
    }
    else {
        if (x == 0) {
            memo[y][x] = accumulation(y - 1, x, t) + t[y][x];
        }
        else if (x == t[y].size() - 1) {
            memo[y][x] = accumulation(y - 1, x - 1, t) + t[y][x];
        }
        else {
            int temp1 = accumulation(y - 1, x - 1, t);
            int temp2 = accumulation(y - 1, x, t);
            memo[y][x] = std::max(temp1, temp2) + t[y][x];
        }
    }
    return memo[y][x];
}


int solution(vector<vector<int>> t) {
    memo.resize(t.size(), vector<int>(t.size(), -1));
    int answer = 0;
    for (int i = 0; i < t.size(); i++) {

        answer = std::max(answer, accumulation(t.size() - 1, i, t));
    }

    return answer;
}