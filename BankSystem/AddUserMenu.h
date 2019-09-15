#pragma once

#include "Menu.h"


class AddUserMenu : public Menu
{
protected:
	pair<string, string> getLoginAndPassword();
public:
	AddUserMenu(string name, Menu* parent = nullptr);
	virtual Menu* process() override; //???????? - o co chodzi z tym override
};

class AddAdminMenu : public AddUserMenu
{
public:
	AddAdminMenu(Menu* parent = nullptr);
	virtual Menu* process() override;
};

//trzeba stworzyc CreateAdminUser ;