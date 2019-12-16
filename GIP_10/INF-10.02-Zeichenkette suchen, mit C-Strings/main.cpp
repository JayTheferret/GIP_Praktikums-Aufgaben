// Datei: main.cpp
#define CATCH_CONFIG_RUNNER
#include "catch.h"

#include <iostream>

using namespace std;

#include "suchen.h"

int main()
{
	if (Catch::Session().run()) {
		system("PAUSE");
		return 1;
	}
	// Ihr Code ab hier ...
	const unsigned int line_max = 20; //maximal länge 20

	char input[line_max];
	char zkette[line_max];

	cout << "Bitte geben Sie den Text ein: ";
	cin.getline(input, line_max);

	cout << "Bitte geben Sie die zu suchende Zeichenkette ein: ";
	cin.getline(zkette, line_max);

	int index = zeichenkette_suchen(input, zkette);

	if (index == -1)
	{
		cout << "Die Zeichenkette '" << zkette << "' ist NICHT in dem Text '" << input << "' enthalten." << std::endl;
	}
	else
	{
		cout << "Die Zeichenkette '" << zkette << "' ist in dem Text '" << input << "' enthalten." << std::endl
			<< "Sie startet ab Zeichen " << index << " (bei Zaehlung ab 0)." << endl;
	}

	system("PAUSE");
	return 0;
}