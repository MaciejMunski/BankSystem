#include "pch.h"
#include "DataBase.h"
#include "LoginMenu.h"
#include "AddUserMenu.h"
#include "TransferMenu.h"
#include "PendingUsersMenu.h"


//zmienna ktora ma typ Database pochodzi z Database i nazywa sie instance - jest to zwykly konstruktor bezparametrowy. 
//gdybysmy chcieli miec konstruktor Database() ,ktory przyjmuje jakies argumenty 
//wtedy trzeba je wypisac jak w zwyklej funkcji DataBase DataBase::instance (arg..);
DataBase DataBase::instance; 

DataBase::DataBase()
{
	mainMenu = new Menu("Main Menu"); //
	loginMenu = new LoginMenu; //klasa bazowa nie miala konstruktora dlatego w ligin menu musimy stworzyc swoj wlasny konstruktor
	createAccountMenu = new Menu("Create Account");
	createAdminAccountMenu = new AddAdminMenu(mainMenu);
	createUserAccountMenu = new AddUserMenu("Add User", mainMenu);
	regularUserMenu = new Menu("User Menu", mainMenu);
	adminUserMenu = new Menu("Admin Menu", mainMenu);
	bankAccountInfoMenu = new BankAccountInfoMenu;
	transferMenu = new TransferMenu;
	pendingUsersMenu = new PendingUsersMenu;

	mainMenu->addSubmenu(loginMenu);
	mainMenu->addSubmenu(createAccountMenu);
	createAccountMenu->addSubmenu(createAdminAccountMenu);
	createAccountMenu->addSubmenu(createUserAccountMenu);
	regularUserMenu->addSubmenu(bankAccountInfoMenu);
	regularUserMenu->addSubmenu(transferMenu);
	adminUserMenu->addSubmenu(pendingUsersMenu);

	addUser(User::ADMIN, "admin", "tajnehaslo");
	addUser(User::REGULAR, "user", "pass");
	addUser(User::REGULAR, "other", "pass");
}

User* DataBase::authenticate(string login, string password)
{
	for (auto u : _users) {
		if (u->authenticate(login, password)) { //spr czy jest taki user ktory loguje sie takimi danymi
			if (u->enabled()) {
				_loggedUser = u;
				return u;
			}else{
				cout << "This account in not enabled\n";
			}
		}
	}
	cout << "Login or password invalid\n";
	return nullptr; 
}

//dodac trzeba User::Type type jako dodatkowy argument, User 
User* DataBase::addUser(User::Type type, string login, string password, bool enabled)
{
	if (findUser(login))
		return nullptr;
	User* u = new User(type, login, password, enabled);
	_users.push_back(u);//jesli nie do dodajemy nowego usera z loginem i haslem i zwracamy tru
	return u;
}

User* DataBase::findUser(string login)
{
	for (auto u : _users) {
		if (u->login() == login) { //jezeli istnieje taki sam user to zwraca false
			return u;
		}
	}
	return nullptr;
}

User* DataBase::loggedUser() const
{
	return _loggedUser;
}

vector<User*> DataBase::pendingUsers() const
{
	vector<User*> result;
	for (auto u : _users) {
		if (!u->enabled())
			result.push_back(u);
	}
	return result;
}

void DataBase::run()
{
	mainMenu->show();
}
