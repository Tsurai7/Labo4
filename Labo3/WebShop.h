#pragma once

#include <iostream>
#include <vector>

//#include "Admin.h"
//#include "Moderator.h"
#include "User.h"


using namespace std;

class WebShop
{
	friend class User;
	friend class Moderator;
	friend class Admin;
private:
	string name;
	string description;
	vector<User*> users;
public:
	WebShop(string name,string desc);
	void AddUser(User* usr);
	void ShowInfo();

	User* Register();
	User* Login();
};