#include <iostream>
#include <vector>	
#include <algorithm>
#include<thread>

using namespace std;

//1. 프로세스 vs 스레드 ?
//메모리에 올라와있는 프로그램 , 프로세스 내에서 공용변수에 접근해서 작업하는 단위

//2. cpu 코어 vs 스레드 상관관계

void HelloThread() {
	cout << "Hello Thread" << endl;
}
int sum = 0;

void AddSum() {
	for (int i = 0; i < 10000; i++) {
		sum++;
	}
}
void SubSum() {
	for (int i = 0; i < 10000; i++) {
		sum--;
	}
}
int main() {
	thread t1(&AddSum);
	thread t2(&SubSum);

	t1.join();
	t2.join();

	cout << sum << endl;


	/*
	join : 스레드가 끝날떄까지 대기
	joinable : join이 가능한가
	get_id : 스레드 아이디
	detach : 스레드 분리
	hardware_concurrency : 현재 운용가능한 스레드 개수
	*/
	return 0;
}