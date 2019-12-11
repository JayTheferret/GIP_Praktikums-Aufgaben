#include <iostream>
using namespace std;

int main()
{
	char z1 = 0;
	char z2 = 0;
	cout << "Bitte geben Sie die erste Ziffer ein: ? ";
	cin >> z1;
	cout << "Bitte geben Sie die zweite Ziffer ein: ? ";
	cin >> z2;

	//Fehlermeldung durch Eingabe von q

	if (z1 == 'q' || z2 == 'q') {	
		cout << "Das Programm wurde durch die Eingabe von q beendet.\n";

		system("PAUSE");
		return 1;
	}

	else {

		//Umwandlung in Zahlenwerte -> alternativ -48 (ASCII-Wert)

		int w1 = int(z1) - '0';	
		int w2 = int(z2) - '0';
		cout << w1 << " + " << w2 << " = " << w1+w2 << endl;
	}

	
system("PAUSE");
return 0;
}