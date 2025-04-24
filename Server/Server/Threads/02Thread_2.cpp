#include <iostream>
#include <vector>	
#include <algorithm>
#include<thread>

#include<atomic>
using namespace std;

/*
atomimc 
- all or nothing
한 작업단위로 묶음

CPU 파이프라인
Fetch : 읽기
Decode : 해석
Excute : 실행
Memory Access : 메모리접근

세마포어 -> refCount를 올리거나 감소시키면서 관리

*/

atomic<int> sum = 0;

void AddSum() {
	for (int i = 0; i < 10000; i++) {
		sum.fetch_add(1);
	}
}
void SubSum() {
	for (int i = 0; i < 10000; i++) {
		sum.fetch_sub(1);
	}
}
int main() {
	
	vector<std::thread> threads;
	threads.resize(6);

	//이동복사생성자 우측값참조로 스레드를 3 - 3 나눠도 리소스 낭비 없음
	for (int i = 0; i < 3; i++) {

		threads[i] = std::thread(&AddSum);
	}
	for (int i = 3; i < 6; i++) {

		threads[i] = std::thread(&SubSum);
	}
	for (auto& thread : threads) {
		thread.join();
	}
	cout << sum << endl;


	return 0;
}