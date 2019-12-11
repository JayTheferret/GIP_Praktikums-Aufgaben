#include <iostream>
using namespace std;

int main()
{
	double Celsius = 0;

	cout << "Bitte geben Sie die Temperatur in grad Celsius ein: ? ";
	cin >> Celsius;

	
	cout << "Die Temperatur in Fahrenheit lautet: " << Celsius * 1.8 + 32 <<endl;

	system("PAUSE");
	return 0;
}