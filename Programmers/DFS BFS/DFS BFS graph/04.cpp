//https://school.programmers.co.kr/learn/courses/30/parts/12421
//4
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
�ܾ� �޾Ƽ� ť���ְ� �̾Ƽ� ���ĺ� �Ѱ��� ���̳����� Ȯ��
���� �����ϸ� �湮ó���ϰ� ť�� �ֱ�
ť�� �ֺ�ų� Ÿ���� ã�������� �ݺ�
*/
//int solution(string begin, string target, vector<string> words) {
//	int answer = 0;
//	if (std::find(words.begin(), words.end(), target) == words.end()) {
//		return 0;
//	}
//	unordered_map<string, int> um; 
//	vector<pair<string, int>> wordsCount;
//	for (int i = 0; i < words.size(); i++) {
//		um[words[i]] = i;
//		wordsCount.push_back({ words[i],0 });
//	}
//	vector<bool> visited(words.size(), false);
//	queue<string> q;
//	
//	q.push(begin);
//
//	while (true) {
//		if (q.empty()) {
//			break;
//		}
//		int qSize = q.size();
//		for (int i = 0; i < qSize; i++) {
//			string temp = q.front();
//			q.pop();
//			if (target == temp) {
//				return answer;
//			}
//			//temp�������� ���ĺ��� �ϳ� �ٸ� ��带 �湮ó���ؼ� ť�� �ֱ�
//			for (int i = 0; i < words.size(); i++) {
//				if (visited[um[wordsCount[i].first]]) {
//					continue;
//				}
//				for (int j = 0; j < temp.size(); j++) {
//					
//					if (wordsCount[i].first[j] == temp[j]) {
//						wordsCount[i].second++;
//					}
//					if (wordsCount[i].second >= temp.size() - 1) {
//						q.push(wordsCount[i].first);
//						visited[um[wordsCount[i].first]] = true;
//						break;
//					}
//				}
//				wordsCount[i].second = 0;
//			}
//		}
//		answer++;
//	}
//	return 0;
//}

//dfs
unordered_map<string, int> um;
vector<pair<string, int>> wordsCount;
vector<bool> visited;
vector<int> Count;

void DFS(string currString, string target, vector<string> words, int num) {
	int countNum = 0;
	int accNum = num;
	if (currString == target) {
		Count.push_back(accNum);
	}

	visited[um[currString]] = true;
	for (int i = 0; i < words.size(); i++) {
		string temp = words[i];
		if (visited[um[temp]]) {
			continue;
		}
		//�湮�� ����� ���ڿ��� ���� ���ڿ� ��
		for (int j = 0; j < currString.size(); j++) {

			if (currString[j] == temp[j]) {
				countNum++;
			}
			if (countNum >= currString.size() - 1) {
				DFS(temp, target, words, accNum + 1);
				visited[um[temp]] = false;
			}
			
		}
		countNum = 0;
	}
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	if (std::find(words.begin(), words.end(), target) == words.end()) {
		return 0;
	}
	
	for (int i = 0; i < words.size(); i++) {
		um[words[i]] = i;
	}
	um[begin] = words.size();
	visited.resize(words.size()+1, false);
	Count.resize(words.size(), 0);
	
	DFS(begin, target,words,0);
	
	Count.erase(std::remove(Count.begin(), Count.end(), 0), Count.end());
	if (Count.empty()) {
		answer = 0;
	}
	else {
		answer = *(std::min_element(Count.begin(), Count.end()));
	}

	return answer;
	
}
int main() {

	solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }); //4

	return 0;
}