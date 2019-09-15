#include "pch.h"
#include "TransferMenu.h"
#include "DataBase.h"


TransferMenu::TransferMenu(shared_ptr<Menu> parent):
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
	shared_ptr<User> receiver = DataBase::instance.findUser(receiverLogin);
	while (receiver == nullptr) {
		cout << "Specified user does not exist\n";
		cout << "receiver: ";
		cin >> receiverLogin;
		receiver = DataBase::instance.findUser(receiverLogin);
	}

	shared_ptr<BankAccount> receiverAccount = receiver->bankAccount();
	if (receiverAccount == nullptr) {
		cout << "You cannot transfer money to that user\n";
		return parent();
	}

	shared_ptr<User> loggedUser = DataBase::instance.loggedUser();
	shared_ptr<BankAccount> loggedUserAccount = loggedUser->bankAccount();

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
