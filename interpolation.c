#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

#define SIZE 15

double f(double x) { //Gubenko Olesya 112
	return 3*x*x*x*x*x-x*x*x*x-5*x*x*x+6*x*x+1;
}

int function() //Gubenko Olesya 112
{
	double x;
	FILE *IN = fopen("input.txt", "wt");
	int i;
	for(i = 0; i<SIZE; i++)
	{
		x=(i*10-3);
		fprintf(IN, "%lf\t\t%lf\n", x, f(x));
	}
	fclose(IN);
	return 0;
}

//sortirovka tochek po vozrastaniyu koordinat "x" puzirkom
int sort(double array_x[], double array_y[]){ //Gubenko Olesya 112
	double buf;
	int i, j;
	for (j=0; j<SIZE; j++){
		for (i=0; i<(SIZE-1); i++){
			if (array_x[i]>array_x[i+1]){
				buf = array_x[i];
				array_x[i]=array_x[i+1];
				array_x[i+1]=buf;
				buf = array_y[i];
				array_y[i]=array_y[i+1];
				array_y[i+1]=buf;
			}
		}
	}
	return 0;
}

double lagranz(double x, double array_x[], double array_y[]) { //Gubenko Olesya 112
	int i, j;
	double y=0, p;
	for (i=0; i<SIZE; i++) {
		p=1;
		for (j=0; j<SIZE; j++) {
			if (j!=i) {
				p=(p*(x-array_x[j]))/(array_x[i]-array_x[j]);
			}
		}
		y=y+array_y[i]*p;
	}
	return y;
}



