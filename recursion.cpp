#include <iostream>
using std::cin;
using std::cout;

int iterativeArraySum(int intArray[], int size) {
    int sum = intArray[0];
    for (int i = 1; i < size; i++) {
        sum += intArray[i];
    }
    return sum;
}

int arraySumDelegate(int intArray[], int size) {
    if (size == 0) return 0;
    int lastNumber = intArray[size - 1];
    int allButLastSum = iterativeArraySum(intArray, size - 1);
    return lastNumber + allButLastSum;
}

int arraySumRecursive(int intArray[], int size) {
    if (size == 0) return 0;
    int lastNumber = intArray[size - 1];
    int allButLastSum = arraySumRecursive(intArray, size - 1);
    return lastNumber + allButLastSum;
}

int iterativeArrayCount(int array[], int arraySize) {
    int count = 0;
    for (int i = 0; i  < arraySize; i++) {
        if (array[i] == 0) count++;
    }
    return count;
}

int delegateArrayCount(int array[], int arraySize) {
    if (arraySize == 0) return 0;
    int count = iterativeArrayCount(array, arraySize - 1);
    if (array[arraySize] == 0)
        count++;
    return count;
}

int recursiveArrayCount(int array[], int arraySize) {
    if (arraySize == 0) return 0;
    int count = recursiveArrayCount(array, arraySize - 1);
    if (array[arraySize] == 0)
        count++;
    return count;
}

int recursiveFactor(int n) {
    if (n == 1) return 1;
    int smallerN = recursiveFactor(n - 1);
    return n * smallerN;
}

int main() {
    int arraySize = 5;
    int intArray[arraySize] = {1, 0, 3, 0, 8};
    cout << arraySumRecursive(intArray, arraySize) << "\n";
    cout << recursiveArrayCount(intArray, arraySize) << "\n";

    int number = 9;
    cout << recursiveFactor(number) << "\n";
}
