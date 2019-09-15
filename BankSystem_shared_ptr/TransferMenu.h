#pragma once

#include "Menu.h"

class TransferMenu: public Menu
{
public:
	TransferMenu(shared_ptr<Menu> parent = nullptr);
	virtual Menu* process() override;
};

