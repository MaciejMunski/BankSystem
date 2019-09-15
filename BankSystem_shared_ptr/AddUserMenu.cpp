#include "pch.h"
#include "AddUserMenu.h"
#include "DataBase.h"

template<typename T1, typename T2>
struct MyPair {
	T1 first;
	T2 second;
};

pair<string, string> AddUserMenu::getLoginAndPassword()
{
	string login;
	string password;
	string passwordConfirmed;
	cout << "choose your login: ";
	cin >> login;
	while (DataBase::instance.findUser(login)) {
		cout << "login already taken\n";
		cout << "choose your login: ";
		cin >> login;
	}
	cout << "set your password: ";
	cin >> password;
	cout << "confirm your password: ";
	cin >> passwordConfirmed;
	while (password != passwordConfirmed) {
		cout << "passwords are different!\n";
		cout << "set your password: ";
		cin >> password;
		cout << "confirm your password: ";
		cin >> passwordConfirmed;
	}
	//return pair<string, string>(login, password);
	return { login, password };
}

AddUserMenu::AddUserMenu(string name, shared_ptr<Menu> parent):
	Menu(name, parent)
{
}

Menu* AddUserMenu::process()
{
	auto loginData = getLoginAndPassword();
	shared_ptr<User> createdUser = DataBase::instance.addUser(User::REGULAR, loginData.first, loginData.second);
	if (createdUser == nullptr) {
		cout << "Something went wrong!\n";
		return parent();
	}
	else {
		return createdUser->menu();
	}
}

AddAdminMenu::AddAdminMenu(shared_ptr<Menu> parent):
	AddUserMenu("Add Admin", parent)
{
}

Menu* AddAdminMenu::process()
{
	pair<string, string> loginData = getLoginAndPassword();
	shared_ptr<User> createdUser = DataBase::instance.addUser(User::ADMIN, loginData.first, loginData.second, false);
	if (createdUser == nullptr) {
		cout << "Something went wrong!\n";		
	}
	else {
		cout << "User creation request is waiting for admin confirmation\n";
	}
	return parent();
}
