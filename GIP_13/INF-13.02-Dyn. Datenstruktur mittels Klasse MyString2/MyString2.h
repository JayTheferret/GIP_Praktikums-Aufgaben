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
	~MyString2(); //Destruktor -> löschen
	MyString2(std::string str);//Kostruktor für string
	MyString2(const MyString2& other); //Copy Konstruktor (erstellt direkt aus Kopie)
	MyString2& operator=(const MyString2& other); // Assignment Operator -> copy->neu erstellt lates löschen
	MyString2 operator +(char c) const;   //assignment -> copy +anhang

	//Methoden
	void append(char p_data); //anfügen
	void delete_all(); //löschen
	unsigned int length(); //länge ermitteln
	char at(unsigned int pos); //data an position
	std::string to_string() const; //in string wandeln
	CharListenKnoten* deep_copy() const; //kopieren
	
};
