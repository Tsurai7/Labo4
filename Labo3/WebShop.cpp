#include "WebShop.h"
#include "Moderator.h"
#include "Admin.h"


using namespace std;

WebShop::WebShop(string name,string desc) 
{
	this->name = name;
	this->description = desc;
}

void WebShop::AddUser(User* usr) { users.push_back(usr); }

void WebShop::ShowInfo()
{
	cout << "Shop name: " << this->name << endl;
	cout << "Description: " << this->description << endl;
	cout << "Registered users: " << endl;

	for (auto user : this->users)
	{
		cout << "Id: " << user->getId() << endl;
		cout << "Name: " << user->getName() << endl;
		cout << "Cart: " << endl;
		for (auto el : user->getCart())
		{
			cout << el << endl;
		}
		cout << endl;
	}
}

User* WebShop::Register()
{
	string name, password, role;

	cout << "Enter username:" << endl;
	cin >> name;
	for (auto user : users)
	{
		if (user->getName() == name)
		{
			cout << "Such user already exists\nTry to login" << endl;
			return nullptr;
		}
	}
	cout << "Enter password:" << endl;
	cin >> password;
	cout << "Enter role:\n[u] User\n[m] Moderator\n[a] Admin" << endl;
	cin >> role;


	try {
		if (role == "u")
		{
			User* user = new User(name, password);
			users.push_back(user);
			cout << "You've been succesfully registered as user\n" << endl;
			return user;
		}
		else if (role == "m")
		{
			Moderator* mdtr = new Moderator(name, password);
			users.push_back(mdtr);
			cout << "You've been succesfully registered as moderator\n" << endl;
			return mdtr;

		}
		else if (role == "a")
		{
			Admin* admn = new Admin(name, password);
			users.push_back(admn);
			cout << "You've been succesfully registered as admin\n" << endl;
			return admn;
		}
		else
		{
			cout << "Invalid input" << endl;
			return nullptr;
		}
	}
	catch (const char* err){
		cout << err << std::endl;
		return nullptr;
	}
}


User* WebShop::Login()
{
	string name, password, role;

	cout << "Enter username:" << endl;
	cin >> name;
	cout << "Enter password:" << endl;
	cin >> password;

	for (auto user : users)
	{
		if (user->getName() == name && user->getPassword() == password)
		{
			cout << "You've been succesfully logined" << endl;
			return user;
		}
	}
	cout << "No such user or wrong password\nTry to register" << endl;
	return nullptr;
}
