#include <stdio.h>

typedef struct s_car
{
	int	a;
	int	b;
} car;

int	main(void)
{
	car audi;
	car toyota;
	car * ptr = &audi;
	car	* newptr;

	toyota = audi;
	audi.b = 4;
	ptr->a = 5;

	newptr = (car *)malloc(sizeof(car));
	if(newptr == NULL)
		exit(1);

	newptr->a = 6;
	newptr->b = 7;

	free(newptr);
	return(0);
}
