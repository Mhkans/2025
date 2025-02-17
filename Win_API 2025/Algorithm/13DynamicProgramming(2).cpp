#include <iostream>
#include<vector>

using namespace std;

vector<int> memo = vector<int>(3001, -1);
//3 -> 111 12 3 21
//4 -> 1111 112 31 22 13 121 211
//5 -> 11111 1112 1121 1211 2111 311 131 311 221 212 122 32 23 
int enchant(int n) {
    //ÀÎÃ¦Æ® n -> fn-1 + fn-2 + fn-3
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (n == 3) {
        return 4;
    }
    
    if (memo[n] != -1) {
        return memo[n];
    }
    else {
        memo[n] = enchant(n - 1) + enchant(n - 2) + enchant(n - 3);
    }
    return memo[n];
}
int main() {

    cout << enchant(5) << endl;
    return 0;
}