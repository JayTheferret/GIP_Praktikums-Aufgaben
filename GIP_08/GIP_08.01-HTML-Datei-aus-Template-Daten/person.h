#pragma once
#include <string>

using namespace std;

struct Person { string nachname, vorname, gebdatum; };

Person extrahiere_person(string eingabezeile);