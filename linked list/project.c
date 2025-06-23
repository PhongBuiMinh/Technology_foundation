#include "phong.h"

int	main(void)
{
	// Initialize nodes  
	struct node * bmw1 = (struct node *)malloc(sizeof(struct node));
	struct node * bmw2 = (struct node *)malloc(sizeof(struct node));
	struct node * bmw3 = (struct node *)malloc(sizeof(struct node));

	struct node * traverse = (struct node *)malloc(sizeof(struct node));

	// Initialize node's characteristics
	bmw1->year = 2010;
	bmw1->cylinders = 2;
	bmw1->displacement = 999;
	bmw1->top_speed = 214;
	bmw1->nextnode = bmw2;

	bmw2->year = 2020;
	bmw2->cylinders = 3;
	bmw2->displacement = 1060;
	bmw2->top_speed = 300;
	bmw2->nextnode = bmw3;

	printf("Add 1 vehicle to the linked list structure.\n");
	scanf("%i", &bmw3->year);
	scanf("%i", &bmw3->cylinders);
	scanf("%i", &bmw3->displacement);
	scanf("%i", &bmw3->top_speed);
	bmw3->nextnode = NULL;

	traverse = bmw1;

	// Display data
	printf("--------------\n");
	printf("Display elements of the 1st node manually.\n");
	printf("%i\n", bmw1->year);
	printf("%i\n", bmw1->cylinders);
	printf("%i\n", bmw1->displacement);
	printf("%i\n", bmw1->top_speed);

	printf("--------------\n");
	printf("Traverse linked list.\n");
	for (int i = 1; traverse != NULL; i++)
	{
		printf("BMW%i: %i ", i, traverse->year);
		printf("%i ", traverse->cylinders);
		printf("%i ", traverse->displacement);
		printf("%i \n", traverse->top_speed);
		traverse = traverse->nextnode;
	}
	
	free(bmw1);
	free(bmw2);
	free(bmw3);
	free(traverse);
	return (0);
}
