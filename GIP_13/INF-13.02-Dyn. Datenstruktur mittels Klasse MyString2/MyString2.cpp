#include "MyString2.h"
/**/MyString2::MyString2() : anker(nullptr) //Standard-Konstruktor, der anker mit dem nullptr Wert belegt
{

}

MyString2::~MyString2()
{
	delete_all();
}

MyString2::MyString2(std::string str) : anker(nullptr) //wenn string leer -> anker bleibt nullptr, leer
{
	for (int i = 0; i < str.length(); i++) {
		append(str[i]); //buchstabe für buchstabe anfügen
	}
}

MyString2::MyString2(const MyString2& other) : anker(other.deep_copy()) //deep copy aufrufen
{
}

MyString2& MyString2::operator=(const MyString2& other)
{
	delete_all(); //für den fall das "this" belegt is
	anker = other.deep_copy(); //kopieren //(this.anker)

	return *this; //kopierte Liste
}

void MyString2::append(char p_data)
{
	CharListenKnoten* temp = new CharListenKnoten(p_data); //überträgt wert/data

	if (anker == nullptr) { //wenn Liste leer direkt am anker einfügen
		anker = temp;
	}
	else {
		CharListenKnoten* temp_2 = anker; //mit anker gleichsetzen

		while (temp_2->get_next() != nullptr) { //durchlaufen solange temp_2 nicht ganz hinten
			temp_2 = temp_2->get_next();
		}
		temp_2->set_next(temp); //nächster kriegt daten/wert (letzter)
	}
}

void MyString2::delete_all()
{

	CharListenKnoten* temp_1 = anker;
	CharListenKnoten* temp_2 = nullptr;

	while (temp_1 != nullptr) { //solange Liste nicht leer
		temp_2 = temp_1->get_next();  //nächster punkt //damit verbindungen bestehen bleiben
		delete temp_1; //ersten löschen
		temp_1 = temp_2; //temp 1 mit dem nächsten belegen -> durchlaufen
	}
	anker = nullptr;
}

unsigned int MyString2::length()
{
	int length = 0;
	CharListenKnoten* temp = anker;

	while (temp != nullptr) { //liste durchgehen
		length++; //länge für jeden Knoten erhöhen
		temp = temp->get_next();
	}

	return length;
}

char MyString2::at(unsigned int pos)
{
	if (length() <= pos) { //falls Liste zu kurz für Position
		return '\0'; //rückgabewert wenn kein Buchstabe an position vorhanden
	}

	CharListenKnoten* temp = anker;

	for (int i = 0; i < pos; i++) { //Liste durchlaufen bis Position
		temp = temp->get_next();
	}

	return temp->get_data(); // data an Position übergeben
}

MyString2 MyString2::operator+(char c) const
{
	MyString2 new_MyString2{*this}; //aufruf Copy Kontrukter -> kopiert this in neues Objekt
	new_MyString2.append(c); //an neuen anfügen

	return new_MyString2;
}

std::string MyString2::to_string() const
{
	std::string str = "";
	CharListenKnoten* temp = anker;

	while (temp != nullptr) { //liste durchgehen
		str += temp->get_data(); //data an der stelle in string eingeben
		temp = temp->get_next(); //einen weiter
	}

	return str;
}

CharListenKnoten* MyString2::deep_copy() const
{
	if (anker == nullptr) { //im Fall von leerer liste
		return nullptr;
	}

	//wenn Liste nicht leer

	CharListenKnoten* new_anker = new CharListenKnoten(anker->get_data()); //Kopie vom anker
	CharListenKnoten* temp_1 = anker->get_next(); //eins voraus
	CharListenKnoten* temp_2 = new_anker;

	while (temp_1 != nullptr) {

		CharListenKnoten* node = new CharListenKnoten(temp_1->get_data());
		temp_2->set_next(node); //nächster angehangen

		temp_1 = temp_1->get_next(); //immernoch eins voraus
		temp_2 = temp_2->get_next();
	}

	return new_anker;
}
