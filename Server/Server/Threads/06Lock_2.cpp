#include <iostream>
#include <vector>	
#include <algorithm>
#include<thread>

#include <atomic>
#include <mutex>
#include <Windows.h>
#include <queue>
using namespace std;

// Event Lock : 생산-소비자(Producer - Consumer) 패턴

queue<int> q;
mutex m;
HANDLE handle; //윈도우 운영체제

void Produce() {
	while (true) {
		{
			unique_lock<mutex> lg(m);
			q.push(100);
		}
		SetEvent(handle);
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

void Consume() {
	while (true) {
		WaitForSingleObject(handle, INFINITE);
		unique_lock<mutex> lg(m);

		if (!q.empty()) {
			auto data = q.front();
			q.pop();
			cout << data << endl;
		}
	}

}
int main()
{
	handle = CreateEvent(NULL, FALSE, FALSE, NULL);

	thread t1(&Produce);
	thread t2(&Consume);

	t1.join();
	t2.join();

	CloseHandle(handle);
	return 0;
}