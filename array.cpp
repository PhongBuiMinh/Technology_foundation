#include <iostream>
using std::cin;
using std::cout;

int	compareFunc(const void * voidA, const void * voidB) {
	int *intA = (int *)(voidA);
	int *intB = (int *)(voidB);
	return *intA - *intB;
}

int main() {
	const int ARRAY_SIZE = 12;
	const int MAX_RESPONSE = 10;
	int array[ARRAY_SIZE] = {8,5,4,5,9,6,5,8,5,10};
	int histogram[MAX_RESPONSE];

	for (int i = 0; i < MAX_RESPONSE; i++) {
		histogram[i] = 0;
	}

	for (int i = 0; i < ARRAY_SIZE; i++) {
		histogram[array[i] - 1]++;
	}

	int mostFrequent = histogram[0];
	for (int i = 1; i < MAX_RESPONSE; i++) {
		if (histogram[i] > mostFrequent) {
			mostFrequent = i;
		}
	}
	mostFrequent++;

	cout << mostFrequent;

	/*
	int firstArray[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++) firstArray[i] = -5;
	for (int j = 0; j < ARRAY_SIZE; j++) cout << firstArray[j] << "\n";

	cout << "\n";

    int secondArray[10];
    for (int i = 0; i < ARRAY_SIZE; i++) secondArray[i] = firstArray[i];
    for (int j = 0; j < ARRAY_SIZE; j++) cout << "Second: " << secondArray[j] << "\n";

    cout << "\n";

    int number = array[2];
    cout << number << "\n";

    int targetValue = 90;
    int targetPos = 0;
    while (targetPos < ARRAY_SIZE && array[targetPos] != targetValue)
        targetPos++;
    cout << targetPos;

    int highestValue = array[0];
    for (int i = 1
    ; i < ARRAY_SIZE; i++) {
            if (array[i] > highestValue) highestValue = array[i];
    }
    cout << highestValue;


    qsort(array, ARRAY_SIZE, sizeof(int), compareFunc);
    for (int i = 0; i < ARRAY_SIZE; i++) cout << "Pos: " << i << ". Value: " << array[i] << "\n";

    int modeCharacter;
    int highestFrequency = 0;
    int currentFrequency = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        currentFrequency++;
        if (i == ARRAY_SIZE - 1 || array[i] != array[i+1]) {
            if (currentFrequency > highestFrequency) {
                highestFrequency = currentFrequency;
                modeCharacter = array[i];
            }
            currentFrequency = 0;
        }
    }

    cout << "Mode: " << modeCharacter << ". Frequency: " << highestFrequency << "\n";
*/
}
