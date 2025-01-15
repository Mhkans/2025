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
vector<int> counts;
vector<bool> visited;

int DFS(int node , int k , vector<vector<int>> dungeons) {
    
    int count = 1;
    for (int i = 0; i < dungeons.size(); i++) {
        if (visited[i]) {
            continue;
        }
        if (dungeons[i][0] > k) {
            continue;
        }
        
        visited[i] = true;

        int nextK = k - dungeons[i][1];
        count += DFS(i, nextK, dungeons);
        visited[i] = false;
        
    }
    
    return count;
    
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    visited.resize(dungeons.size(), false);
    counts.resize(dungeons.size(), 0);
    for (int i = 0; i < dungeons.size(); i++) {
        if (dungeons[i][0] <= k) {
            visited[i] = true;
            counts[i] = DFS(i, k - dungeons[i][1], dungeons);
        }
    }
    answer = *(std::max_element(counts.begin(), counts.end()));

    return answer;
}
int main() {

    cout << solution(80, { {80,20},{50,40,},{30,10} });

	return 0;
}
