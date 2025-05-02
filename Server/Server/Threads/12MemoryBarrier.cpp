#include <iostream>
#include <vector>	
#include <algorithm>
#include<thread>
#include <Windows.h>
#include <atomic>
#include <mutex>
#include <queue>
#include <future>
using namespace std;


/*
메모리 정책
memory_order :: relaxed -> 코드재배치 O 메모리 가시성 해결 X
memory_order :: seq_cst -> 코드재배치 X 메모리 가시성 해결 O
memory_order :: acquire , release -> 절취선

*/
atomic<bool> ready;
int value; 


void Produce() {
	value = 10;
	ready.store(true,memory_order_release); // 이후에는 코드재배치를 X 
}

void Consume() {
	while (ready.load(memory_order_acquire)==false) {
		
	}
	cout << value << endl;
}

int main()
{
	thread t1(&Produce);
	thread t2(&Consume);

	t1.join();
	t2.join();

	return 0;
}