#include <iostream>
#include<vector>
#include <stack>
#include <queue>
using namespace std;

vector<vector<int>> adjacent;
vector<int> best; //가중치의 최소값을 베스트값으로 저장
vector<int> parent; 

struct Vertex {
    Vertex(int num , int cost) : vertexNum(num),cost(cost){}
    int vertexNum = 0;
    int cost = 0; //시작점부터의 가중치
    bool operator<(const Vertex& v) const
    {
        if (cost < v.cost)
            return true;
        return false;
    }

    bool operator>(const Vertex& v) const
    {
        if (cost > v.cost)
            return true;
        return false;
    }
};

void CreateGraph() {

    adjacent = vector<vector<int>>(7, vector<int>(7, -1));   
    parent = vector<int>(7, -1);

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

void Djikstra(int start) {

    best.resize(adjacent.size(), INT_MAX);
    priority_queue < Vertex, vector<Vertex>, greater<Vertex>> pq;

    Vertex startV = Vertex(start, 0);

    best[start] = 0;
    pq.push(startV);
    while (true) {
        if (pq.empty()) {
            break;
        }
        Vertex hereV = pq.top();
        pq.pop();
        if (best[hereV.vertexNum] < hereV.cost) {
            cout << "더 좋은 경로가 이전에 발견됨" << endl;
            cout << hereV.vertexNum << endl;
            cout << hereV.cost << endl;
            cout << best[hereV.vertexNum] << endl;
        }
        for (int there = 0; there < adjacent.size(); there++) {
            if (hereV.vertexNum == there) {
                continue;
            }
            if (adjacent[hereV.vertexNum][there] == -1) {
                continue;
            }
            int thereCost = hereV.cost + adjacent[hereV.vertexNum][there];

            if (thereCost >= best[there]) {
                continue;
            }
            Vertex thereV(there, thereCost);
            pq.push(thereV);
            best[there] = thereCost;
            parent[there] = hereV.vertexNum;

        }
    }
}

int main()
{
    CreateGraph();
    Djikstra(0);
    return 0;
}