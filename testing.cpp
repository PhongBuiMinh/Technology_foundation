#include <iostream>
using std::cin;
using std::cout;

int lengthNumber(int n) {
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

int caretOperator(int n) {
    int careted = 1; 
    while (n != 1) {
        careted *= 10;
        n--;
    }
    return careted;
}

int main() {
    int a = 467;
    int length = lengthNumber(a);

    char b[length];
    for (int i = 0; i < length; i++) {
        b[i] = (a / caretOperator(length - i)) + '0';
        a = a % caretOperator(length - i);
    }

    char * c = new char[length + 1];
    for (int i = 0; i < length; i++) {
        c[i] = b[i];
    }

    cout << c;
    
}