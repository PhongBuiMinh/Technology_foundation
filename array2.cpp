#include <iostream>
using std::cin;
using std::cout;

int main() {
    const int ARRAY_SIZE = 8;
    const char punctuation[ARRAY_SIZE] = {'!', '?', ',', '.', ' ', ';', '"', '\''};

    struct student {
        int grade;
        int ID;
        char name[];
    };

    student studentArray[ARRAY_SIZE] = {
        {88, 101, 'A'}, 
        {50, 102, 'B'},
        {90, 103, 'C'},
        {27, 104, 'D'},
        {35, 105, 'E'}
    };

    int highestGrade = studentArray[0].grade;
    for (int i = 1; i < ARRAY_SIZE; i++) {
        if (studentArray[i].grade > highestGrade) highestGrade = studentArray[i].grade;
    }

    cout << highestGrade << "\n";
    
    int highPosition = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (studentArray[i].grade > studentArray[highPosition].grade) highPosition = i; 
    }
    
    cout << studentArray[highPosition].ID << "\n";

    const int AGENT_NUMBERS = 3;
    const int MONTH_NUMBERS = 12;
    int sales[AGENT_NUMBERS][MONTH_NUMBERS] = {
        {23, 423, 63, 435, 63, 2, 234, 5, 65, 23, 45, 75},
        {1, 2, 4, 6, 7, 8, 9, 78, 56, 78, 90, 67},
        {123, 345, 456, 4567, 789, 654, 257, 567, 876, 253, 753, 105}
    };

    int highestSale = sales[0][0];
    for (int i = 0; i < AGENT_NUMBERS; i++) {
        for (int j = 1; j < MONTH_NUMBERS; j++) {
            //if (sales[i][j] > sales[highestSale][highestSale]) {
            //    highestSale = 
            //}
            if (sales[i][j] > highestSale) highestSale = sales[i][j];
        }
    }
    cout << highestSale;

}