#include <iostream>
#include "Core/Node.h"
#include "Core/Node.cpp"

using namespace std;

int main() {
    auto *node = new Node<int>( 5);

    cout <<  node->getData() << std::endl;
    return 0;
}
