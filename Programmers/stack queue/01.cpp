//https://school.programmers.co.kr/learn/courses/30/parts/12081
//1

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

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    stack<int> s;
    for (int i = 0; i < arr.size(); i++) {
        if (!s.empty() && arr[i] == s.top()) {
            continue;
        }
        else {
            s.push(arr[i]);
        }
    }
    while (true) {
        if (s.empty()) {
            break;
        }
        answer.push_back(s.top());
        s.pop();
    }
    std::reverse(answer.begin(), answer.end());


    return answer;
}
vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    auto Iter = unique(arr.begin(), arr.end());

    arr.erase(Iter, arr.end());
    return arr;
}
int main() {

    vector<int> v = { 1,1,3,3,0,1,1 };
    for (auto num : solution(v)) {
        cout << num;
    }

	return 0;
}