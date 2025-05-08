#include <iostream>
#include <vector>	
#include <algorithm>
#include<thread>
#include <Windows.h>
#include <atomic>
#include <mutex>
#include <queue>
#include <future>
#include <stack>
using namespace std;


#include "00Lock_Based_Stack.h"

//stack<int> s;
queue<int> q;
LockBasedStack<int> s;


void Push() {
	while (true) {
		int value = rand() % 100;
		s.push(value);

		this_thread::sleep_for(chrono::milliseconds(100));
	}
}
void Push_Q() {
	while (true) {
		int value = rand() % 100;
		q.push(value);

		this_thread::sleep_for(chrono::milliseconds(100));
	}
}
void Pop() {
	while (true) {
		//if (!s.empty()) {
		//	cout << s.top() << endl;
		//	s.pop();
		//}
		// 
		//int out = 0;
		//if (s.tryPop(out)) {
		//	cout << out << endl;
		//}

		int out = -1;
		s.waitPop(out);
		if (out != -1) {
			cout << out << endl;
		}
	}	

}
void Pop_Q() {
	while (true) {
		if (!q.empty()) {
			int out = q.front();
			q.pop();
			cout << out << endl;
		}
		
	}

}
int main()
{
	//thread t1(&Push);
	//thread t2(&Pop);
	//thread t3(&Pop);
	
	thread t1(&Push_Q);
	thread t2(&Pop_Q);
	thread t3(&Pop_Q);
	


	t1.join();
	t2.join();
	t3.join();

	return 0;
}