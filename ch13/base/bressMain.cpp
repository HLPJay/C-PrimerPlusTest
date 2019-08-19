#include <iostream>
#include "bress.h"

int main(void)
{
	using std::cout;
	using std::endl;
	Brass Piggy("Procelot", 381229, 4000.00);
	BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);

	Piggy.ViewAcct();
	cout<<endl;

	Hoggy.ViewAcct();
	cout<<endl;

	cout<<"Depositing $1000 into the Hogg Account:\n";
	Hoggy.Deposit(1000.00);

	cout<<"new balance: $"<<Hoggy.Balance()<<endl;
	cout<<"withdrawing $4200 form the Pigg account:\n";
	Piggy.withdraw(4200.00);
	cout<<"Piggy balance: $"<<Piggy.Balance()<<endl;
	cout<<"withdrawing $4200 form the Hogg account:\n";
	Hoggy.withdraw(4200.00);
	Hoggy.ViewAcct();
	return 0;
}