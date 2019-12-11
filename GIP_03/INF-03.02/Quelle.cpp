#include <iostream>
using namespace std;

int main()
{
	//Position und Größenvergleich

	int PG = 0;			//Position Größte
	int PK = 0;			//Position Kleinste

	int z1 = 0;
	int z2 = 0;
	cout << "Bitte geben Sie die 1.Zahl ein: ? ";
	cin >> z1;
	cout << "Bitte geben Sie die 2.Zahl ein: ? ";
	cin >> z2;
	
	int g = 0; //größte zahl
	int k = 0; //kleinste Zahl

	if (z1 > z2) {
		g = z1;
		k = z2;
		PG = 1;
		PK = 2;
	}
	else if (z2 > z1) {
		g = z2;
		k = z1;
		PG = 2;
		PK = 1;
	}
	else {
		g = z1;
		k = z1;
		PG = 1;
		PK = 1;
	}

	int z3 = 0;
	cout << "Bitte geben Sie die 3.Zahl ein: ? ";
	cin >> z3;

	if (z3 > g) {
		g = z3;
		PG = 3;
	}
	else if (z3 < k) {
		k = z3;
		PG = 3;
	}

	int z4 = 0;
	cout << "Bitte geben Sie die 4.Zahl ein: ? ";
	cin >> z4;

	if (z4 > g) {
		g = z4;
		PG = 4;
	}
	else if (z4 < k) {
		k = z4;
		PK = 4;
	}

	int z5 = 0;
	cout << "Bitte geben Sie die 5.Zahl ein: ? ";
	cin >> z5;

	if (z5 > g) {
		g = z5;
		PG = 5;
	}
	else if (z5 < k) {
		k = z5;
		PK = 5;
	}
		

	cout << "Die " << PK <<". Zahl war die kleinste der eingegeben Zahlen und lautet: " <<k << endl;
	cout << "Die " << PG << ". Zahl war die groesste der eingegeben Zahlen und lautet: " << g << endl;

	system("PAUSE");
	return 0;
}


//mit Schleife verkürzen