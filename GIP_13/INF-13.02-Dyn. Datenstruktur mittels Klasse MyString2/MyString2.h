#pragma once
#include "CharListenKnoten.h"
#include <string>

class MyString2 {

private:

	CharListenKnoten* anker;

public:

	CharListenKnoten*	get_anker() { return anker; }
	void				set_anker(CharListenKnoten* new_anker) { anker = new_anker;  }

	MyString2(); //Konstruktor
	~MyString2(); //Destruktor -> l�schen
	MyString2(std::string str);//Kostruktor f�r string
	MyString2(const MyString2& other); //Copy Konstruktor (erstellt direkt aus Kopie)
	MyString2& operator=(const MyString2& other); // Assignment Operator -> copy->neu erstellt lates l�schen
	MyString2 operator +(char c) const;   //assignment -> copy +anhang

	//Methoden
	void append(char p_data); //anf�gen
	void delete_all(); //l�schen
	unsigned int length(); //l�nge ermitteln
	char at(unsigned int pos); //data an position
	std::string to_string() const; //in string wandeln
	CharListenKnoten* deep_copy() const; //kopieren
	
};
