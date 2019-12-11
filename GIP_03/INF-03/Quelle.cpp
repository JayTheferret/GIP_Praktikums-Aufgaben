#include <iostream>
using namespace std;

int main()
{
	int tag1 = 0;
	int monat1 = 0;
	int jahr1 = 0;

	cout << "Bitte geben Sie den Tag des ersten Datums ein: ";
	cin >> tag1 ;
	cout << "Bitte geben Sie den Monat des ersten Datums ein: ";
	cin >> monat1;
	cout << "Bitte geben Sie das Jahr des ersten Datums ein: ";
	cin >> jahr1;

	int tag2 = 0;
	int monat2 = 0;
	int jahr2 = 0;

	cout << "Bitte geben Sie den Tag des zweiten Datums ein: ";
	cin >> tag2;
	cout << "Bitte geben Sie den Monat des zweiten Datums ein: ";
	cin >> monat2;
	cout << "Bitte geben Sie das Jahr des zweiten Datums ein: ";
	cin >> jahr2;

	//Bedingungen und bedingte Ausgaben

	if (jahr1 > jahr2) {
		cout << "Das zweite Datum liegt vor dem ersten datum.\n";
	}
	
	else if (jahr2 > jahr1) {
		cout << "Das erste Datum liegt vor dem zweiten Datum.\n";
	}
	
	else  {
		if (monat1 > monat2) {
			cout << "Das zweite Datum liegt vor dem ersten Datum.\n";
		}
		else if (monat2 > monat1) {
			cout << "Das erste Datum liegt vor dem zweiten Datum.\n";
		}
		else  {
			if (tag1 > tag2) {
				cout << "Das zweite Datum liegt vor dem ersten Datum\n";
			}
			else if (tag1 > tag2) {
				cout << "Das zweite Datum liegt vor dem ersten Datum\n";
			}
			else  {
				cout << "Beide Datumsangaben sind gleich.\n";
			}
		}
	}



	system("PAUSE");
	return 0;
} 