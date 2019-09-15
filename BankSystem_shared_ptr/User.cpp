#include "pch.h"
#include "User.h"
#include "DataBase.h"

User::User(Type type, string login, string password, bool enabled):
	_type(type),
	_login(login),
	_password(password),
	_enabled(enabled)
{
	switch (type) {
	case REGULAR:
		_menu = DataBase::instance.regularUserMenu.get();
		_bankAccount = make_shared<BankAccount>();
		break;
	case ADMIN:
		_menu = DataBase::instance.adminUserMenu.get();
		break;
	}
}

bool User::authenticate(string login, string password)
{
	return login == _login && password == _password; //czy login rowna sie loginowi user i czy podane haslo rowne jest hasle usera
}

string User::login()
{
	return _login;
}

Menu* User::menu()
{
	return _menu;
}

bool User::enabled()
{
	return _enabled;
}

void User::setEnabled(bool value)
{
	_enabled = value;
}

shared_ptr<BankAccount> User::bankAccount() const
{
	return _bankAccount;
}
