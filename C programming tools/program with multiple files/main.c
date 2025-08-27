#include<stdio.h>
#include"math.h"

int main(void)
{
	int a;
	int b;

	printf("Enter number: ");
	scanf("%i", &a);
	printf("\nEnter number: ");
	scanf("%i", &b);
	printf("\nAddition: %i", add(a, b));
	printf("\nSubtraction: %i", subtract(a, b));
	printf("\nMultiplication: %i", multiply(a, b));
	printf("\nDivision: %i", divide(a, b));
	return (0);
}
