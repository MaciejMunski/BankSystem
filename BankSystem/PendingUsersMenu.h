#pragma once

#include "Menu.h"
#include "User.h"

class PendingUsersMenu : public Menu
{
public:
	PendingUsersMenu(Menu* parent = nullptr);
	virtual Menu* process() override;
};


class EnableUserMenu : public Menu
{
	User* _user;
public:
	EnableUserMenu(User* user, Menu* parent = nullptr);
	virtual Menu* process() override;
};