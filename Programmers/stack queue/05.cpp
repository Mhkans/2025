//https://school.programmers.co.kr/learn/courses/30/lessons/42583

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
int 다리를 건너는중인 트럭의 무게 합 - 
vector<pair> 다리를 건너는 중인 트럭 , 경과시간 - 
vector 다리를 건넌 트럭들 - 

while() 종료조건 : 다리를 건넌 트럭 사이즈 == 주어진벡터 사이즈 -
time++; -
다리를 건너는 중인 트럭들 검사해서 경과시간 ++; if 경과시간 == bridge_length-1 다리를 지난 트럭으로 이동-
다리를 건너는 중인 트럭들 검사해서 무게의합 갱신-
if() 다리를 건너는 트럭 사이즈 >= bridge_length{ -
continue;
}
if 다리를 건너는 트럭의 무게합 + q.front > weight { - 
continue;
}
q.pop(); 다리를 건너는 중인 트럭에 원소 추가


*/
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 1;
    vector<pair<int, int>> crossing;
    vector<int> done;
    queue<int> q;
    int wSum = 0;
    
    for (auto& w : truck_weights) {
        q.push(w);
    }
    int first = q.front();
    q.pop();
    crossing.push_back({ first , 0 });
    while (true) {
        if (done.size() == truck_weights.size()) {
            break;
        }

        time++;
        wSum = 0;
        
        for (auto Iter = crossing.begin(); Iter != crossing.end();) {
            if (Iter->second == bridge_length-1) {
                done.push_back(Iter->first);
                Iter = crossing.erase(Iter);
            }
            else {
                wSum += Iter->first;
                Iter->second++;
                Iter++;
            }

        }
        
        if (crossing.size() >= bridge_length) {
            continue;
        }
        if (!q.empty()) {
            int temp = q.front();
            if (wSum + temp > weight) {
                continue;
            }
            q.pop();
            crossing.push_back({ temp , 0 });
        }
       
        
    }
    return time;
}

int main() {
    cout << solution(2,10,{ 7,4,5,6 });
    return 0;
}

