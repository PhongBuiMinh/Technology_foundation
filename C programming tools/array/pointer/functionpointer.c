#include <stdio.h>

#define MAX_SIZE 3

void sum(int a, int b, int c)
{
	printf("Sum: %i", a + b + c);
	return;
}

int main(void)
{
	int		a, b, c;
	void	(*fptr)(int, int, int);
	int		arr[MAX_SIZE] = {2, 3, 4};
	int		(*aptr)[MAX_SIZE];

	a = 5;
	b = 5;
	c = 5;
	
	aptr = &arr;
	printf("%i\n", (*aptr)[0]);
	fptr = &sum;
	fptr(a, b, c);
	return(0);
}
