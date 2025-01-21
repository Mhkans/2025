//https://school.programmers.co.kr/learn/courses/30/parts/12421
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
void DFS(int target, vector<int> numbers, int count, int& answer, int& num) {
    if (count == numbers.size()) {
        return;
    }
    int plusNum = num + numbers[count];
    if (target == plusNum && count == numbers.size() - 1) {
        answer++;
    }
    int minNum = num - numbers[count];
    if (target == minNum && count == numbers.size() - 1) {
        answer++;
    }
    DFS(target, numbers, count + 1, answer, plusNum);
    DFS(target, numbers, count + 1, answer, minNum);

}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    int acc = 0;

    DFS(target, numbers, 0, answer, acc);
    
    return answer;
}

int main() {

    cout << solution({ 4, 1, 2, 1 },4);

    return 0;
}