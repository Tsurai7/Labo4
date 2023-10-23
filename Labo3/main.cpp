#include <iostream>

#include "User.h"
#include "Moderator.h"
#include "Admin.h"
#include "WebShop.h"
#include "RailFence.h"
#include "Election.h"

using namespace std;

int main()
{
	WebShop amazon("Amazon", "Simple web shop with some info");

	Moderator* nikita = new Moderator("nikita", "1234");
	User* ruslan = new User("ruslan", "wasdf56");
	User* timofey = new User("timofey", "qwert123");

	//nikita->AddToCartAuto("Norwegian wood");

	ruslan->AddToCartAuto("Crime and punishment");

	timofey->AddToCartAuto("IPHONE 13");
	timofey->AddToCartAuto("MacBook 2021");

	amazon.AddUser((User*)nikita);
	amazon.AddUser(ruslan);
	amazon.AddUser(timofey);

	User* usr = nullptr;
	int action = 0;
	do {
		cout << "Choose action\n[0] Exit\n[1] Shop info\n[2] Register\n[3] Login\n[4] Rail-Fence\n[5] Election" << endl;
		cin >> action;
		switch (action)
		{
		case 0:
			exit;
			break;
		case 1:
			system("cls");
			amazon.ShowInfo();
			break;
		case 2:
			system("cls");
			usr = amazon.Register();
			if (usr == nullptr)
				break;
			usr->ShowActions(amazon);
			break;
		case 3:
			system("cls");
			usr = amazon.Login();
			if (usr == nullptr)
				break;
			usr->ShowActions(amazon);
			break;
		case 4:
			RailFenceHandler();
			break;
		case 5:
			ElectionHandler();
			break;
		default:
			cout << "Invalid input" << endl;
			break;
		}
	} while (true);


	return 0;
}