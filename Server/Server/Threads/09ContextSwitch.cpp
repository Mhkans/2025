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
Context Swtiching : 레지스터 캐시에 저장되어있던 정보를 교체
cout(모니터에 접근) , 계산하던 일(기본적인 연산)을 번갈아 하면 Context Switching Overhead 발생

SpintLock 이 오버헤드가 가장 적게 발생하므로 FPS게임같이 빠른전송이 필요할때 사용

캐시 : 
Temporal Locality : 시간적 지역 -> 방금 본 메모리에서 또 접근할 일이 생길것같다 -> 메모리저장
Sptial Locality : 공간적 지역 -> 보았던 메모리 주변에 또 접근할 일이 생길것같다 
*/

int buffer[10000][10000];

int main()
{
	{
		memset(buffer, 0, sizeof(buffer));

		__int64 start = GetTickCount64();
		__int64 sum = 0;
		for (int i = 0; i < 10000; i++) {

			for (int j = 0; j < 10000; j++) {
				sum += buffer[i][j];
			}
		}
		__int64 end = GetTickCount64();

		cout << "Elapsed Tick " << end - start << " ms" << endl;
	}


	{
		memset(buffer, 0, sizeof(buffer));

		__int64 start = GetTickCount64();
		__int64 sum = 0;
		for (int i = 0; i < 10000; i++) {

			for (int j = 0; j < 10000; j++) {
				sum += buffer[j][i];
			}
		}
		__int64 end = GetTickCount64();

		cout << "Elapsed Tick " << end - start << " ms" << endl;
	}


	return 0;
}