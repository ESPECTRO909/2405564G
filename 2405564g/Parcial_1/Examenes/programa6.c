#include<stdio.h>

int main()
{
	char nombre[10];

	printf("ingresa el nomnbre\n");
	for(int i=0; i<5;i++)
	{
		scanf("%c",&nombre[i]);
	}

	for(int i=5; i>0;i--)
	{
	printf("%c",nombre[i]);
	}


	return 0;
}

	

