//https://school.programmers.co.kr/learn/courses/30/lessons/120882

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
vector<int> solution(vector<vector<int>> score) {
	vector<pair<int,int>> temp;
	vector<int> answer(score.size(), 0);
	unordered_map<int,int> um;
	//answer에 1. 스코어 평균 2. 순서
	//um에 개수 저장
	 
	for (int i = 0; i < score.size(); i++) {

		temp.push_back( {(score[i][0] + score[i][1]), i });
		um[temp[i].first]++;
	}
	std::sort(temp.begin(), temp.end(), [](const pair<int,int>& a ,const pair<int,int>& b ) {
		return a.first > b.first;
	});
	int index = 1;
	for (int i = 0; i < score.size();) {
		int tempNum = um[temp[i].first];
		for (int k = 0; k < tempNum; k++) {
			answer[temp[i].second] = index;
			i++;
		}
		
		index += tempNum;
		
	}
	return answer;
}

int main() {
	solution({ {80, 70}, { 70, 80}, { 30, 50}, { 90, 100}, { 100, 90}, { 100, 100}, { 10, 30} });
	return 0;
}