//
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<bool> visited;
vector<string> path;
vector<string> DFS(vector<vector<string>> t, unordered_map<string, int> um, string here) {
    if (path.size() == t.size() - 1) {
        return path;
    }
    int hereNum = um[here];
    visited[hereNum] = true;
    for (int i = 0; i < t.size(); i++) {
        if (i == hereNum) {
            continue;
        }
        if (visited[i]) {
            continue;
        }
        if (t[hereNum][1] == t[i][0]) {
            path[hereNum] = here;
            DFS(t, um, t[i][0]);
            visited[hereNum] = false;
            path[hereNum] = "";
        }
    }
}


vector<string> solution(vector<vector<string>> t) {
    vector<string> answer;
    sort(t.begin(), t.end(), [](vector<string> str1, vector<string> str2) {
        if (str1[0] < str2[0]) {
            if (str1[1] < str2[1]) {
                return true;
            }
            else {
                return false;
            }
        }
        return false;

    });
    path = vector<string>(t.size());
    visited = vector<bool>(t.size(), false);
    unordered_map<string, int> um;

    for (int i = 0; i < t.size(); i++) {
        um[t[i][0]] = i;
    }
    answer = DFS(t, um, t[0][0]);

    //어차피 마지막은 무조건 도착가능
    return path;
}