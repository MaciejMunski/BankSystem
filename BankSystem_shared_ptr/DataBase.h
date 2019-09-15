#pragma once

#include "User.h"

class DataBase
{	
	vector<shared_ptr<User>> _users;	//wskazniki na obiekty usera, konieczne User.h, przechowujemy wszystkich userow
	shared_ptr<User> _loggedUser;

public:
	//to jest zmienna ktora nie ma swojej definicji i musimy ja dodac w pliku zrodlowym Database.cpp
	//tak jak bysmy defniowali finkcje. Musi byc w pliku zrodlowym stworzona. w c++ 17 jest to jako inline jesli bedzie ta sama klasa
	static DataBase instance; 

	shared_ptr<Menu> mainMenu;
	shared_ptr<Menu> loginMenu; //klasa bazowa nie miala konstruktora dlatego w login menu musimy stworzyc swoj wlasny konstruktor
	shared_ptr<Menu> createAccountMenu;
	shared_ptr<Menu> createAdminAccountMenu;
	shared_ptr<Menu> createUserAccountMenu;
	shared_ptr<Menu> regularUserMenu;
	shared_ptr<Menu> adminUserMenu;
	shared_ptr<Menu> bankAccountInfoMenu;
	shared_ptr<Menu> transferMenu;
	shared_ptr<Menu> pendingUsersMenu;

	DataBase();
	
	//metoda sprawdza czy user moze sie zalogowac, sprawdza po wszystkich userach
	shared_ptr<User> authenticate(string login, string password); 
	
	//f dostaje login i pass dla nowego usera ktory ma bc stworzony gdy go podajemy i zwroci nam boola
	//User:: - trzeba odwolac sie do usera podajac skad enum pochodzi
	shared_ptr<User> addUser(User::Type type, string login, string password, bool enabled = true); 
	shared_ptr<User> findUser(string login); //sprawdzenie czy nowy login istnieje
	shared_ptr<User> loggedUser() const;
	vector<shared_ptr<User>> pendingUsers() const;

	void run();
};

//singleton