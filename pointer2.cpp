#include <iostream>
using std::cin;
using std::cout;

typedef char * string;

char CharacterAt(string s, int position) {
    return s[position];
}

int length(string s) {
    int length = 0;
    while(s[length] != 0) {
        length++;
    }
    return length;
}

void append(string &s, char c) {
    int oldLength = length(s);
    string newS = new char[oldLength + 2];
    for(int i = 0; i < oldLength; i++) {
        newS[i] = s[i];
    }
    newS[oldLength] = c;
    newS[oldLength + 1] = 0;
    delete[] s;
    s = newS;
}

void appendTester() {
    string a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4]= 0;
    append(a, '!');
    cout << a << "\n";

    string b = new char[1];
    b[0] = 0;
    append(b, '!');
    cout << b << "\n";
}

void concatenate(string &a, string b) {
    int firstLength = length(a);
    int secondLength = length(b);
    string newA = new char[firstLength + secondLength + 1]; 
    for (int i = 0; i < firstLength; i++) {
        newA[i] = a[i]; 
    }
    for (int i = 0; i < secondLength; i++) {
        newA[firstLength + i] = b[i];
    }
    newA[firstLength + secondLength] = 0;
    delete[] a;
    a = newA;
}

// int main
void concatenateTester() {
    string a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4]= 0;
    string b = new char[4];
    b[0] = 'b'; b[1] = 'e'; b[2] = 'd'; b[3] = 0;
    string c = new char[1];
    c[0] = 0;
    concatenate(c, a);
    delete[] c;
    cout << a << "\n" << c << "\n";
    cout << (void *) a << "\n" << (void *) c << "\n";
}

/*
int main() {
    
    const int intsPerKilobyte = 1024 / sizeof(int);
    while (true) {
        int *oneKilobyteArray = new int[intsPerKilobyte];
    }
    
}
*/

