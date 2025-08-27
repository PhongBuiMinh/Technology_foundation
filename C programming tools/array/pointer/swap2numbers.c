#include <stdio.h>

void	swap(int * a, int * b)
{
	int	tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
	int	a;
	int b;
	int	tmp;

	swap(&a, &b);

	return(0);
}
