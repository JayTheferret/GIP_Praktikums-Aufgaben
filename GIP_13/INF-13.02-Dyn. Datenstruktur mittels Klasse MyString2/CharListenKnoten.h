#pragma once

//classe für die kette -> anker in mystring

//basieren auf dem struct listenknoten
class CharListenKnoten {

private:
    //einfach verkettet
	CharListenKnoten* next;
	char data;

public:

    CharListenKnoten(char c = 0): data(c), next(nullptr){}

    //Setter und Getter

    CharListenKnoten* get_next() { return next; }
    void set_next(CharListenKnoten* new_next) { next = new_next; }

    char get_data() { return data; }
    void set_data(char new_data) { data = new_data; }

};