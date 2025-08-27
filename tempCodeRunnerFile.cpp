#include <iostream>
using std::cin;
using std::cout;

int main() {
    int a[3] = 100;
    char b;
    for (int i = 0; i < 3; i++) {
        b = a[i] + '0';
    }
    cout << b;

}