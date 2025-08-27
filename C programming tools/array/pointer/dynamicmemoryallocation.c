#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

int main(void)
{
	int	*	arr = (int *)malloc(MAX_SIZE * sizeof(int));

	if(arr == NULL)
		exit(1);

	printf("Initialize and display an array: ");
	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr[i] = 1 + i;
		printf("%i ", arr[i]);
	}
	free(arr);
	//system("ls");
	return(0);
}
