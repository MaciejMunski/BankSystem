#include "pch.h"
#include "LoginMenu.h"
#include "DataBase.h"

LoginMenu::LoginMenu(Menu* parent):
	Menu("Login", parent) //gdy konstruuje LoginMenu naszym konstr to do obiektu bazowego przypisuje nazwe login i parenta ktorego dalismy do argumentu
{
}

Menu* LoginMenu::process()
{
	string login, password;
	cout << "login: ";
	cin >> login;
	cout << "password: ";
	cin >> password;

	//zalogowanie uzytkownika, two zmienna  wskaznikowa user o nazwie loggedUser, 
	//przypisujemy do zmiennej to co 
	User* loggedUser = DataBase::instance.authenticate(login, password);
	if (loggedUser == nullptr) {
		//przez LoginMenu mozemy dostac sie do tej informacji za pomoca gettera () - trzeba wywolac geter i dostaniemy rodzica aktualnego menu
		return parent(); 
	}
	else {
		return loggedUser->menu();//jeze?i udalo sie to przechodze do menu usera na ktorego udalo sie zalogowac,j.
	}	
}
