//https://school.programmers.co.kr/learn/courses/30/lessons/84021
//06
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
//전치행렬 -> 회전된 도형 , dfs로 한개씩 다 넣어보고 백트래킹
//도형을 확정하는방법 : 상하좌우 판별해서 1이 이어져있으면 같은도형 
//범위기반for돌아서 나온값부터 탐색 시작 BFS

void CreateShapes(int startY,int startX , vector<vector<int>>& table) {
    //메인에서 for문을 돌아서 여기좌표에 도달하면 상하좌우 탐색으로 도형을 확정할거임

}

void TransposedMatrix(vector<vector<int>> shape) {

}
bool Cango(int x, int y , vector<vector<int>> table) {
    if (table[y][x] == 0) {
        return false;
    }
    return true;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -1;
    
    return answer;
}

int main() {



    return 0;
}