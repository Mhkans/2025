#include <mutex>
#include "00Account.h"
#include"00User.h"
Account* Account::_instance = nullptr;
void Account::Login()
{
	std::lock_guard<std::mutex> lg(_m);
	//User 정보 뽑기
	User::Instance()->GetUser(0);
}

int Account::GetAccount(int id)
{
	std::lock_guard<std::mutex> lg(_m);
	//Account정보를 DB에서 갖고오기

	return 0;
}
