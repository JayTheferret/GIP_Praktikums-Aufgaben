#include <iostream>
#include <string>
#include "wortspiegel.h"
using namespace std;

int main() {
	string eingabe;
	char auswahl = 'a';
	int position = 0;

	cout << "Bitte geben Sie den text ein: ? ";
	getline(cin, eingabe);

	while (true) {
		cout << eingabe << endl;
		
		for (int i = 0; i < position; i++) {
			cout << " ";
		}
			cout << "*" << endl;
			cout << "Befehl (l: links, r: rechts, s: spiegeln, q: Ende) ?- ";
			cin >> auswahl;

			//position ->stern
			if (auswahl == 'l' && position >0) {
				position--;
			}

			else if (auswahl == 'r' && position < eingabe.size()-1) //Anfang bei 0 -> geht nicht über rand hinweg
			{
				position++;
			}

			else if (auswahl == 's') {
				wortspiegel(eingabe, position); //funktion wortspiegel ausführen -> gibt input und pos and wortspiegel
			}

			else if (auswahl == 'q') {
				break;
			}
	}
	system("PAUSE");
	return 0;
}