//https://school.programmers.co.kr/learn/courses/30/parts/12081
//3

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
bool solution(string s)
{

    queue<char> q;
    int count = 0;
    int num = 0;
    for (auto ch : s) {
        if (ch == '(') {
            q.push(ch);
        }
        else {
            if (!q.empty()) {
                q.pop();
            }
            else {
                return false;
            }
            
        }
    }    
   
    if (q.empty()) {
        return true;
    }
    else {
        return false;
    }

}

int main() {
    cout << solution("(()())");
    return 0;
}