//https://school.programmers.co.kr/learn/courses/30/parts/12421
//6 ������
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
//����θ� ����ϴ� ����� ���� ��� ã���Ŀ� ���� sort 
//bfs
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<pair<string, int>> ticketIndex; // �湮�� Ƽ�� ��������� ������ ��ŷ

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