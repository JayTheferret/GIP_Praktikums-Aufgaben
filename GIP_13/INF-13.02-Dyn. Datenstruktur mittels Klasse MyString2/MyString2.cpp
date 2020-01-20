#include "MyString2.h"

MyString2::MyString2() :anker(nullptr) {} //Standard-Konstruktor, der anker mit dem nullptr Wert belegt

//&adresse

MyString2::MyString2(const std::string& str) : anker(nullptr) {

    if (str.empty()) { //wenn leer
        anker = new CharListenKnoten(0);
        return;
    }

    CharListenKnoten* ptr = new CharListenKnoten(str.at(0));

    anker = ptr;

    for (std::size_t i = 1; i < str.size(); ++i) { //durchlaufen//nur so viele wie buchstaben zu speichernm aka str.size
        ptr->set_next(new CharListenKnoten(str.at(i)));
        ptr = ptr->get_next();
    }
}

// erzeugt einen neuen CharListenKnoten mit p_data als „Nutzlast“ und hängt diesen ans Ende an
void MyString2::append(char p_data) {

    if (!anker) {
        anker = new CharListenKnoten(p_data);
    }

    else {
        CharListenKnoten* ptr = anker;

        while (ptr->get_next()) {
            ptr = ptr->get_next();
        }
    }