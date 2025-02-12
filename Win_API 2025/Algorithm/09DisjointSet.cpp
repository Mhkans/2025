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
	int FindLeader(int u) { //최악의경우 모든원소의리더 시간복잡도 N
		if (u == _parent[u]) { //내가 최고리더
			return u;
		}
		int parent = _parent[u];
		return FindLeader(parent);
	}
	void Merge(int u, int v) {
		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);

		if (uLeader == vLeader) {//둘이 이미 같은집합일경우
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
int main() {

	GuildSystem();

	return 0;
}