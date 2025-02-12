#include <iostream>
#include<vector>
#include <queue>
using namespace std;

vector<vector<bool>> adjacent;
vector<bool> discovered;
vector<int> parent; //최단거리 찾기

void CreateGraph() {

    adjacent = vector<vector<bool>>(7, vector<bool>(7, false));
    discovered = vector<bool>(7, false);
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

    adjacent[0][0] = true;
    adjacent[0][1] = true;
    adjacent[0][2] = true;
    adjacent[0][3] = true;

    adjacent[1][0] = true;
    adjacent[1][1] = true;
    adjacent[1][4] = true;

    adjacent[2][0] = true;
    adjacent[2][2] = true;
    adjacent[2][5] = true;
    adjacent[2][6] = true;

    adjacent[3][0] = true;
    adjacent[3][3] = true;

    adjacent[4][1] = true;
    adjacent[4][4] = true;

    adjacent[5][2] = true;
    adjacent[5][5] = true;

    adjacent[6][2] = true;
    adjacent[6][6] = true;


}
void BFS(int start) {
    discovered[start] = true;
    parent[start] = start;
    queue<int> q;
    q.push(start);

    while (true) {

        if (q.empty()) {

            break;

        }

        int here = q.front();
        cout << here << endl;
        q.pop();
        
        for (int there = 0; there < adjacent.size(); there++) {
            if (here == there) {
                continue;
            }
            if (!adjacent[here][there]) {
                continue;
            }
            if (discovered[there]) {
                continue;
            }
            q.push(there);
            discovered[there] = true;
            parent[there] = here;
        }
    }
}
int main()
{
    CreateGraph();
    BFS(0);

    //0 에서 6 까지의 거리
    int distacne = 0;
    int Parent = 6;
    while (true) {
        Parent = parent[Parent];
        distacne++;
        if (Parent == parent[Parent]) {
            break;
        }
    }
    cout << distacne << endl;
    return 0;
}