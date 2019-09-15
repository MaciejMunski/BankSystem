#pragma once

#include "Menu.h"

class BankAccount
{
	//friend class User; //user jest przyjacielem BankAccount, czyli ma dostêp do wszystkich pol i metod (równie¿ private)

	string _number;
	float _balance;

public:
	BankAccount();
	string number() const;
	float balance() const;
	void transfer(float amount);
};

class BankAccountInfoMenu : public Menu {
public:
	BankAccountInfoMenu(shared_ptr<Menu> parent = nullptr);
	virtual Menu* process() override;
};