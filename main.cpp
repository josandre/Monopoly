#include <iostream>
#include "Core/Node.h"
#include "Core/Node.cpp"
#include "Models/Property.h"
#include "Models/SpecialCard.h"

using namespace std;

int main() {
   Property prop = *new Property("Avenida mediterrane", "Brown", 60, 2, 30, 50, 50, 33);
   auto specialCard = *new SpecialCard("Exit jail free", "Use this card to exit jail for free", 0, 0 , ExitJail);

    cout <<  specialCard.toString() << std::endl;
    return 0;
}
