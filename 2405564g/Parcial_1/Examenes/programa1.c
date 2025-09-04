#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define  pi 3.1416
int main()
{
	float radio;
	float area;

	printf("ingrese raadio\n");
	scanf("%f",&radio);

	area = pi * (radio*radio); 

	printf("el area es:%f\n",area);



}


