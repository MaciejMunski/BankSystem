#include "pch.h"
#include "TransferMenu.h"
#include "DataBase.h"


TransferMenu::TransferMenu(Menu* parent):
	Menu("Transfer", parent)
{
}

Menu* TransferMenu::process()
{
	string receiverLogin;
	cout << "receiver: ";
	cin >> receiverLogin;
	//while (DataBase::instance.findUser(receiver) == nullptr) { równowa¿ne
	//while (!DataBase::instance.findUser(receiver)) {
	User* receiver = DataBase::instance.findUser(receiverLogin);
	while (receiver == nullptr) {
		cout << "Specified user does not exist\n";
		cout << "receiver: ";
		cin >> receiverLogin;
		receiver = DataBase::instance.findUser(receiverLogin);
	}

	BankAccount* receiverAccount = receiver->bankAccount();
	if (receiverAccount == nullptr) {
		cout << "You cannot transfer money to that user\n";
		return parent();
	}

	User* loggedUser = DataBase::instance.loggedUser();
	BankAccount* loggedUserAccount = loggedUser->bankAccount();

	float amount;
	bool done = false;

	do {
		cout << "amount: ";
		cin >> amount;
		try {
			loggedUserAccount->transfer(-amount);
			receiverAccount->transfer(amount);
			done = true;
		}
		catch (exception e) {
			cout << e.what() << endl;
		}
	} while (!done);

	return parent();
}
