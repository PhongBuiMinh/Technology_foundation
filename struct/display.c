#include <stdio.h>
#include "phong.h"

int main (void)
{
	student student1;
	struct s_student student2;

	printf("Enter student 1 name, age, total marks:\n");
	scanf("%s", student1.name);
	scanf("%i", &student1.age);
	scanf("%i", &student1.total_mark);

	printf("Enter student 2 name, age, total marks:\n");
	scanf("%s", student2.name);
	scanf("%i", &student2.age);
	scanf("%i", &student2.total_mark);

	printf("\nStudent1: %s %i %i\n", student1.name, student1.age, student1.total_mark);
	printf("Student2: %s %i %i\n", student2.name, student2.age, student2.total_mark);
	printf("average: %f\n", (float)(student1.total_mark + student2.total_mark) / 2);
	
	student student_clone;
	student_clone = student1;

	printf("\nStudent1: %s %i %i\n", student_clone.name, student_clone.age, student_clone.total_mark);

	return (0);
}
