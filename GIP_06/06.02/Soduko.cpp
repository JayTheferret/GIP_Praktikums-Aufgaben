#include <iostream>
#include <string>
using namespace std;

int main() {

	int sudoku[9][9] = { 0 };
	string eingabe[11];

	cout << "Bitte geben Sie das Sudoku ein:" << std::endl;

	for (int i = 0; i < 11; i++) { //zeilen einlesen
		getline(cin, eingabe[i]);
	}

	// Konvertierung
	int c;
	for (int i = 0, y = 0; i < 11; i++) {	//zeilen(y)
		if (i == 3 || i == 7)	//anonsten wird immer 0(nicht existierende zahlen) eingefügt -> zeilen für trennung
			continue;

		for (int j = 0, x = 0; j < eingabe[i].length(); j++) {	//spalten, j darf nicht länger als eingegebene zeile sein
			c = int(eingabe[i].at(j) - '0');	//ascii, umwandlung in int
			if (c >= 1 && c <= 9) {		//im fall von wert zwischen 1-9 einspeichern und nächste spalte
				sudoku[y][x] = c;
				x++;		//spalte
			}
		}

		y++; //nächste zeile
	}


	// Ausgabe 5.3
	/*

	cout << endl;
	cout << "Das Sudoku lautet:" << endl;

	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cout << ";" << sudoku[y][x];	// vor jeder zahl(!) semikolon,
			if ((x + 1) % 3 == 0 && x < 8) {	///nach jeder dritten zahl-> sonst kein rest)wenn null dann trenner, letzte nicht
				cout << ";//";
			}
		}

		if ((y + 1) % 3 == 0 && y < 8) { //wenn zahl 0 dann unterer trenner, unterste zeile nicht (s.o)
			cout << endl << "=======//=======//=======";
		}

		cout << endl;
	}
	*/

	//------------------------------------6.02---------------------

	int g = 0; //gültigkeitstest

	//Zeilen

	for (int y = 0; y < 9; y++) {//zeilen durchgehen
		
		int test[9] = { 0 };//Eingabe test

		for (int x = 0; x < 9; x++) {
			test[sudoku[x][y] - 1]++; //1 eingefügt wenn zahl vorkommt (fängt bei null an daher -1)-> array/liste mit 9 positionen
		}
		for (int i = 0; i < 9; i++) {
			if (test[i] == 0) { //0 fehlte eingabe
				cout << "Zeile " << y << ": Zahl " << i + 1 << " kommt nicht vor."<<endl;
			}
			else if (test[i] > 1) {//zwei oder höher doppelte eingabe
				cout << "Zeile " << y << ": Zahl " << i + 1 << " kommt mehrfach vor."<<endl;
			}
			else { g++; }
		}
	}

	//Spalten

	for (int x = 0; x < 9; x++) { 
		
		int test[9] = { 0 };
		
		for (int y = 0; y < 9; y++) {
			test[sudoku[x][y] - 1]++;
		}
		for (int i = 0; i < 9; i++) {
			if (test[i] == 0) {
				cout << "Spalte " << x << ": Zahl " << i + 1 << " kommt nicht vor."<<endl;
			}
			else if (test[i] > 1) {
				cout << "Spalte " << x << ": Zahl " << i + 1 << " kommt mehrfach vor." <<endl;
			}
			else { g++; }
		}
	}

	//Blöcke

	for (int b = 0; b < 9; b++) { //9 blöcke gesamt
		
		int test[9] = { 0 };//je neun eingaben

		for (int y_b = 0; y_b < 3; y_b++) { //nur bis zur drittend - nächste zeile
			
			for (int x_b = 0; x_b < 3; x_b++) { //nur bis zur dritten position -> block = 3x3, -nächste zeile
				
				test[sudoku[x_b + (b % 3) * 3][y_b + (b / 3) * 3] - 1]++; //modulo bleibt bei richtigen eingaben auf nullx3 -> eintrag bleibt negativ, int-> springt zurück
			}
		}
		for (int i = 0; i < 9; i++) {
			if (test[i] == 0) {
				cout << "Block " << b << ": Zahl " << i + 1 << " kommt nicht vor.\n";
			}
			else if (test[i] > 1) {
				cout << "Block " << b << ": Zahl " << i + 1 << " kommt mehrfach vor.\n";
			}
			else { g++; }
		}
	}

	if (g == 243) { //243 nimmt g an wenn alles gültig ist (testdurchlauf)
		cout << "Das Sudoku ist gueltig."<<endl;
	}

	system("PAUSE");
	return 0;
}