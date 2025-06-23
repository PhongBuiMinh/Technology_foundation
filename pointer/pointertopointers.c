#include <stdio.h>

#define ROW 2
#define COLUMN 2

int main(void)
{
	int	arr[ROW][COLUMN];
	int	**pparr = (int *)malloc(ROW * sizeof(int *));

	for(int i = 0; i < ROW; i++)
		pparr[i] = (int *)malloc(COLUMN * sizeof(int));
	
	int	*parr = (int *)malloc(COLUMN * sizeof(int));
	printf("Hmm");

	return(0);
}
