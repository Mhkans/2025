//https://school.programmers.co.kr/learn/courses/30/parts/12081
//4

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
int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int, int>> num;
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++) {
        q.push({ priorities[i] , i });
    }
   
    std::sort(priorities.begin(), priorities.end(),less<int>());
    while (true) {
        if (priorities.empty()) {
            break;
        }
        auto temp = q.front();

        if (priorities.back() != temp.first) {
            q.pop();
            q.push(temp);
        }
        else {
            priorities.pop_back();
            q.pop();
            num.push_back(temp);
        }
    }
    for (int i = 0; i < num.size(); i++) {
        num[i].first = i+1;
    }
    for (auto number : num) {
        if (number.second == location) {
            answer = number.first;
        }
    }
    return answer;
    
}

int main() {
    cout << solution({ 1, 1, 9, 1, 1, 1 }, 0); //1
   
	return 0;
}