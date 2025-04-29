#include <iostream>
#include <vector>	
#include <algorithm>
#include<thread>

#include <atomic>
#include <mutex>
#include <Windows.h>

using namespace std;


//  - DeadLock : 교착상태
//    mutex가 2개 있는 상황

// - SpinLock
//    : CAS
// lock이 풀릴떄까지 쓰레드 무한 반복 대기 ,
// 단점 : 쓰레드가 쉬지않고 자원을 사용
// 
// - SleepLock
// lock이 잠겨있으면 Sleep시키고 다시 되돌아와서 확인 후 Sleep or Excute결정
// Sleep : 운영체제에서 thread를 재운다 , 
// 단점 : 자고 일어났을때 이미 다른 쓰레드가 점유할경우 오랜시간 일을 못할 수도있다
// 
// - EventLock
//    : CV


// Context Switching : 

int sum = 0;
mutex myMutex;

class spinLock {
public:
	void lock() {
		//비교하고 값을 대입하는 과정이 한번에 실행되어야함
		//CAS : Compare And Swap
		bool expected = false;
		bool desired = true;
		//compare_exchange_strong -> expected를 대입해주고 _locked를 desired로 , 예상된 결과이면 return true;
		/*
		
		*/
		while (_locked.compare_exchange_strong(expected, desired) == false) {
			
			expected = false;
			this_thread::sleep_for(chrono::microseconds(1000));
		}
		_locked.store(true);
	}
	void unlock() {
		_locked.store(false);
	}
private:
	atomic<bool> _locked = false;
};

spinLock _myLock;

void Add() {
	for (int i = 0; i < 10000; i++) {
		lock_guard<spinLock> lg(_myLock);
		sum++;
	}
}
void Sub() {
	for (int i = 0; i < 10000; i++) {
		lock_guard<spinLock> lg(_myLock);
		sum--;
	}
}

int main()
{
	thread t1(&Add);
	thread t2(&Sub);

	t1.join();
	t2.join();

	cout << sum << endl;

	return 0;
}