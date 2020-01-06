#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP05.h"
using namespace std;
using namespace cimg_library;

const int grid_size = 10; // Anzahl an Kaestchen in x- und y-Richtung
const int box_size = 30;  // size der einzelnen Kaestchen (in Pixel)
const int border = 20;    // Rand links und oben bis zu den ersten Kaestchen (in Pixel)

// Prototyp der Funktionen zum Vorbelegen des Grids ...
void grid_init(bool grid[][grid_size]);

//--
int count_living_neighbours(int zelle_x, int zelle_y, bool grid[][grid_size]) {

	int living_neighbours = 0;
	int deltas[8][2] = { //verschiebungen, Nachbarn
		{-1, -1},
		{ 0, -1},
		{+1, -1},
		{-1,  0},
		{+1,  0},
		{-1, +1},
		{ 0, +1},
		{+1, +1},
	};

	

	for (int i = 0; i < 8; i++) {//deltas durchlaufen
		//nachbar Positionen generieren
		int x = zelle_x + deltas[i][0]; 
		int y = zelle_y + deltas[i][1];

		// Ausserdem darf bei zellen am rand nicht über den Rand hinausgegriffen
		// werden (diese Zellen haben entsprechend weniger Nachbarn) ...
		if (
			x >= 0 && x < grid_size
			&&
			y >= 0 && y < grid_size
			&&
			grid[x][y] == true
			) {
			//Nachbaranzahl hochzählen
			living_neighbours++;
		}
	}
	return living_neighbours;
}
//--

int main()
{
	bool grid[grid_size][grid_size] = { 0 };
	bool next_grid[grid_size][grid_size] = { 0 };

	// Erstes Grid vorbelegen ...
	grid_init(grid);

	while (gip_window_not_closed())
	{
		// Spielfeld anzeigen ...

		gip_stop_updates(); // ... schaltet das Neuzeichnen nach jeder Bildschirmänderung aus

		// TO DO
		//--

		for (int y = 0; y < grid_size; y++) {
			for (int x = 0; x < grid_size; x++) {

				const unsigned char* color;

				if (grid[x][y] == true) { //if true dann zelle //true könnte auch wegbleiben
					color = green;
				}
				else {
					color = white;
				}

				gip_draw_rectangle(
					//linke obere ecke
					border + box_size * x, //X
					border + box_size * y,	//Y
					//rechte untere ecke
					border + box_size + box_size * x, //X
					border + box_size + box_size * y, //Y
					//Farbe
					color);
			}
		}
		//--

		gip_start_updates(); // ... alle Bildschirmänderungen (auch die nach dem gip_stop_updates() ) wieder anzeigen

		gip_sleep(3);

		//--

		// Berechne das naechste Spielfeld ...
		// Achtung; Für die Zelle (x,y) darf die Position (x,y) selbst *nicht*
		// mit in die Betrachtungen einbezogen werden.
		//funktion---vvvv
		// Ausserdem darf bei zellen am rand nicht über den Rand hinausgegriffen
		// werden (diese Zellen haben entsprechend weniger Nachbarn) ...

		for (int y = 0; y < grid_size; y++) {
			for (int x = 0; x < grid_size; x++) {

				int living = count_living_neighbours(x, y, grid);//funktion-> lebende nachbarn zählen
				if ((living == 2 || living == 3) && grid[x][y] == true) {//wenn zwei/drei Nachbarn, und zelle leben
					next_grid[x][y] = true;
				}
				else if (living == 3 && grid[x][y] == false) {
					next_grid[x][y] = true;
				}
				else {
					next_grid[x][y] = false;
				}
			}
		}

		//--

		// Kopiere das naechste Spielfeld in das aktuelle Spielfeld ...

		//--

		for (int y = 0; y < grid_size; y++) {
			for (int x = 0; x < grid_size; x++) {
				grid[x][y] = next_grid[x][y];
			}
		}

		//--

	}
	return 0;
}

