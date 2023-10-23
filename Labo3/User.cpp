#include "User.h"

using namespace std;

User::User(string name, string password)
{
	random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<> distribution(1, 1000);

	this->id = distribution(generator);
	this->name = name;
	this->password = password;
}

int User::getId() { return this->id; }

string User::getName() { return this->name; }

string User::getPassword() { return this->password; }

vector<string> User::getCart() { return this->cart; }

void User::AddToCartAuto(string item) { this->cart.push_back(item); }

void User::AddToCartAuto()
{
}

void User::AddItem() 
{
	string item;
	cout << "Enter item name:" << endl;
	cin >> item;
	this->cart.push_back(item); 
}

void User::RemoveItem()
{
	string item;
	cout << "Enter item name:" << endl;
	cin >> item;

	int ind = -1;
	for (int i = 0; i < cart.size(); i++)
	{
		if (item == cart[i])
		{
			ind = i;
			break;
		}
	}
	if (ind == -1)
	{
		cout << "No such element" << endl;
		exit;
	}
	else
	{
		cart.erase(cart.begin() + ind);
	}
}

void User::ShowCart()
{
	if (cart.size() == 0)
	{
		cout <<"Empty...";
	}
	else
	{
		for (auto item : cart)
			cout << item << " ";
	}
	cout << endl;
}


void User::ShowActions(WebShop& shop)
{
	if (this == nullptr)
	{
		cout << "Show actions error" << endl;
		return;
	}
	int action = 0;

	do {
	cout << "Actions:\n[0] Show profile\n[1] Add item to cart\n[2] Remove item from cart\n[3] Exit" << endl;
	cin >> action;
		switch (action)
		{
		case 0:
			system("cls");
			cout << "ID: " << this->getId() << endl;
			cout << "NAME: " << this->getName() << endl;
			cout << "PASSWORD: " << this->getPassword() << endl;
			cout << "CART:";
			this->ShowCart();	
			break;
		case 1:
			system("cls");
			this->AddItem();
			break;
		case 2:
			system("cls");
			this->RemoveItem();
			break;
		case 3:
			system("cls");
			return;
			break;
		default:
			cout << "Invalid input" << endl;
			break;
		}
	} while (true);
}