//https://school.programmers.co.kr/learn/courses/30/lessons/42584

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
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> st;
    int index = 1;
    for (auto& p : prices) {
        st.push(p);
    }

    while (true) {
        if (st.empty()) {
            break;
        }
        int topN = st.top();
        st.pop();
        if (topN < st.top()) {
            index--;
        }
        for (int i = 0; i < answer.size() - index; i++) {
            answer[i]++;
        }
    }

    std::reverse(answer.begin(), answer.end());
    return answer;
}
//vector<int> solution(vector<int> prices) {
//    vector<int> answer;
//    for (int i = 0; i < prices.size()-1; i++) {
//        int count = 0;
//        int start = prices[i];
//        for (auto Iter = prices.begin() + i+1; Iter != prices.end();) {
//            if (*Iter >= start) {
//                count++;
//                Iter++;
//            }
//            else {
//                count++;
//                break;
//            }
//        }
//        answer.push_back(count);
//    }
//    answer.push_back(0);
//
//    return answer;
//}
int main() {
    solution({ 1, 2, 3, 2, 3 });
}