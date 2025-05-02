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
Thread Local Storage (TLS) : 스레드 고유의 변수를 스택영역에 만들어둠 
*/

thread_local int L_threadID;
void MySetThreadID(int id) {
	L_threadID = id;
	while (true) {
		cout << "Thread id : " << L_threadID << endl;
		this_thread::sleep_for(chrono::milliseconds(3000));
	}
}

int main()
{
	vector<thread> threads;
	int count = thread::hardware_concurrency();
	for (int i = 0; i < count; i++) {
		threads.push_back(thread(MySetThreadID, i));
	}
	for (auto& t : threads) {
		t.join();
	}

	return 0;
}