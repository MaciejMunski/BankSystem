#include "pch.h"
#include "PendingUsersMenu.h"
#include "DataBase.h"

PendingUsersMenu::PendingUsersMenu(shared_ptr<Menu> parent):
	Menu("Pending users", parent)
{
}

Menu* PendingUsersMenu::process()
{
	clear();
	auto pendingUsers = DataBase::instance.pendingUsers();
	for (shared_ptr<User> u : pendingUsers) {
		shared_ptr<Menu> enableUserMenu = make_shared<EnableUserMenu>(u);
		addSubmenu(enableUserMenu);
	}
	return Menu::process();
}

EnableUserMenu::EnableUserMenu(shared_ptr<User> user, shared_ptr<Menu> parent):
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
