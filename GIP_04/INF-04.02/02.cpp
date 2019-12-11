#include <iostream>
#include <string>
using namespace std;

int main()
{
	string Klartext = "";
	string Ausgabe = "";

	cout << "Bitte geben Sie den zu verschluesselnden Text ein: ";
	getline(cin, Klartext);		//ganze zeile

	int v = 0;					//verschiebepositionen-Anzahl
	cout << "Bitte geben Sie die Anzahl der Verschiebepositionen ein als positive ganze Zahl: ";
	cin >> v;

	for (int i = 0; i < Klartext.length();i++) // buchstaben durchlaufen
	{
		int ascii = int(Klartext.at(i)); //ascii wert an aktueller position

		if(ascii >= int('a') && ascii <= int('z')){
			ascii += v;			//v drauf rechnen
			while (ascii > int('z')) //für den Fall dass der eingegebene (v) wert zu groß war
			{
				ascii -= 26;
			}
		}
		else if (ascii >= int('A') && ascii <= int('Z')) { //!alternativ modulo!

			ascii += v;
			while(ascii > int('Z'))
			{
				ascii -= 26;		//für den fall dass der eingegebene (v) wert zu groß war
			}
		}
		Ausgabe = Ausgabe + char(ascii); //pro schleife wird der buchstabe drauf gepackt
	}

	cout << Ausgabe << endl;


	system("PAUSE");
	return 0;
}

