#pragma once

#include <iostream>
#include <vector>
#include <random>

#include "User.h"
#include "WebShop.h"


using namespace std;

class Admin : protected User
{
	friend class WebShop;

public:
	Admin(string name, string password);
	void SetDesc(WebShop& shop);
	void ShowActions(WebShop& shop) override;
	void BanUser(WebShop& shop);
};