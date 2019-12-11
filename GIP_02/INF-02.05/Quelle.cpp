#include <iostream>
using namespace std;

int main()
{
	double Wert = 0;
	int Auswahl = 0;

	cout << "ihre Eingabe: ? ";
	cin >> Wert;
	cout << endl;


	cout << "Ihre Auswahl der Umwandlung:\n"
		" 1 - Celsius in Fahrenheit\n"
		" 2 - Meter in Fuss\n"
		" 3 - Euro in US Dollar\n";
	cin >> Auswahl;

	double Ergebnis = 0;
			Ergebnis = 
				(Wert*1.8+32)*(1/Auswahl)+
				(Wert*3.2808)*(2/Auswahl-(1/Auswahl)*2)+
				(Wert*1.2957)*(3/Auswahl-(1/Auswahl)*3-(2/Auswahl-(1/Auswahl)*2));

			//bei integer unter 0.9 -> 0

	cout << "Das Ergebnis lautet: " << Ergebnis << endl <<endl;


	system("PAUSE");
	return 0;
}