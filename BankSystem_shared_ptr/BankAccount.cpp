#include "pch.h"
#include "BankAccount.h"
#include "DataBase.h"

const string accountPrefix = "17";

BankAccount::BankAccount()
{
	_balance = 0;
	_number = accountPrefix + " ";
	for (int i = 0; i < 6; ++i) {
		for (int k = 0; k < 4; ++k) {
			_number += rand() % 10 + '0';
		}
		_number += " ";
	}
	//TODO check if account number already exists
}

string BankAccount::number() const
{
	return _number;
}

float BankAccount::balance() const
{
	return _balance;
}

void BankAccount::transfer(float amount)
{
	if (_balance + amount < 0) {
		throw exception("Withdrawn amount is larger thatn account balance");
	}
	_balance += amount;
}

BankAccountInfoMenu::BankAccountInfoMenu(shared_ptr<Menu> parent):
	Menu("Bank Account Info",parent)
{
}

Menu* BankAccountInfoMenu::process()
{
	shared_ptr<User> u = DataBase::instance.loggedUser();
	if (u != nullptr) {
		shared_ptr<BankAccount> ba = u->bankAccount();
		if (ba != nullptr) {
			cout << "Number: " << ba->number() << endl;
			cout << "Balance: " << ba->balance() << endl;
		}
	}
	return parent();
}
