#pragma once

#include "Menu.h"
#include "User.h"

class PendingUsersMenu : public Menu
{
public:
	PendingUsersMenu(shared_ptr<Menu> parent = nullptr);
	virtual Menu* process() override;
};


class EnableUserMenu : public Menu
{
	shared_ptr<User> _user;
public:
	EnableUserMenu(shared_ptr<User> user, shared_ptr<Menu> parent = nullptr);
	virtual Menu* process() override;
};