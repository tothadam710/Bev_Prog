#include <iostream>
#include "kutyak.h"

using namespace std;




int main()
{
   
    string name = "Morzsi";
    int age = 12;
    bool chip = false;
    

    kutyak Morzsi(name,age,chip);

    Morzsi.adatok();
    Morzsi.kutyaev(age);
    Morzsi.chippel(chip);

    return 0;
}


