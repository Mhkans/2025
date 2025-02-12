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
/*
사각형 범위 지정
상하좌우 이동가능 경로인지 판별
vec[i][0] -> x 시작 , vec[i][2] -> x끝
vec[i][1] -> y 시작 , vec[i][3] -> y끝
*/
//4방향
vector<pair<int, int>> way;

vector<vector<bool>> CreateMap(int maxX, int maxY , vector<vector<int>> rectangle) {
    vector<vector<bool>> map(maxX,vector<bool>(maxY,false));
    for (int t = 0; t < rectangle.size(); t++) {
        for (int i = rectangle[t][0]; i <= rectangle[t][2]; i++) {
            for (int j = rectangle[t][1]; j <= rectangle[t][3]; j++) {

                map[i][j] = true;
            }
        }
    }
    for (int t = 0; t < rectangle.size(); t++) {
        for (int i = rectangle[t][0] +1; i < rectangle[t][2]; i++) {
            for (int j = rectangle[t][1]+1; j < rectangle[t][3]; j++) {

                map[i][j] = false;
            }
        }
    }
    return map;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<pair<int, int>> debugV;
    way.push_back({ 1,0 });
    way.push_back({ 0,1 });
    way.push_back({ -1,0 });
    way.push_back({ 0,-1 });

    //2배 스케일링한 좌표가 필요함
    vector<vector<int>> rect_2;
    for (int i = 0; i < rectangle.size();i++) {
        
        for (int j = 0; j < rectangle[i].size(); j++) {

            rectangle[i][j]
        }
    }
    vector<vector<bool>> map = CreateMap(50 * 2, 50 * 2, rectangle);
    vector<vector<bool>> visited(50 * 2, vector<bool>(50 * 2, false));
    queue<pair<int,int>> q;
    q.push({ characterX,characterY });
    visited[q.front().first][q.front().second] = true;
    debugV.push_back({ characterX,characterY });
    while (true) {

        if (q.empty()) {
            break;
        }
        answer++;
        for (int i = 0; i < q.size(); i++) {
            auto currPos = q.front();
            q.pop();
            for (int i = 0; i < way.size(); i++) {
                auto nextPos = pair<int, int>(currPos.first + way[i].first, currPos.second + way[i].second);

                if (!map[nextPos.first][nextPos.second]) {
                    continue;
                }
                if (visited[nextPos.first][nextPos.second]) {
                    continue;
                }
                q.push(nextPos);
                //1,3 1,4 2,4 3,4 3,5 4,5 4,6 3,6 2,6 2,7 2,8 3,8 
                //4,8 4,9 5,9 6,9 6,8 7,8
                debugV.push_back(nextPos);
                visited[nextPos.first][nextPos.second] = true;
                if (nextPos.first == itemX && nextPos.second == itemY) {
                    return answer/2;
                }
            }
        }
       
    }

  

    return answer;
}
int main() {

    cout << solution({ {1, 1, 7, 4},{3, 2, 5, 5},{4, 3, 6, 9},{2, 6, 8, 8} }, 1, 3, 7, 8);
}
