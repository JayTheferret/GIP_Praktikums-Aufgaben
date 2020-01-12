#pragma once

class MyRectangle {

private:

	int x1 = 0;
	int y1 = 0;
	int x2 = 20;
	int y2 = 20;

public:

	//Konstruktor
		//Attribute setzen

	MyRectangle(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2){}

	//ohne Angaben von Parametern (�bernimmt standart werte -> private)

	MyRectangle(){}

	//getter und Setter setzen(m�glichkeit auf Wert �nderungen)

	void set_x1(int set_x1) { x1 = set_x1; }
	int get_x1() const { return x1; }

	void set_y1(int set_y1) { y1 = set_y1; }
	int get_y1() const { return y1; }


	void set_x2(int set_x2) { x2 = set_x2; }
	int get_x2() const { return x2; }

	void set_y2(int set_y2) { y2 = set_y2; }
	int get_y2() const { return y2; }

	//setter f�r alle vier gleichzeitig

	void set(int set_x1, int set_y1 , int set_x2, int set_y2) {

		x1 = set_x1;
		y1 = set_y1;
		x2 = set_x2;
		y2 = set_y2;
	}

	void draw() {

		gip_draw_rectangle(x1, y1, x2, y2, blue);
	}

	//Kollisionserkennung

	bool does_not_collide_with(const MyRectangle& other) const {
		
		if (x1 < other.x2 &&  //rechte Kante kleiner -> weiter links
			x2 > other.x1 && 
			y1 < other.y2 &&  //obere Kante
			y2 > other.x1) {
			return false; //keine Kollision
		}

		//else { return true;}
	}
};