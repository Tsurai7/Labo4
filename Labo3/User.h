#pragma once

#include <iostream>
#include <vector>
#include <random>

#include "WebShop.h"

using namespace std;

class User
{
	friend class WebShop;
protected:
	int id;
	string name;
	string password;
	vector<string> cart;
public:
	User(string name, string password);
	int getId();
	string getName();
	string getPassword();
	vector<string> getCart();
	void AddToCartAuto(string item);
	void AddToCartAuto();
	void AddItem();
	void RemoveItem();
	void ShowCart();
	virtual void ShowActions(WebShop& shop);
};
