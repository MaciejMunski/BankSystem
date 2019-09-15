#pragma once

#include "Menu.h"

class LoginMenu : public Menu
{
public:
	LoginMenu(shared_ptr<Menu> parent = nullptr);
	virtual Menu* process() override; //process czyli przetw Menu override zebezpiecza ze poprawnie nadpisalismy i nie pomylilismy sie w nazwie albo nie podalismy zlego typu zwroconego
};
