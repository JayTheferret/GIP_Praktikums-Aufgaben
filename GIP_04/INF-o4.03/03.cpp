#include <iostream>
using namespace std;

int main()
{
	int Stunden = 0;
	int Stunden_l = 0; //letzte
	int Minuten = 0;
	int Minuten_g = 0; //gesamt
	int Taktzeit = 0;

	//überprüfung der Stunden

	do {
		cout << "Bitte geben Sie die Stunden der Startuhrzeit ein: ";
		cin >> Stunden;
	} while (Stunden < 0 || Stunden >23);

	//überprüfung der Minuten

	do {
		cout << "Bitte geben Sie die Minuten der Startuhrzeit ein: ";
		cin >> Minuten;
	} while (Minuten < 0 || Minuten >59);

	Minuten_g = Minuten + Stunden*60;

	cout << "Der erste Bus faehrt also um " << Stunden << ":" << Minuten << endl;

	//überprüfung der Taktzeit

	do {
		cout << "Bitte geben Sie die Taktzeit in Minuten ein: ";
		cin >> Taktzeit;
	} while (Taktzeit < 0 || Taktzeit >180);

	do
	{
		Stunden_l = Stunden;
		Stunden = Minuten_g / 60; // stunde = 60 minuten
		Minuten = Minuten_g % 60; //rest in minuten (modulo)

		Minuten_g += Taktzeit;

		if (Stunden_l != Stunden) { //wenn letzte anders als jetzt, Umbruch
			cout << endl;
		}

		cout << Stunden << ":" << Minuten << " ";
		Minuten += Taktzeit;

	} while (Minuten_g <1440); //24x60
	cout << endl;

		system("PAUSE");
		return 0;
	
}

