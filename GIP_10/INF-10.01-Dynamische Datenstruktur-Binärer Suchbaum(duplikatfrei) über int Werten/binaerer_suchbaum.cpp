#include <iostream>
#include "binaerer_suchbaum.h";

Suchbaum::BaumKnoten* Suchbaum::einfuegen(int value, BaumKnoten* root) {

	if (root == nullptr) { //wenn Baum leer
		
		root = new BaumKnoten;
		root->value = value; //zeigt auf wert -> schreibt neuen Wert rein
		root->child_l = nullptr;
		root->child_r = nullptr;
	}

	else {

		BaumKnoten* current = root; //aktueller als Kopie von root
		BaumKnoten* prev = nullptr; //vorheriger

		while (current != nullptr) {

			prev = current; //auf den vorherigen setzen (dieser geht eins weiter)

			if (value > current->value) { //wert größer als current wert
				current = current->child_r; //eins weiter -> rechts
			}
			else if (value < current->value) {
				current = current->child_l;
			}
			else { //wert existiert bereits -> Schleife verlasen
				return root; //kein break-> ansonsten falsche ausführung
			}
		}
		BaumKnoten* child = new BaumKnoten; //neuen Knoten erstellen
		child->value = value; //Knoten den wert übergeben
		child->child_l = nullptr;
		child->child_r = nullptr;

		if (value > prev->value) {
			prev->child_r = child; //rechts anhängen
		}
		else {
			prev->child_l = child;//links anhängen
		}
	}

	return root;
}

void Suchbaum::knoten_ausgeben(BaumKnoten* knoten, int tiefe) {

	if (knoten == nullptr) { //wenn aktueller teilbaum leer -> return
		return;
	}

	// rechten Teilbaum ausgeben

	knoten_ausgeben(knoten->child_r, tiefe + 1);

	//aktuellen wert ausgeben

	for (int i = 0; i < tiefe; i++) { 
		std::cout << "++";
	}
	std::cout << knoten->value << std::endl; //wert ausgeben

	// linken Teilbaum ausgeben

	knoten_ausgeben(knoten->child_l, tiefe+1);
}

void Suchbaum::ausgeben(BaumKnoten* tree){

	if (tree == nullptr) {
		std::cout << "Leerer Baum." << std::endl; //falls Baum leer
	}
	else {
		knoten_ausgeben(tree, 0); //baum an ausgabefunktion geben, tiefe mit null starten
	}
}
