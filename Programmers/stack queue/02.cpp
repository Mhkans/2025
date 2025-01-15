//https://school.programmers.co.kr/learn/courses/30/parts/12081
//2

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

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int num;
    
    for (auto& pNum : progresses) {

        pNum = 100 - pNum;
    }
    for (int i = 0; i < progresses.size(); i++) {
        if (progresses[i] % speeds[i] == 0) {
            q.push(progresses[i] / speeds[i]);
        }
        else {
            q.push((progresses[i] / speeds[i]) + 1);
        }
    }
    while (true) {

        if (q.empty()) {
            break;
        }
        int count = 1;
        num = q.front(); //7
        q.pop(); // 3 9
        while (true) {
            if (q.empty()|| q.front() - num > 0) {
                answer.push_back(count);
                break;
            }
            else {
                count++;
                q.pop();
            }
        }
    }
    return answer;
}
int main() {

    vector<int> v1 = { 93, 30, 55 };
    vector<int> v2 = { 1, 30, 5 };
    for (auto num : solution(v1,v2)) {
        cout << num;
    }

    return 0;
}