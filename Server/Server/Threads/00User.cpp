#include <mutex>
#include "00User.h"
#include "00Account.h"
using namespace std;

User* User::_instance = nullptr;

void User::Save()
{
	std::lock_guard<std::mutex> lg(_m);

	//account 확인 
	Account::Instance()->GetAccount(0);
	//계정정보를 저장
	return;
}

int User::GetUser(int id)
{
	std::lock_guard<std::mutex> lg(_m);
	//userinfo id에서 추출
	return 0; //임시로 0
}
