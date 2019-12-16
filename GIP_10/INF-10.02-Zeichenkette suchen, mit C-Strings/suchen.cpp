#include "suchen.h"

using namespace std;

int bestimme_laenge(const char* text)

{
	int laenge;

	for (laenge = 0;; laenge++)//L�nge hochz�hlen
	{
		if (text[laenge] == '\0')	//wenn ende erreicht, dann break
		{
			break;
		}
	}
	return laenge;
}


int zeichenkette_suchen(const char* text, const char* zkette) {

	int laenge_text = bestimme_laenge(text);		//l�nge von text bestimmen
	int laenge_zkette = bestimme_laenge(zkette);	// l�nge von gesuchter zeichenkette bestimmen

	for (int i = 0; i < laenge_text; i++) { // text durchlaufen

		if (text[i] == zkette[0]) { //wenn anfang von zkette gefunden

			int r = 0;  // r zum z�hlen der zkette

			for (int j = i; j < i + laenge_zkette; j++) { //j als i kopie, ohne i zu �ndern

				if (text[j] == zkette[r]) {
					r++;
				}
				if (r == laenge_zkette) //wenn Zkette volls�ndig erhalten
				{
					return i; //wenn die Bedinung zutrifft, gib "i" zurueck. "i" hat den Wert der aktuellen Position im Array "Text", wo "Zkette" beginnt
				}
			}
		}
	}

	return -1; //Zeichenkette kam nicht im Text vor

}