void grid_init(bool grid[][grid_size])
{
	int eingabe = -1;
	do {
		cout << "Bitte waehlen Sie die Vorbelegung des Grids aus:" << endl
			<< "0 - Zufall" << endl
			<< "1 - Statisch" << endl
			<< "2 - Blinker" << endl
			<< "3 - Oktagon" << endl
			<< "4 - Gleiter" << endl
			<< "5 - Segler 1 (Light-Weight Spaceship)" << endl
			<< "6 - Segler 2 (Middle-Weight Spaceship)" << endl
			<< "? ";
		cin >> eingabe;
		cin.clear();
		cin.ignore(1000, '\n');
	} while (eingabe < 0 || eingabe > 6);

	if (eingabe == 0)
	{
		// Erstes Grid vorbelegen (per Zufallszahlen) ...
		//--
		for (int y = 0; y < grid_size; y++) {
			for (int x = 0; x < grid_size; x++) {
				grid[x][y] = gip_random(0, 1); //1 = true 0 =false (bool)
			}
		}
		//--    
		// TO DO

	}
	else if (eingabe == 1)
	{
		const int pattern_size = 3;
		char pattern[pattern_size][pattern_size] =
		{
			{ '.', '*', '.' },
			{ '*', '.', '*' },
			{ '.', '*', '.' },
		};
		for (int y = 0; y < pattern_size; y++)
			for (int x = 0; x < pattern_size; x++)
				if (pattern[y][x] == '*')
					grid[x][y + 3] = true;
	}
	else if (eingabe == 2)
	{
		const int pattern_size = 3;
		char pattern[pattern_size][pattern_size] =
		{
			{ '.', '*', '.' },
			{ '.', '*', '.' },
			{ '.', '*', '.' },
		};
		for (int y = 0; y < pattern_size; y++)
			for (int x = 0; x < pattern_size; x++)
				if (pattern[y][x] == '*')
					grid[x][y + 3] = true;
	}
	else if (eingabe == 3)
	{
		const int pattern_size = 8;
		char pattern[pattern_size][pattern_size] =
		{
			{ '.', '.', '.', '*', '*', '.', '.', '.' },
			{ '.', '.', '*', '.', '.', '*', '.', '.' },
			{ '.', '*', '.', '.', '.', '.', '*', '.' },
			{ '*', '.', '.', '.', '.', '.', '.', '*' },
			{ '*', '.', '.', '.', '.', '.', '.', '*' },
			{ '.', '*', '.', '.', '.', '.', '*', '.' },
			{ '.', '.', '*', '.', '.', '*', '.', '.' },
			{ '.', '.', '.', '*', '*', '.', '.', '.' },
		};
		for (int y = 0; y < pattern_size; y++)
			for (int x = 0; x < pattern_size; x++)
				if (pattern[y][x] == '*')
					grid[x][y + 1] = true;
	}
	else if (eingabe == 4)
	{
		const int pattern_size = 3;
		char pattern[pattern_size][pattern_size] =
		{
			{ '.', '*', '.' },
			{ '.', '.', '*' },
			{ '*', '*', '*' },
		};
		for (int y = 0; y < pattern_size; y++)
			for (int x = 0; x < pattern_size; x++)
				if (pattern[y][x] == '*')
					grid[x][y + 3] = true;
	}
	else if (eingabe == 5)
	{
		const int pattern_size = 5;
		char pattern[pattern_size][pattern_size] =
		{
			{ '*', '.', '.', '*', '.' },
			{ '.', '.', '.', '.', '*' },
			{ '*', '.', '.', '.', '*' },
			{ '.', '*', '*', '*', '*' },
			{ '.', '.', '.', '.', '.' },
		};
		for (int y = 0; y < pattern_size; y++)
			for (int x = 0; x < pattern_size; x++)
				if (pattern[y][x] == '*')
					grid[x][y + 3] = true;
	}
	else if (eingabe == 6)
	{
		const int pattern_size = 6;
		char pattern[pattern_size][pattern_size] =
		{
			{ '.', '*', '*', '*', '*', '*' },
			{ '*', '.', '.', '.', '.', '*' },
			{ '.', '.', '.', '.', '.', '*' },
			{ '*', '.', '.', '.', '*', '.' },
			{ '.', '.', '*', '.', '.', '.' },
			{ '.', '.', '.', '.', '.', '.' },
		};
		for (int y = 0; y < pattern_size; y++)
			for (int x = 0; x < pattern_size; x++)
				if (pattern[y][x] == '*')
					grid[x][y + 3] = true;
	}
}
