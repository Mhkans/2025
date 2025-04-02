#include <iostream>
#include<vector>

using namespace std;

vector<int> memo = vector<int>(301, -1);
vector<int> v;
int N;
void Input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
}
int DP(int n, vector<int>& v,int count) {
    if (n== v.size() - 1) {
        return v[n];
    }
    if (n + 1 == v.size() - 1 && count == 2) {
        return 0;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    else {
        int temp1 =0;
        int temp2=0;
        if (count == 2) {
            temp2 = DP(n + 2, v, 1);
        }
        else {
            temp1 = DP(n + 1, v, ++count) + v[n];
            temp2 = DP(n + 2, v, 1)+v[n];
        }
        memo[n] = std::max(temp1, temp2);
    }
    return memo[n];
}
int main() {
    Input();
    int answer = 0;
    answer = std::max(DP(0, v, 1), DP(1, v, 1));
    cout << answer;
    return 0;
}
