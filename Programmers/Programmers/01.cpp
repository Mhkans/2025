//https://school.programmers.co.kr/learn/courses/30/lessons/42861
//미니멈 스패닝 트리 크루스칼 
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
class DisJointSet
{
public:
	DisJointSet(int n)
	{
		_parent = vector<int>(n, 0);
		_rank = vector<int>(n, 1);

		for (int i = 0; i < n; i++)
		{
			_parent[i] = i;
		}
	}

	int FindLeader(int u)
	{
		if (u == _parent[u])
			return u;

		int parent = _parent[u];
		return FindLeader(parent);
	}

	void Merge(int u, int v)
	{
		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);

		if (uLeader == vLeader)
			return;

		if (_rank[uLeader] > _rank[vLeader])
		{
			std::swap(uLeader, vLeader);
		}

		_parent[uLeader] = vLeader;

		if (_rank[uLeader] == _rank[vLeader])
			_rank[vLeader]++;
	}

private:
	vector<int> _parent;
	vector<int> _rank;
};
struct Edge {
	int u;
	int v;
	int cost;
};
int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	if (costs.size() <= 0) {
		return 0;
	}
	//1.costs를 통해 edges에 edge 넣고 관리하기 2.DisJointSet leader비교해서 집합 연결시키기

	vector<Edge> edges;
	for (auto& cost : costs) {
		Edge edge;
		edge.u = cost[0];
		edge.v = cost[1];
		edge.cost = cost[2];

		edges.push_back(edge);
	}
	std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {

		return a.cost < b.cost;
	});

	DisJointSet set(n);

	for (auto& edge : edges) {
		int u = edge.u;
		int v = edge.v;
		if (set.FindLeader(u) == set.FindLeader(v)) {
			continue;
		}
		set.Merge(u, v);
		answer += edge.cost;
	}


	return answer;
}

int main() {
	cout << solution(4, { {0, 1, 1},{0, 2, 2},{1, 2, 5},{1, 3, 1},{2, 3, 8} });
	return 0;
}