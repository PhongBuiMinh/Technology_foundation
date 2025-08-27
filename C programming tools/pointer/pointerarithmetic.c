#include <stdio.h>

int main(void)
{
	int	i[5] = {1, 2, 3, 4, 5};
	int	*	ptr;
	int	j;

	ptr = i;
	j = 0;
	printf("Array: ");
	while (j < 5)
	{
		printf("%i ", *(ptr + j));
		j++;
	}
		
	return(0);
}
