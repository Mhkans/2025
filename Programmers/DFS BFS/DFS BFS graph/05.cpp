//https://school.programmers.co.kr/learn/courses/30/lessons/87694
//5
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

vector<vector<bool>> path;

void Stamp(int startX, int startY, int endX, int endY, bool b) {
    for (int y = startY; y <= endY; y++) {
        for (int x = startX; x <= endX; x++) {
            path[x][startY] = b;
            path[x][endY] = b;
            path[startX][y] = b;
            path[endX][y] = b;
        }
    }
}
void CreateMap(vector<vector<int>> r) {
    path.resize(100, vector<bool>(100, false));
    for (int i = 0; i < r.size(); i++) {
        Stamp(r[i][0], r[i][1], r[i][2], r[i][3], true);
    }
    for (int i = 0; i < r.size(); i++) {
        Stamp(r[i][0] + 1, r[i][1] + 1, r[i][2] - 1, r[i][3] - 1, false);
    }
}
bool CanGo(pair<int, int> here) {

}
int solution(vector<vector<int>> r, int x, int y, int itemX, int itemY) {
    int answer = 0;
    vector<vector<int>> r2;
    for (auto rect : r) {
        vector<int> rectInfo;
        rectInfo.push_back(rect[0]);
        rectInfo.push_back(rect[1]);
        rectInfo.push_back(rect[3] * 2);
        rectInfo.push_back(rect[4] * 2);
    }
    CreateMap(r2);
    queue<pair<int, int>> q;
    q.push(pair<int, int>(x, y));
    while (true) {
        if (q.empty()) {
            return -1;
        }
        if (q.front() == pair<int, int>(itemX, itemY)) {
            break;
        }
        pair<int, int> here = q.front();
        q.pop();


    }
    return answer;
}
int main() {

    cout << solution({ {1, 1, 7, 4},{3, 2, 5, 5},{4, 3, 6, 9},{2, 6, 8, 8} }, 1, 3, 7, 8);
}
