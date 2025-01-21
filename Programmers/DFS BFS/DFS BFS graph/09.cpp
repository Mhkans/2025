//https://school.programmers.co.kr/learn/courses/30/lessons/120956
//¿Ë¾ËÀÌ1
//https://school.programmers.co.kr/learn/courses/30/lessons/87946
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

vector<bool> visited;
vector<string> allPath;
unordered_map<int, string> um;
string temp = "";
void DFS(int here) {
    
    for (int i = 0; i < 4; i++) {
        if (visited[i]) {
            continue;
        }
        visited[i] = true;
        temp += um[i];
        if (find(allPath.begin(), allPath.end(), temp) == allPath.end()) {
            allPath.push_back(temp);
        }
        DFS(i);
        visited[i] = false;
        for (int j = 0; j < um[i].size(); j++) {
            temp.pop_back();
        }
    }
    
}
int solution(vector<string> babbling) {
    int answer = 0;
    um[0] = "aya";
    um[1] = "ye";
    um[2] = "woo";
    um[3] = "ma";
    visited.resize(4, false);
    DFS(0);
    for (auto bab : babbling) {
        if (find(allPath.begin(), allPath.end(), bab) != allPath.end()) {
            answer++;
        }
    }
    return answer;
}
int main() {

    cout << solution({ "ayaye", "uuuma", "ye", "yemawoo", "ayaa" });

    return 0;
}
