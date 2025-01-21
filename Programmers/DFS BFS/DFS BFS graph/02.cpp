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

vector<bool> visited;
void DFS(int start , vector<vector<int>> comp) {
	visited[start] = true;
	for (int i = 0; i < comp.size(); i++) {
		if (comp[start][i] == 0) {
			continue;
		}
		if (visited[i]) {
			continue;
		}
		DFS(i, comp);
	}

}
int solution(int n, vector<vector<int>> computers) {
	visited.resize(n);
	int answer = 0;
	
	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			continue;
		}
		answer++;
		DFS(i,computers);
	}
	return answer;
}
int main() {

	cout<<solution(3, { {1,1,0},{1,1,0},{0,0,1} });
	cout << solution(5, { {1,1,0,0,0},{1,1,1,1,0},{0,1,1,0,0},{0,1,0,1,0 },{0,0,0,0,1} });

    return 0;
}