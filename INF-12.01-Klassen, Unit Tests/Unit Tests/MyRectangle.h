#pragma once


//#include "CImgGIP05.h"
#include "CImgGIP05Mock.h"

class MyRectangle {

private:

	int x1 = 0;
	int y1 = 0;
	int x2 = 20;
	int y2 = 20;

public:

	//Konstruktor

	MyRectangle(int, int, int, int);

	//ohne Angaben von Parametern (übernimmt standart werte -> private)

	//MyRectangle() {}

	//getter und Setter setzen(möglichkeit auf Wert änderungen)

	void set_x1(int set_x1) { x1 = set_x1; } //wenn namen gleich dann this->x1 = x1 (this auf private)
	int get_x1() const { return x1; }

	void set_y1(int set_y1) { y1 = set_y1; }
	int get_y1() const { return y1; }


	void set_x2(int set_x2) { x2 = set_x2; }
	int get_x2() const { return x2; }

	void set_y2(int set_y2) { y2 = set_y2; }
	int get_y2() const { return y2; }

	//setter für alle vier gleichzeitig

	void set(int set_x1, int set_y1, int set_x2, int set_y2) {

		x1 = set_x1;
		y1 = set_y1;
		x2 = set_x2;
		y2 = set_y2;
	}

	//zeichnen
	void draw();

	/*void draw() {

		gip_draw_rectangle(x1, y1, x2, y2, blue);
	};*/

	bool does_not_collide_with(const MyRectangle& other) const;

};