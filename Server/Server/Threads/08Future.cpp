#include <iostream>
#include <vector>	
#include <algorithm>
#include<thread>

#include <atomic>
#include <mutex>
#include <queue>
#include <future>
using namespace std;

/*
Calculate하는데 EventLock SpinLock SleepLock 을 걸고 멀티쓰레드환경에서 작업하는 환경을 최소화
작은 작업들을 하는데 비동기 방식이필요할 경우 future를 사용
*/
__int64 Calculate() {

	__int64 sum = 0;

	for (int i = 0; i < 100'0000; i++) {
		sum += i;
	}
	return sum;
}

void PromiseWorker(promise<string>& promise) {
	promise.set_value("Set Message");
}

void TaskWorker(packaged_task<int64_t()>& task) {
	task(); // packaged_task 호출
}
int main()
{
	/*
	future : 비동기 방식으로 future에서 할 일을 만들고 나중에 반환
	launch :: deferred : 지연시켜서 나중에 실행
	launch :: async : 쓰레드하나를 파서 실행
	*/
	{
		future<__int64> f = async(launch::async, Calculate);
		int temp = 0;

		__int64 sum = f.get();

		cout << sum << endl;
	}
	/*
	promise : 동기 시점을 제공한다
	*/
	{
		promise<string> promise;
		future<string> future = promise.get_future();//future에 반환하겠다 라는 약속

		thread t(PromiseWorker, ref(promise));
		future_status status = future.wait_for(chrono::milliseconds(10)); //0.01초 동안 대기하면서 future의 상태 확인

		if (status == future_status::ready) {
			//future가 세팅이 잘 되어있다 -> 즉시 실행 가능
			string value = future.get();
			cout << "Promise Value: " << value << endl;
		}
		else {
			cout << "Promise timed out!" << endl;
		}
		t.join();
	}

	//packaged_task : 일감(function)을 만들어서 넘겨주는 방법
	{
		packaged_task<__int64()> task(Calculate);
		future<__int64> f_result = task.get_future();

		thread t(TaskWorker,ref(task));

		__int64 sum = f_result.get();
		cout << sum << endl;

		t.join();
	}


	return 0;
}