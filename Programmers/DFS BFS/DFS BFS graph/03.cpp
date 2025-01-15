//https://school.programmers.co.kr/learn/courses/30/parts/12421
//3
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


int solution(vector<vector<int>> maps)
{
	int answer = 0;

	vector<vector<bool>> visited;
	queue<pair<int,int>> q;
	vector<vector<pair<int,int>>> parents;

	visited.resize(maps.size(), vector<bool>(maps[0].size(), false));
	parents.resize(maps.size(), vector<pair<int, int>>(maps[0].size(), { -1,-1 }));
	
	pair<int, int> nextStep[4] =
	{
		pair<int,int>{0, -1},
		pair<int,int>{-1, 0},
		pair<int,int>{0,1},
		pair<int,int>{1,0}
	};
	pair<int, int> start = { 0,0 };
	visited[start.first][start.second] = true;
	parents[start.first][start.second] = start;
	q.push(start);
	
	while (true) {
		if (q.empty()) {
			answer = -1;
			break;
		}
		pair<int, int> here = q.front();
		q.pop();
		if (here.first == maps.size()-1 && here.second == maps[0].size()-1) {
			pair<int, int> next = here;
			while (true) {
				if (next.first == start.first && next.second == start.second) {
					answer++;
					return answer;
				}
				next = parents[next.first][next.second];
				
				answer++;
				
			}
		}
		

		for (int i = 0; i < 4; i++) {
			pair<int, int> nextstep;
			nextstep.first = here.first + nextStep[i].first;
			nextstep.second = here.second + nextStep[i].second;

			if (nextstep.first >= maps.size() || nextstep.second >= maps[0].size() || nextstep.first < 0 || nextstep.second < 0) {
				continue;
			}
			if (maps[nextstep.first][nextstep.second] == 0) {
				continue;
			}
			if (visited[nextstep.first][nextstep.second]) {
				continue;
			}

			visited[nextstep.first][nextstep.second] = true;
			parents[nextstep.first][nextstep.second] = here;
			q.push(nextstep);


		}
	}
	
	


	return answer;
}
int main() {

	cout << solution({ {1, 0, 1, 1, 1},{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 1},{0, 0, 0, 0, 1} });

	return 0;
}