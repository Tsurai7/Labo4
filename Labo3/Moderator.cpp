#include "Moderator.h"


 Moderator::Moderator(string name, string password)
 	: User(name, password) {}

void Moderator::SetDesc(WebShop& shop)
{
	string desc;
	cout << "Enter description" << endl;
	cin >> desc;

	shop.description = desc;
	cout << "Description was successfully changed" << endl;
}

void Moderator::ShowActions(WebShop& shop)
{
	if (this == nullptr)
	{
		cout << "Show actions error" << endl;
		return;
	}

	int action = 0;

	do {
		cout << "Actions:\n[0] Show profile\n[1] Add item to cart\n[2] Remove item from cart\n[3] Set Shop Info\n[4] Exit" << endl;
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
			this->SetDesc(shop);
			break;
		case 4:
			system("cls");
			return;
			break;
		default:
			cout << "Invalid input" << endl;
			break;
		}
	} while (true);
}

