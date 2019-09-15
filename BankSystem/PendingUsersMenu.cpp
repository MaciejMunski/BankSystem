#include "pch.h"
#include "PendingUsersMenu.h"
#include "DataBase.h"

PendingUsersMenu::PendingUsersMenu(Menu* parent):
	Menu("Pending users", parent)
{
}

Menu* PendingUsersMenu::process()
{
	clear();
	auto pendingUsers = DataBase::instance.pendingUsers();
	for (User* u : pendingUsers) {
		Menu* enableUserMenu = new EnableUserMenu(u);
		addSubmenu(enableUserMenu);
	}
	return Menu::process();
}

EnableUserMenu::EnableUserMenu(User* user, Menu* parent):
	Menu(user->login(), parent),
	_user(user)
{

}

Menu* EnableUserMenu::process()
{
	_user->setEnabled(true);
	cout << "User " << _user->login() << " enabled\n";
	return parent();
}
