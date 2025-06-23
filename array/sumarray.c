#include <stdio.h>

#define MAX_LENGTH 3

int main(void)
{
	int sum;
	int arr[MAX_LENGTH] = {16, 20, 60};

	for (int i = 0; i < MAX_LENGTH; i++)
		printf("%i\n", arr[i]);

	sum = 0;
	for (int i = 0; i < MAX_LENGTH; i++)
		sum += arr[i]; 
	printf("Sum: %i\n", sum);
	return(0);
}
