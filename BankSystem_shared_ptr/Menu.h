#pragma once

//cppreference.com / cplusplus.com / org

class Menu {
	Menu* _parent; //odwolanie do rodzica czyli do menu ktore jest wyzej w hierarchii
	string _name;  // z podlreslnikiem zeby np pozniej moc napisac getter zgodnie z konwencja 
	vector<shared_ptr<Menu>> _submenus;  //wektor odwolan do innych menu, wektor wskaznikow na Menu, vector to klasa z bibl std ktora przechowuje 
							//sobie wsk na tablice ktora samodzielnie dynamicznie alokuje - jest ustandaryzowana 
							//zeby dzialala szybko i uniwersalnie 
public:
	//domyslna wartosc argumentu - piszemy tylko w wpliku .h
	Menu(string name, shared_ptr<Menu> parent = nullptr); //jesli podam tylko string name to teo shared_ptr<Menu> parent przyjmie domyslna wartosc dzieki temu nie trzeba go podawac w main.cpp shared_ptr<Menu>mainMenu przyjmie on nullptr automatycznie
	void clear();
	string name();
	Menu* parent(); //po to zeby dostac sie z zewnatrz do tej informacji
	void addSubmenu(shared_ptr<Menu> menu); //funkcja do obslugi czyli dodania submenu
	void show(); //chcemy uruchomic Menu, funckja wyjsciowa do dowolnego Menu
	//przetwarzanie dzia�ania menu, zwracana warto�� to wska�nik do nast�pnego menu
	//kt�re powinno by� pokazane po wyj�ciu z aktualnego
	virtual Menu* process(); 
};