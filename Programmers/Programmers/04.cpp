//https://www.acmicpc.net/problem/11659
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
vector<int> v;
void Input() {
	int N, M;
	cin >> N>>M;
	
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
}
int main() {
	Input();

	return 0;
}