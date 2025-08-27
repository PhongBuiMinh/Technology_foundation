#include <iostream>
using std::cin;
using std::cout;

typedef const char * string;

int main() {
    string description = "abc";
    int count = 0;
    while (description[count] != 0){
        count++;
    }
    cout << count; 
}
