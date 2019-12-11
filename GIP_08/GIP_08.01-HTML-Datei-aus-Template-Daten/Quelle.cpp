#include <iostream>
#include <string>
#include <fstream>
#include "person.h"
#include "texte.h"

using namespace std;

//functions for </br> and <br>

string br(string text) { 
	return text + "</br>"; //</br> dran h�ngen
}

string b(string text) { 
	return "<b>" + text + "</b>"; 
}

int main()
{
	string eingabezeile = "" , kurztext = "", langtext = "";


	fstream datei("personendaten.txt", ios::in); // als textuelle Eingabedatei �ffnen;lesen

	//arbeit mit der datei

	while (getline(datei, eingabezeile)) {		//solange(eingabezeile aus Datendatei lesen)

	Person person = extrahiere_person(eingabezeile);
	
	//vvv HTML datei Texte vvv

	// kurztext erstellen 
	kurztext += br(b(person.nachname) + ", " + person.vorname) + "\n"; //br und b

	// langtext erstellen ...
	langtext += br(b(person.vorname + " " + person.nachname) + ", " + person.gebdatum) + "\n";
	
	}


	datei.close(); //Datendatei schlie�en

	fstream Templatedatei("webseite.html.tmpl", ios::in); //liest f�hrt funktion aus
	fstream Ausgabedatei("webseite.html", ios::out); //hier einf�gen

	while (getline(Templatedatei, eingabezeile)) {

		eingabezeile = ersetze(eingabezeile, '%', kurztext); //zeichen entfernen, durc h text ersetzen
		eingabezeile = ersetze(eingabezeile, '$', langtext);

		//Schreibe eingabezeile + "\n" in die Ausgabedatei;
		Ausgabedatei << eingabezeile + "\n";
	}
	Templatedatei.close();
	Ausgabedatei.close();

	system("PAUSE");
	return 0;
	
}