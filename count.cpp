#include <iostream>
using std::cin;
using std::cout;

int main () {
    char number;
    int positiveCount = 0;
    int negativeCount = 0;
    for (int i = 1; i <= 10; i++) {
        cin >> number;
        if (number < 0) negativeCount++;
        if (number > 0) positiveCount++;
    }

    char response;
    cout << "n or p? ";
    cin >> response;
    if (response == 'p') cout << positiveCount;
    if (response == 'n') cout << negativeCount;


}