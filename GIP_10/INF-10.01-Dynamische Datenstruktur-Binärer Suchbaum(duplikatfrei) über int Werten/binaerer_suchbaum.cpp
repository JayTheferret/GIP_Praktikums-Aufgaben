#include <string>
#include "binaerer_suchbaum.h"

#include <iostream>

void einfuegen(Suchbaum::BaumKnoten*& head, Suchbaum::BaumKnoten* knoten)
{
    Suchbaum::BaumKnoten* current = head;
    while (current)
    {
        if (knoten->data == current->data)
        {
            delete knoten;
            return;
        }

        if (knoten->data < current->data)
        {
            if (current->left_child)
                current = current->left_child;
            else
            {
                current->left_child = knoten;
                break;
            }
        }

        else if (knoten->data > current->data)
        {
            if (current->right_child)
                current = current->right_child;
            else
            {
                current->right_child = knoten;
                break;
            }
        }
    }
}

void Suchbaum::einfuegen(Suchbaum::BaumKnoten*& head, int data)
{
    BaumKnoten* knoten = new BaumKnoten;
    knoten->data = data;
    knoten->parent = nullptr;
    knoten->left_child = nullptr;
    knoten->right_child = nullptr;

    if (!head)
    {
        head = knoten;
        return;
    }

    einfuegen(head,knoten);
}

void Suchbaum::ausgeben(BaumKnoten* head)
{
    knoten_ausgeben(head, 0);
}

void Suchbaum::knoten_ausgeben(BaumKnoten* knoten, int depth)
{
    if (!knoten)
    {
        std::cout << "Leerer Baum." << std::endl;
        return;
    }

    if (knoten->right_child)
        knoten_ausgeben(knoten->right_child, depth + 1);

    for (int i = 0; i < depth; ++i)
        std::cout << "++";

    std::cout << knoten->data << std::endl;

    if (knoten->left_child)
        knoten_ausgeben(knoten->left_child, depth + 1);
}