//https://school.programmers.co.kr/learn/courses/30/lessons/42626
//더 맵게
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto num : scoville) {
        pq.push(num);
    }
    while (true) {
        if (pq.empty()) {
            return -1;
        }
        if (pq.top() >= K) {
            return answer;
        }
        if (pq.size() == 1) {
            if (pq.top() < K) {
                return -1;
            }
        }

        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int result = first + second * 2;
        pq.push(result);
        answer++;
    }
    return -1;
}

