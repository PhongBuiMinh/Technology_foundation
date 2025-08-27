#include <iostream>
using std::cin;
using std::cout;

int main() {
    int *pointerA, *pointerB, variable1 = 5;
    cout << "PointerA's value: " << pointerA << "\n";
    cout << "PointerA's address: " << &pointerA << "\n";
    cout << "PointerB's value: " << pointerB << "\n";

    cout << "\n";

    cout << "Variable1's address: " << &variable1 << "\n";

    cout << "\n";

    pointerA = &variable1;
    pointerB = pointerA;

    cout << "PointerA's value: " << pointerA << "\n";
    cout << "PointerA's address: " << &pointerA << "\n";
    cout << "PointerB's value: " << pointerB << "\n";
    
    cout << "\n";

    int * pointerC = new int;
    *pointerC = 13;
    int variable2 = *pointerC; 
    cout << *pointerC << " " << variable2 << "";

    char * pointerD = new char[3];
    pointerD = "abc";
    cout << "D: " << *pointerD << "\n";
}