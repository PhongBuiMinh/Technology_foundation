#include <iostream>
using std::cin;
using std::cout;

struct listNode {
    int studentID;
    int grade;
    listNode * next;
};
typedef listNode * studentCollection;

void addRecord(studentCollection & sc, int studentID, int grade) {
    listNode * newNode = new listNode;
    newNode->studentID = studentID; newNode->grade = grade;
    newNode->next = sc; // dia chi cua sc;
    sc = newNode;
}

int averageRecord(studentCollection sc) {
    int count = 0;
    double sum = 0;
    listNode * loopPtr = sc; //point to itself;
    while (loopPtr != 0) {
        sum += loopPtr->grade;
        count++;
        loopPtr = loopPtr->next;
    } 
    double average = sum /count;
    return average;
}

int main() {
    studentCollection sc;
    listNode * node1 = new listNode;
    node1->studentID = 1001; node1->grade = 78;
    listNode * node2 = new listNode;
    node2->studentID = 1002; node2->grade = 100;
    listNode * node3 = new listNode;
    node3->studentID = 1003; node3->grade = 87;
    sc = node1; // take that memory;
    node1->next = node2;
    node2->next = node3;
    node3->next = 0;
    node1 = node2 = node3 = 0;
    addRecord(sc, 1004, 55);
    int avg = averageRecord(sc);
    cout << avg;
}
