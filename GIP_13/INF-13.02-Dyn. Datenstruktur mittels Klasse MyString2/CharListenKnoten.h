#pragma once

class CharListenKnoten
{
private:

    CharListenKnoten* next; //einfach verkettet in Vorwärtsrichtung über einen CharListenKnoten* next
    char              data; //„Nutzlast“ jedes CharListenKnoten sei ein char data

public:

    CharListenKnoten(char c = 0) : data(c), next(nullptr) {}

    //Setter und Getter

    CharListenKnoten* get_next() { return next; }
    void set_next(CharListenKnoten* set_next) { next = set_next; }

    char get_data() { return data; }
    void set_data(char set_data) { data = set_data; }
};