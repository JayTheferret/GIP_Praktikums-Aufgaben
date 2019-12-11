#include <iostream>
using namespace std;

int main()
{
	cout << "Merken Sie sich eine Zahl zwischen 1 (inklusive) und 100 (exklusive)" << endl << endl;

	int rmin = 1;
	int rmax = 100;
	char Auswahl = 0;

	while (true) //schleife
	{
	cout << "Aktueller Ratebereich: " << rmin << " bis " << rmax << endl;
	cout << "Ist " << (rmax+rmin) / 2 << " ihre Zahl?" << endl; //mittelwert
	cout << "(j) ja: gleich," << endl;
	cout << "(k) nein: meine Zahl ist kleiner," << endl;
	cout << "(g) nein: meine Zahl ist groesser." << endl;
	cout << "? ";

	cin >> Auswahl;

	if (Auswahl == 'k')
		rmax = (rmax+rmin)/2; //nur ganze zahlen

	else if (Auswahl == 'g')
		rmin = (rmax+rmin) / 2;

	else if (Auswahl == 'j')
		break;

}

	system("PAUSE");
	return 0;
}

