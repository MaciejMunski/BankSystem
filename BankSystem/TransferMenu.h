#pragma once

#include "Menu.h"

class TransferMenu: public Menu
{
public:
	TransferMenu(Menu* parent = nullptr);
	virtual Menu* process() override;
};

