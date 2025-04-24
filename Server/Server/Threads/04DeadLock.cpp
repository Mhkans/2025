
#include <iostream>
#include<thread>

using namespace std;

#include "00Account.h"
#include "00User.h"

/*
spinLock -CAS
sleepLock
EventLock -CV
*/

int main()
{
    std::thread t1([](){
        for (int i = 0; i < 10000; i++) {
            User::Instance()->Save();
        }
    });
    std::thread t2([]() {
        for (int i = 0; i < 10000; i++) {
            Account::Instance()->Login();
        }
    });

    t1.join();
    t2.join();

    Account::Delete();
    User::Delete();
}
