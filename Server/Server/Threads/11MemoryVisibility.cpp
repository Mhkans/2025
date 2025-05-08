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
코드 재배치가 발생하는 이유
-> CPU 파이프라인

Fetch : 읽기
Decode : 해석
Excute : 실행
Memory Access : 메모리접근


메모리가시성 문제
1. CPU의 캐시들이 독립적으로 저장하기 때문에 실행순서를 보장받지 못하는것
->cpu들이 다른값을 볼수있으므로
2. 가시성을 해결하기위해서 atomic을 사용
->모든 스레드들이 해당변수의 동일한 수정순서를 관찰한다
*/

int x = 0;
int y = 0;
int r1 = 0;
int r2 = 0;

volatile bool ready;

void Thread_01() {

	while (!ready) {

	}
	y = 1; //Store y
	r1 = x;//Load x

	//만약에 캐시에 앞 작업이 없다면 코드재배치가 일어나서
	//r1 = x; -> y=1; 순서로 작업순서 변경
}
void Thread_02() {

	while (!ready) {

	}
	x = 1; //Store x
	r2 = y;//Load y
}
int main()
{
	int count = 0;
	while (true) {

		ready = false;
		count++;

		x = y = r1 = r2 = 0;

		thread t1(&Thread_01);
		thread t2(&Thread_02);

		ready = true;

		t1.join();
		t2.join();

		if (r1 == 0 && r2 == 0) {
			break;
		}
	}

	cout << count << endl;

	return 0;
}