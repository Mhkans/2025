#include <iostream>
#include <vector>	
#include <algorithm>
#include<thread>

#include <atomic>
#include <mutex>
#include <Windows.h>
#include <queue>
using namespace std;

// CV : Condition Variable

queue<int> q;
mutex m;
condition_variable cv;

void Produce() {
	while (true) {

		{
			unique_lock<mutex> lg(m);
			q.push(100);
		}

		cv.notify_all();
		this_thread::sleep_for(chrono::milliseconds(1000));

	}
}

void Consume() {
	while (true) {
		unique_lock<mutex> lg(m);
		cv.wait(lg, []() {

			return !q.empty();
		});

		auto data = q.front();
		q.pop();
		cout << data << endl;
		cout << "Q Data : " << data << endl;
		cout << "Q Size : " << q.size() <<endl;

	}

}
int main()
{
	thread t1(&Produce);
	thread t2(&Consume);

	t1.join();
	t2.join();

	return 0;
}