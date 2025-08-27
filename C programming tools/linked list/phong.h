#ifndef PHONG_H
#define PHONG_H

#include <stdio.h>
#include <stdlib.h>

struct node {
	char vehicle[20];
	int year;
	int cylinders;
	int displacement;
	int top_speed;
	struct node * nextnode;
};

#endif
