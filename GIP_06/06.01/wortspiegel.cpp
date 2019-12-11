#include <string>
using namespace std;

void wortspiegel(string& text, int pos) {

		int start = 0;
		int end = 0;
		int spos = 0; //position stern/auswahl

		string temp = ""; //spiegeln ohne original zu verfälschen

		if (text.at(pos) != ' ' && text.at(pos) != '.' && text.at(pos) != ',') { //nur ausführen wenn keine satzzeichen etc. in auswahl
			spos = pos;

			while (spos > 0) {

				//anfang vom wort finden

				if (text.at(spos) == ' ' || text.at(spos) == '.' || text.at(spos) == ',') { 
					spos++;  break; 
				}

				spos--; //so lange nach links bis anfang gefunden(falls satzzeichen eins nach rehts und break
			}

			start =  spos; //anfang vom wort
			spos = pos; //zurücksetzen

			while (spos < text.size() - 1) {

				if (text.at(spos) == ' ' || text.at(spos) == '.' || text.at(spos) == ',') { 
					spos--; break; 
				}

				spos++;
			}

			end = spos; //ende vom wort (s.o.)

			for (int i = 0; i <= end - start; i++) {	//für wortlänge
				temp = text.at(start + i) + temp;  //spiegeln (wort hinten dran, buchstabe vorne)
			}

			for (int i = 0; i <= end - start; i++) {
				text.at(start + i) = temp.at(i); //-> ausgabe des eingangs
			}
		}
	}