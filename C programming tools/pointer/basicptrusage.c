#include <stdio.h>

int main(void)
{
	int	i;
	int	*	ptr;

	i = 5;
	ptr = &i;
	printf("Value: %i", *ptr);
	return(0);
}
