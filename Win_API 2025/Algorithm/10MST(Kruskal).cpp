#include <iostream>
#include<vector>
#include <stack>
#include <queue>
using namespace std;

/*
���д�Ʈ�� : ��������� ���� , ����Ŭ�� ���� Ʈ��
���д�Ʈ���� ������ �������ִ�.

�̴ϸ� ���д� Ʈ�� : ���д� Ʈ�� �߿� �������� ����ġ�� ���� �ּ��� Ʈ��
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
	void Merge(int u, int v) {// ��ũ�� �������� ū������ ���յǴ°� �ð����⵵ ����
		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);

		if (uLeader == vLeader) {
			return;
		}

		if (_rank[uLeader] > _rank[vLeader]) { //vLeader�� ��ũ�� �׻�ũ�� ����
			std::swap(uLeader, vLeader);
		}
		_parent[uLeader] = vLeader; // uleader�� �׻� vLeader�ؿ� ����
	}


private:
	vector<int> _parent;
	vector<int> _rank;
};

void CreateGraph() {

    adjacent = vector<vector<int>>(7, vector<int>(7, -1));

    // ������� �׷��� A�� A�� ��ġ���(A)�� ���� ����.

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
                continue;  //����� ����
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
            //�̹� ���� ������ ���
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