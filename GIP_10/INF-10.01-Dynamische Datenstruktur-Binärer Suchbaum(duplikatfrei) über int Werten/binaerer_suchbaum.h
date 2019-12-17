#pragma once

namespace Suchbaum
{
    struct BaumKnoten
    {
        int data;
        BaumKnoten* parent;
        BaumKnoten* left_child;//kleiner
        BaumKnoten* right_child;//größer
    };

    void einfuegen(BaumKnoten*& head, int data);
    void ausgeben(BaumKnoten* head);
    void knoten_ausgeben(BaumKnoten* knoten, int tiefe);

}