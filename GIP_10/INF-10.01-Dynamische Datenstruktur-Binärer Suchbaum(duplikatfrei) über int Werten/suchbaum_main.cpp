#include <iostream>
#include "binaerer_suchbaum.h"

using namespace std;

int main() {

	Suchbaum::BaumKnoten* tree = nullptr;
	int value = 0;

	cout << "Naechster Wert (99 beendet): ? ";
	cin >> value;

	while(value != 99) {
		tree = Suchbaum::einfuegen(value, tree); //Baum aktualisieren

		cout << "Naechster Wert (99 beendet): ? ";
		cin >> value;

	}

	Suchbaum::ausgeben(tree);

	system("PAUSE");
	return 0;
}