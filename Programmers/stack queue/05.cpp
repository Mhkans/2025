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
int �ٸ��� �ǳʴ����� Ʈ���� ���� �� - 
vector<pair> �ٸ��� �ǳʴ� ���� Ʈ�� , ����ð� - 
vector �ٸ��� �ǳ� Ʈ���� - 

while() �������� : �ٸ��� �ǳ� Ʈ�� ������ == �־������� ������ -
time++; -
�ٸ��� �ǳʴ� ���� Ʈ���� �˻��ؼ� ����ð� ++; if ����ð� == bridge_length-1 �ٸ��� ���� Ʈ������ �̵�-
�ٸ��� �ǳʴ� ���� Ʈ���� �˻��ؼ� �������� ����-
if() �ٸ��� �ǳʴ� Ʈ�� ������ >= bridge_length{ -
continue;
}
if �ٸ��� �ǳʴ� Ʈ���� ������ + q.front > weight { - 
continue;
}
q.pop(); �ٸ��� �ǳʴ� ���� Ʈ���� ���� �߰�


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

