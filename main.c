#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

#define SIZE 50

int main() //Gubenko Olesya 112
{
	double x, array_x[SIZE], array_y[SIZE];
	function();
	FILE *IN = fopen("input.txt", "rt");
	if(IN==NULL)
	{
		printf("Input file cannot be opened.\n");
		return -1;
	}
	int i;
	for(i = 0; i<SIZE; i++)
	{
		if(fscanf(IN, "%lf%lf", &array_x[i], &array_y[i])!=2){
			printf("Missed points.\n");
			return -1;
		}
	}
	fclose(IN);
	if (sort(array_x, array_y)!=0){
		printf ("Problem with sorting.\n");
		return -1;
	}

	/*for (i=0; i<SIZE; i++){
		printf("%lf\t\t%lf\n", array_x[i], array_y[i]);
	}*/


	printf("Enter x.\n");
	if (scanf("%lf", &x)!=1){
		printf("Unexpectable x.\n");
		return -1;
	}
	double y = lagranz(x, array_x, array_y);
	printf("y: %lf\n", y);
	return 0;
}
