#pragma once

#include "Menu.h"
#include "BankAccount.h"

//mypass
//hash: r35@%$?g4%W$5gw$%vw#%TVw%wERGbsE%tbwE5bW53

//User odpowiada za danie uzytkownikow w systemie
class User
{
public:
	//enum (anumeration - typ wuliczeniowy, wart obracajs sie w obrebie kilku scisle okreslonych, 
	//tutaj to regular i admin)
	//defniuje dwie stale wartosci, ktore nazyw sie regular i admin, sa one stale niezmienialne
	//do tych nazw przypisywane sa wartosci ergular to 0 admin to 1, przypisywane sa kolejne wartosc 
	//i poczawszy od zera. Jest wyzej bo kompilator musi wiedziec pozniej co to jest Type.
	//do sprawdzenia wartosci enuma najlepiej uzyc instrukcji switch, wszystkie wartosci pojawiaja sie w casach; uniknie sie wtedy 
	//warunku domyslnego ktory nie jest tak naprawde ligiczny
	
	enum Type {
		REGULAR, ADMIN
	};

private:
	Type _type;
	string _surname;
	string _login;
	string _password;
	unsigned _yearOfBirth;
	Menu* _menu;
	bool _enabled;
	BankAccount* _bankAccount;

public:
	//aby mozna bylo stworzyc usera z loginem i haslem; 
	User(Type type, string login, string password, bool enabled = true); 
	bool authenticate(string login, string password);
	string login(); //zeby dal osie dostac do usera (geter do loginu)
	//geter zeby dostac sie do menu usera
	Menu* menu();
	bool enabled();
	void setEnabled(bool value);
	BankAccount* bankAccount() const;
};

//klasy powiazane tematycznie definiujemy w tych samych plikach
