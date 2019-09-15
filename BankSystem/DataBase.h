#pragma once

#include "User.h"

class DataBase
{	
	vector<User*> _users;	//wskazniki na obiekty usera, konieczne User.h, przechowujemy wszystkich userow
	User* _loggedUser;

public:
	//to jest zmienna ktora nie ma swojej definicji i musimy ja dodac w pliku zrodlowym Database.cpp
	//tak jak bysmy defniowali finkcje. Musi byc w pliku zrodlowym stworzona. w c++ 17 jest to jako inline jesli bedzie ta sama klasa
	static DataBase instance; 

	Menu* mainMenu;
	Menu* loginMenu; //klasa bazowa nie miala konstruktora dlatego w login menu musimy stworzyc swoj wlasny konstruktor
	Menu* createAccountMenu;
	Menu* createAdminAccountMenu;
	Menu* createUserAccountMenu;
	Menu* regularUserMenu;
	Menu* adminUserMenu;
	Menu* bankAccountInfoMenu;
	Menu* transferMenu;
	Menu* pendingUsersMenu;

	DataBase();
	
	//metoda sprawdza czy user moze sie zalogowac, sprawdza po wszystkich userach
	User* authenticate(string login, string password); 
	
	//f dostaje login i pass dla nowego usera ktory ma bc stworzony gdy go podajemy i zwroci nam boola
	//User:: - trzeba odwolac sie do usera podajac skad enum pochodzi
	User* addUser(User::Type type, string login, string password, bool enabled = true); 
	User* findUser(string login); //sprawdzenie czy nowy login istnieje
	User* loggedUser() const;
	vector<User*> pendingUsers() const;

	void run();
};

//singleton