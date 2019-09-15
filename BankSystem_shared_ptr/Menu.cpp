#include "pch.h"
#include "Menu.h"

Menu::Menu(string name, shared_ptr<Menu> parent):
	_parent(parent.get()), //trzeba teraz ustawic parenta
	_name(name)
{
}

void Menu::clear()
{
	_submenus.clear();
}

string Menu::name()
{
	return _name;
}

Menu* Menu::parent()
{
	return _parent;
}

void Menu::addSubmenu(shared_ptr<Menu> menu)
{
	//nie dodamy wskaznika ktory jest nullem, chcemy sie zabezpieczyc przed niewlasciwym uzywaniem
	if (menu == nullptr)
		return;
	//nie dodamy wskaznika ktory juz jest dodany do submenus
	for (shared_ptr<Menu> m : _submenus)
		if (m == menu)
			return;
	//jezeli wszystko ok, to dodajemy. do wektora submenu dodajemy menu, wektora nie damy do public 
	_submenus.push_back(menu);
	menu->_parent = this;
}

void Menu::show()	
{
//menu w ktorym wywolujemy show,
//w menzmienna current przechowuje wskaznik na menu w ktorym aktualnie jestesmy
	Menu* current = this; 
	//wchodzimy do petli do i robimy przypisanie, jezeli jest cos po prawej stronie i chcemy 
	//to przypisac do lewe to to po prawej to musi to byc wykonane jako pierwsze. dlatego z aktualnego
	//menu wywolujemy metode process
	do {
		current = current->process(); //wykonaj Menu i zwroc kolejne Menu do ktorego powinnismy przejsc i bedzie ono aktualnym, tak dlugo dopiki nie wybierzemy 0.
		cout << "=====================" << endl;
	} while (current != nullptr);
}

Menu* Menu::process()
//komunikuje sie z uzytkownikiem, przeprowadza dzialanie ktore dotyczy tego konkretnego menu 
//i zwraca wsk na menu ktore powinnow byc nastepnie wykonane. kaze menu zwraca to ktore bedzie nastepne
{
	if (_parent == nullptr) {
		//glowne menu programu
		cout << "0: exit\n";
	}
	else {
		cout << "0: back\n"; //na zerze jest back a jak wcisnie od 1 w gore to bede w  menu
	}
	for (int i = 0; i < _submenus.size(); ++i) {
		cout << (i + 1) << ": " << _submenus[i]->name() << "\n"; //przejde do takieg osubmenu gdy wybiore taka cyfre
	}

	int choice;
	cout << ">> ";
	cin >> choice;
	while (choice < 0 || choice > _submenus.size()) {
		cout << "invalid choice\n";
		cout << ">> ";
		cin >> choice;
	}

	if (choice == 0) {
		return _parent; //zwroc menu o jeden wyzej
	}
	else {
		return _submenus[choice - 1].get(); // jak to jest z tym -1
	}
}
