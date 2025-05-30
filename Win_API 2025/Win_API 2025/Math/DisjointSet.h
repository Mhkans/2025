#pragma once
#include"framework.h"
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
	void Merge(int u, int v) {
		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);

		if (uLeader == vLeader) {
			return;
		}

		if (_rank[uLeader] > _rank[vLeader]) { 
			std::swap(uLeader, vLeader);
		}
		_parent[uLeader] = vLeader;
	}


private:
	vector<int> _parent;
	vector<int> _rank;
};