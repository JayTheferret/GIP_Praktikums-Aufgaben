#include <iostream>
#include <string>
#include "person.h"
#include "texte.h"

using namespace std;

Person extrahiere_person(string eingabezeile) {

	Person p;
	string rest;

	spalte_ab_erstem(eingabezeile, ',', p.nachname, rest); //nachname weitergeben,(trennung komma) rest in rest
	spalte_ab_erstem(rest, ',', p.vorname, p.gebdatum); //s.o. rest in gebdatum

	p.nachname = trimme(p.nachname);//leerzeichen etc raustrimmen
	p.vorname = trimme(p.vorname);
	p.gebdatum = trimme(p.gebdatum);

	return p;


	//extrahieren der personendaten

	// vor erstes komma = nachname
	//zwischen komma = name
	//hinter = gebdatum

}