#pragma once

#include <iostream>
#include <vector>
#include <random>

#include "User.h"
#include "WebShop.h"


using namespace std;

class Moderator : protected User
{
	friend class WebShop;

public:
	Moderator(string name, string password);
	void SetDesc(WebShop& shop);
	void ShowActions(WebShop& shop) override;
};
