#include <iostream>
using namespace std;

int main()
{
	double Euro = 0;

	cout << "Bitte geben Sie die Geldmenge in Euro ein: ? ";
	cin >> Euro;


	cout << "Die Geldmenge in US Dollar lautet: " << Euro * 1.2957 << endl;

	system("PAUSE");
	return 0;
}