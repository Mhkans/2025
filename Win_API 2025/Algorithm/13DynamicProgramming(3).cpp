#include <vector>

using namespace std;
vector<vector<int>> t;
vector<vector<int>> memo = vector<vector<int>>(501, vector<int>(501, -1));
int tSize;
//마지막줄 호출되면 t[y][x]반환 , 윗줄 점화식 n[y][x] = max (n[y+1][x],n[y+1][x+1]) + t[y][x]
int accumulation(int y, int x) {
    if (y >= tSize - 1) {
        return t[y][x];
    }
    if (memo[y][x] != -1) {
        return memo[y][x];
    }
    else {
        memo[y][x] = std::max(accumulation(y + 1, x), accumulation(y + 1, x + 1)) + t[y][x];
    }
    return memo[y][x];
}


int solution(vector<vector<int>> tri) {
    t = tri;
    tSize = t.size();
    int answer = 0;
    answer = accumulation(0, 0);
    return answer;
}