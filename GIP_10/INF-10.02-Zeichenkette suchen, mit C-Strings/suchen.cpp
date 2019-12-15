#include <iostream>
#include "suchen.h"

using namespace std;

const unsigned int line_max = 20;

int zeichenkette_suchen(char* text, char* zkette)
{
	int result = -1;

	for (int i = 0, j = 0; text[i] != '\0'; i++)
	{
		if (text[i] != zkette[j]) //Wenn die Zeichen unterschiedlich sind, soll erneut vom Anfang starten
		{
			j = 0;
			result = -1;
		}
		else
		{
			if (zkette[j + 1] == '\0') //Ist suchender String in der Zeichenkette
			{
				result = i - j; //Jetzige Position - Länge von zkette
				break;
			}
			j++;
		}
	}
	return result;
}

int main()
{
	char text[line_max + 1];
	char search[line_max + 1];

	cout << "Bitte geben Sie den Text ein: ";
	cin.getline(text, line_max);

	cout << "Bitte geben Sie die zu suchende Zeichenkette ein: ";
	cin.getline(search, line_max);

	int index = zeichenkette_suchen(text, search);

	if (index == -1)
	{
		cout << "Die Zeichenkette '" << search << "' ist NICHT in dem Text '" << text << "' enthalten." << std::endl;
	}
	else
	{
		cout << "Die Zeichenkette '" << search << "' ist in dem Text '" << text << "' enthalten." << std::endl
			<< "Sie startet ab Zeichen " << index << " (bei Zaehlung ab 0)." << std::endl;
	}
}