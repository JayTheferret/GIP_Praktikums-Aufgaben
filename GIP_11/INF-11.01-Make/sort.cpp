#include <iostream>

using namespace std;

void sortiere(int a[], int N) { //nach Größe sortieren

    int temp, i, j;

    for (i = 0; i <= N - 1; i++) { // Alle Arraypositionen durchgehen

        for (j = i + 1; j < N; j++) { //nächste Zahl

            if (a[i] > a[j]) { //wenn i größer als j -> i eins weiter nach hinten/tauschen

                temp = a[i]; 
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}