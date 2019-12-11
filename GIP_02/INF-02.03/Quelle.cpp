#include <iostream>
using namespace std;

int main()
{
	double Meter = 0;

	cout << "Bitte geben Sie die Laenge in Metern ein: ? ";
	cin >> Meter;


	cout << "Die Laenge in Fuss lautet: " << Meter*3.2808 << endl;

	system("PAUSE");
	return 0;
}