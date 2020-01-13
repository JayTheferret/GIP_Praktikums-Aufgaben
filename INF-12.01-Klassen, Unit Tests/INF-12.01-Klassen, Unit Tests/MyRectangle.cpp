#include "MyRectangle.h"
#include "CImgGIP05.h"

//Konstruktor
		//Attribute setzen

MyRectangle::MyRectangle(int x1, int y1, int x2, int y2) 
	: x1(x1), y1(y1), x2(x2), y2(y2) {} // Attribute aus Private damit gleichsetzen

void MyRectangle::draw() {

	gip_draw_rectangle(x1, y1, x2, y2, blue);
}

//Kollisionserkennung

bool MyRectangle::does_not_collide_with(const MyRectangle& other) const {

	if (x2 < other.x1 ||
		other.x2 < x1 ||

		other.y1 > y2 ||
		y1 > other.y2) {
		return true;
	}

	return false;
}