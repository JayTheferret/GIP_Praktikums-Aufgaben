#pragma once

/*
Die Klasse speichere die Buchstaben der Zeichenkette intern dadurch,
dass die Buchstaben in einer dynamischen Liste von CharListenKnoten
auf dem Heap gespeichert werden, jeder Buchstabe einzeln in einem
eigenen CharListenKnoten. Es sollen auch leere Zeichenketten
gespeichert werden können. Es sollen nie mehr CharListenKnoten
vorhanden sein als auch wirklich Buchstaben zu speichern sind. Es gebe
auch keine interne Nullterminierung im MyString2, d.h. es werden nur die
„wirklichen Buchstaben“ als CharListenKnoten Einträge gespeichert.

Die Klasse MyString2 habe dazu nur ein Attribut CharListenKnoten*
anker, welches den Pointer auf den ersten CharListenKnoten (falls
vorhanden, sonst nullptr) speichert.
*/

#include "CharListenKnoten.h"
#include <string>

class MyString2 {

private:
	CharListenKnoten* anker;

public:

	CharListenKnoten*	get_anker() { return anker; }
	void				set_anker(CharListenKnoten* set_anker) { anker = set_anker; }

	MyString2();
};