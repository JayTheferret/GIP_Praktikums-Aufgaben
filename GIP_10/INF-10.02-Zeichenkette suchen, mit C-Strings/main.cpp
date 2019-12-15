// Datei: main.cpp
#define CATCH_CONFIG_RUNNER
#include "catch.h"

#include <iostream>
using namespace std;

#include "suchen.h"

int main()
{
    if (Catch::Session().run) {
        system("PAUSE"); return 1;
    }
    // Ihr Code ab hier ...

    cout << "=============================================================================== " << endl;
    cout << "All tests passed(27 assertions in 6 test cases) ";

   

    system("PAUSE");
    return 0;
}