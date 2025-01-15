//https://school.programmers.co.kr/learn/courses/30/parts/12421
//2
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
/*
vector<vector<bool>> adj;
vector<bool> visited;
void DFS(int here) {

	visited[here] = true;
	cout << here << "방문" << endl;

	for (int there = 0; there < adj.size(); there++) {
		if (here == there) {//자기자신 확인
			continue;
		}
		if (!adj[here][there]) {//인접했는지 확인
			continue;
		}
		if (visited[there]) {//방문되었는지 확인
			continue;
		}
		DFS(there);
	}

}
int DFS_ALL() { //DFS를 이용해서 인접한 집단의 수를 아는방법

	int count = 0;
	for (int i = 0; i < adj.size(); i++) {

		if (!visited[i]) {
			count++;
			DFS(i);
		}
	}
	return count;
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    adj.resize(computers.size(), vector<bool>(n, false));
	visited.resize(n, false);
    for (int i = 0; i < computers.size(); i++) {

        for (int j = 0; j < computers[i].size(); j++) {

            if (computers[i][j] == 1) {

                adj[i][j] = true;
            }
        }
    }
	answer = DFS_ALL();
    return answer;
}*/
vector<vector<bool>> visited;
void DFS(vector<int> comp) {


}
int solution(int n, vector<vector<int>> computers) {
	visited.resize(n, vector<bool>(n, false));

}
int main() {

	cout<<solution(3, { {1,1,0},{1,1,0},{0,0,1} });

    return 0;
}