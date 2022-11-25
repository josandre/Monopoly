#include <iostream>
#include "Monopoly/Core/Nodo.h"
using namespace std;

int main() {
    auto *nodo = new Nodo<int>( 5);


    cout << nodo->getData() << std::endl;
    return 0;
}
