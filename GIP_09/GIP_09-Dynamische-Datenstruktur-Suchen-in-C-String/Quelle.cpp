#include <iostream>
#include <string> //.
using namespace std;

struct TListenKnoten
{
	int data;
	TListenKnoten* next;
	TListenKnoten* prev; //.
};
void hinten_anfuegen(TListenKnoten*& anker, const int wert)
{
	TListenKnoten* neuer_eintrag = new TListenKnoten;
	neuer_eintrag->data = wert;
	neuer_eintrag->next = nullptr;
	neuer_eintrag->prev = nullptr;//.

	if (anker == nullptr)
		anker = neuer_eintrag;
	else
	{
		TListenKnoten* ptr = anker;
		while (ptr->next != nullptr)//während ungleich 0
			ptr = ptr->next;
		ptr->next = neuer_eintrag;

		/*while (ptr->prev != nullptr)
			ptr = ptr->prev;
		ptr->prev = neuer_eintrag;*/

		//Ändern Sie die Funktion hinten_anfuegen()so, dass auch der prev Pointer der Listenknoten jeweils korrekt gesetzt wird.

	}
}
string liste_als_string(TListenKnoten* anker)
{
	string resultat = "";
	if (anker == nullptr)
		return "Leere Liste.";
	else
	{
		resultat += "[ ";
		TListenKnoten* ptr = anker;
		do
		{
			resultat += std::to_string(ptr->data);
			if (ptr->next != nullptr) resultat += " , ";
			else resultat += " ";
			ptr = ptr->next;
		} while (ptr != nullptr);
		resultat += "]";
	}
	return resultat;
}
void liste_ausgeben(TListenKnoten* anker)
{
	cout << liste_als_string(anker) << endl;
}
int main()
{
	const int laenge = 10;
	TListenKnoten* anker = nullptr;
	liste_ausgeben(anker);
	for (int i = 0; i < laenge; i++)
		hinten_anfuegen(anker, i * i);
	liste_ausgeben(anker);
	system("PAUSE");
	return 0;
}
