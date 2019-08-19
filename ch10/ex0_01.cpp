/**************************************
姓名，账号(string)，存款

**************************************/
#include <iostream>
#include <string>

namespace Test10_1{
	using namespace std;
	class BankAccount
	{
		private:
			string name;
			string account;
			double money;
		public:
			BankAccount(string strName, string strAccount, double num = 0);
			~BankAccount();
			void ShowInfo(void) const ;
			void SetMoney(double num);
			bool GetMoney(double num);
	};

	//TODO :构造函数和析构函数是没有返回值的
	BankAccount::BankAccount(string strName, string strAccount, double num)
	{
		this->name = strName;
		this->account = strAccount;
		if(num<0)
		{
			this->money = 0.0;
		}
		else
		{
			this->money = num;
		}

	}

	BankAccount::~BankAccount()
	{
		cout<<"BankAccount::~BankAccount"<<endl;
	}

	void BankAccount::ShowInfo(void) const 
	{
		cout<<"name:"<<this->name<<endl;
		cout<<"account:"<<this->account<<endl;
		cout<<"money:"<<this->money<<endl;
	}

	void BankAccount::SetMoney(double num)
	{
		if(num<0)
		{
			num = 0;
		}
		this->money += num;
	}

	bool BankAccount::GetMoney(double num)
	{
		if(num >this->money)
		{
			return false;
		}
		this->money -= num;
		return true;
	}
}

int main(void)
{
	using namespace Test10_1;
	BankAccount bankAccount {"myname", "myaccount",10};
	//BankAccount bankAccount = {"myname", "myaccount",10};
	//BankAccount bankAccount = BankAccount{"myname", "myaccount",10};//或者括号
	bankAccount.ShowInfo();
	bankAccount.SetMoney(12);
	cout<<"return GetMoney:"<<bankAccount.GetMoney(20)<<endl;
	bankAccount.ShowInfo();
	cout<<"return GetMoney:"<<bankAccount.GetMoney(20)<<endl;
	bankAccount.ShowInfo();
	return 0;
}