#include <iostream>
#include<vector>
#include <stack>
#include <queue>
using namespace std;

/*
스패닝트리 : 모든정점을 포함 , 사이클이 없는 트리
스패닝트리는 여러개 있을수있다.

미니멈 스패닝 트리 : 스패닝 트리 중에 간선들의 가중치의 합이 최소인 트리
*/

vector<vector<int>> adjacent;
vector<class Edge> edges;

class DisjointSet {

public:
	DisjointSet(int n) {
		_parent = vector<int>(n, 0);
		for (int i = 0; i < n; i++) {

			_parent[i] = i;
		}
		_rank = vector<int>(n, 1);
	}

	int FindLeader(int u) {
		if (u == _parent[u]) {
			return u;
		}
		int parent = _parent[u];
		return FindLeader(parent);
	}
	void Merge(int u, int v) {// 랭크가 작은쪽이 큰쪽으로 병합되는게 시간복잡도 유리
		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);

		if (uLeader == vLeader) {
			return;
		}

		if (_rank[uLeader] > _rank[vLeader]) { //vLeader의 랭크가 항상크게 세팅
			std::swap(uLeader, vLeader);
		}
		_parent[uLeader] = vLeader; // uleader가 항상 vLeader밑에 들어간다
	}


private:
	vector<int> _parent;
	vector<int> _rank;
};

void CreateGraph() {

    adjacent = vector<vector<int>>(7, vector<int>(7, -1));

    // 양방향은 그래프 A는 A와 전치행렬(A)와 서로 같다.

    //   0  1  2  3  4  5  6
    // 0 1  1  1  1  0  0  0
    // 1 1  1  0  0  1  0  0
    // 2 1  0  1  0  0  1  1
    // 3 1  0  0  1  0  0  0
    // 4 0  1  0  0  1  0  0
    // 5 0  0  1  0  0  1  0
    // 6 0  0  1  0  0  0  1

    adjacent[0][0] = 0;
    adjacent[0][1] = 1;
    adjacent[0][2] = 10;
    adjacent[0][3] = 5;

    adjacent[1][0] = 1;
    adjacent[1][1] = 0;
    adjacent[1][2] = 5;
    adjacent[1][4] = 5;

    adjacent[2][0] = 10;
    adjacent[2][1] = 5;
    adjacent[2][2] = 0;
    adjacent[2][5] = 3;
    adjacent[2][6] = 8;

    adjacent[3][0] = 5;
    adjacent[3][3] = 0;
    adjacent[3][6] = 10;

    adjacent[4][1] = 5;
    adjacent[4][4] = 0;

    adjacent[5][2] = 3;
    adjacent[5][5] = 0;

    adjacent[6][2] = 8;
    adjacent[6][3] = 10;
    adjacent[6][6] = 0;

}

struct Edge {

    int u;
    int v;
    int cost;

};
void CreateEdges() {

    for (int u = 0; u < adjacent.size(); u++) {

        for (int v = 0; v < adjacent.size(); v++) {
            if (adjacent[u][v] < 0) {
                continue;
            }
            if (u >= v) {
                continue;  //양방향 방지
            }
            Edge edge;
            edge.u = u;
            edge.v = v;
            edge.cost = adjacent[u][v];

            edges.push_back(edge);
        }
    }
}
vector<Edge> Kruskal() {

    vector<Edge> result;

    std::sort(edges.begin(), edges.end(), [](const Edge& a , const Edge& b) {

        return a.cost < b.cost;
    });
    DisjointSet set(adjacent.size());
    for (auto edge : edges) {

        int u = edge.u;
        int v = edge.v;
        if (set.FindLeader(u) == set.FindLeader(v)) {
            //이미 같은 집합인 경우
            continue;
        }
        result.push_back(edge);
        set.Merge(u, v);
    }
    return result;
}
int main() {

    CreateGraph();
    CreateEdges();

    auto mst = Kruskal();

    for (auto edge : mst) {
        cout << "U : " << edge.u << " V : " << edge.v << " Cost : " << edge.cost << endl;
    }
	return 0;
}