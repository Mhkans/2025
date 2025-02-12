//https://school.programmers.co.kr/learn/courses/30/parts/12421
//6 여행경로
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
//모든경로를 통과하는 경우의 수를 모두 찾은후에 직접 sort 
//bfs
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<pair<string, int>> ticketIndex; // 방문한 티켓 출발지점의 순서를 마킹

    for (int i = 0; i < tickets.size(); i++) {
        ticketIndex.push_back(pair<string, int>(tickets[i][0], i));
    }
    vector<bool> visited(tickets.size(), false);
    queue<pair<string, string>> q;

    q.push(pair<string, string>(tickets[0][0], tickets[0][1]));
    visited[ticketIndex[0].second] = true;
    return answer;
}
int main() {



	return 0;
}