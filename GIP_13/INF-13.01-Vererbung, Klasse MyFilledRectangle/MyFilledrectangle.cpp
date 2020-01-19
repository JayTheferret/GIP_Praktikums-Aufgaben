#include "MyFilledRectangle.h"
#include "CImgGIP05.h"


void MyFilledRectangle::draw() {

    MyRectangle::draw();

    //(linker bis rechter Rand), allerdings mit jeweils einem Abstand von 2 Pixeln zum Rand.
       // D.h.das Rechteck wird durch lauter horizontale rote Linien ausgefüll

    if (x2 - x1 <= 4 || y2 - y1 <= 4)
        return;  //wenn zu klein für Abstand von 2 Pixeln -> nur rectangle zeichnen

    for (int y = y1 + 2; y < y2 - 2; ++y) { // Abstand zum rand behalten
        gip_draw_line(x1 + 2, y, x2 - 2, y, red);
    }
    //gip_draw_line(x1, y1, x2, y2, red);
}