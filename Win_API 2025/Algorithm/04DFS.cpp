#include <iostream>
#include<vector>
#include <stack>
using namespace std;

vector<vector<bool>> adjacent;
vector<bool> visited;

void CreateGraph() {

    adjacent = vector<vector<bool>>(7, vector<bool>(7, false));
    visited = vector<bool>(7, false);

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
void DFS(int here) {
    visited[here] = true;
    cout << here << endl;
    for (int there = 0; there < adjacent.size(); there++) {

        if (here == there) {
            continue;

        }
        if (visited[there]) {
            continue;
        }
        if (!adjacent[here][there]) {
            continue;
        }
        DFS(there);
    }
}
int main()
{
    CreateGraph();
    DFS(0);

    return 0;
}