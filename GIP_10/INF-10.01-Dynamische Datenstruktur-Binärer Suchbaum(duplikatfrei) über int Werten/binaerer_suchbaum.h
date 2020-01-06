#pragma once

namespace Suchbaum {

	struct BaumKnoten {
		BaumKnoten* child_l;
		BaumKnoten* child_r;
		int value;
	};

	BaumKnoten* einfuegen(int wert, BaumKnoten* root);
	void ausgeben(BaumKnoten* tree);
	void knoten_ausgeben(BaumKnoten* knoten, int tiefe);
}
