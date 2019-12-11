#include <string>
#include "texte.h"

using namespace std;

 void spalte_ab_erstem(string eingabezeile, char zeichen, string& input, string& rest) {

	 bool done = false;

	 for (int i = 0; i < eingabezeile.size(); i++) { //durchlaufen

		 if (!done) {
			 if (eingabezeile.at(i) != zeichen) {
				 input = input + eingabezeile.at(i);
			 }
			 else {
				 done = true;
				 i++;
			 }
		 }
		 else {
			 rest = rest + eingabezeile.at(i);
		 }

	 }

 }

string trimme(string text) {
	 string out = "";

	 for (unsigned int i = 0; i < text.size(); i++) { //text durchlaufen
		 if (text.at(i) != ' ') { //ohne leerzeichen
			 out += text.at(i);
		 }
	 }

	 return out;
 }

 string ersetze(string in, char comp, string rep) {
	 string out = "";

	 for (unsigned int i = 0; i < in.size(); i++) { //text durchlaufen
		 if (in.at(i) != comp) {//alles außer comp (zeichen) in out
			 out += in.at(i);
		 }
		 else {
			 out += rep;
		 }
	 }

	 return out;
 }
