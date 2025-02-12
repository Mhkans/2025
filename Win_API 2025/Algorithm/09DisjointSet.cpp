#include <iostream>
#include<vector>
#include <stack>
#include <queue>
using namespace std;

struct User {

	int guildID = 0;
};

void GuildSystem() {
	NaiveDisjointSet set(1000);

	set.Merge(555, 1);
	set.Merge(2, 1);
}

class NaiveDisjointSet {

public:
	NaiveDisjointSet(int n) {
		_parent = vector<int>(n, 0);
		for (int i = 0; i < n; i++) {
			_parent[i] = i;
		}
	}
	int FindLeader(int u) { //�־��ǰ�� �������Ǹ��� �ð����⵵ N
		if (u == _parent[u]) { //���� �ְ���
			return u;
		}
		int parent = _parent[u];
		return FindLeader(parent);
	}
	void Merge(int u, int v) {
		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);

		if (uLeader == vLeader) {//���� �̹� ���������ϰ��
			return;
		}
		_parent[uLeader] = vLeader;

	}
private:
	vector<int> _parent;
};

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
int main() {

	GuildSystem();

	return 0;
}