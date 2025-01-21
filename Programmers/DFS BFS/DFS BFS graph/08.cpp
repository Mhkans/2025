//https://school.programmers.co.kr/learn/courses/30/lessons/87946
//ÇÇ·Îµµ
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


vector<bool> visited;
int maxNum = 0;
void DFS(vector<vector<int>> d, int k, int here, int num) {
    if (maxNum < num) {
        maxNum = num;
    }
    visited[here] = true;
    for (int i = 0; i < d.size(); i++) {
        if (visited[i]) {
            continue;

        }
        if (d[i][0] > k) {
            continue;
        }
        DFS(d, k - d[i][1], i, num + 1);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    visited.resize(dungeons.size(), false);
    dungeons.erase(std::remove_if(dungeons.begin(), dungeons.end(), [k](const vector<int>& a) {
        return a[0] > k;
    }), dungeons.end());
    for (int i = 0; i < dungeons.size(); i++) {

        DFS(dungeons, k, i, 1);

    }
    return maxNum;
}
int main() {

    cout << solution(80, { {90,10},{80,20},{50,40,},{30,10},{85,25} });

	return 0;
}
