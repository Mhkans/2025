#include <iostream>
#include <vector>	
#include <algorithm>
#include<thread>

#include <atomic>
#include <mutex>
using namespace std;

/*
lock
mutex - 자물쇠 개념
RAII - Resource Acquisition Is Initialization ,객체가 생성될 때 자원을 획득하고, 객체가 소멸될 때 자원을 해제하는 디자인 패턴
*/

vector<int> v;
std::mutex m;

template<typename T>
class LockGuard {
public:
	LockGuard(T* mutex) :_mutex(mutex) { _mutex->lock(); }
	~LockGuard() { _mutex->unlock(); }


private:
	T* _mutex;

};


void Push(int num) {

	std::lock_guard<std::mutex> lg(m);
	v.push_back(num);
}
int main() {

	std::thread t1([]() {
		for (int i = 0; i < 10000; i++) {
			Push(i);
		}
	});
	std::thread t2([]() {
		for (int i = 0; i < 10000; i++) {
			Push(i);
		}
	});
	
	t1.join();
	t2.join();


	cout << v.size() << endl;


	return 0;
}