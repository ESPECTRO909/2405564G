#include<stdio.h>

int main()
{
	int numero1,numero2,numero3,promedio;
	printf("ingresa el primer numero\n");
	scanf("%d",&numero1);
	printf("ingresa el seegundo numero\n");
	scanf("%d",&numero2);
	printf("ingresa el tercero numero\n");
	scanf("%d",&numero3);

	promedio = (numero1+numero2+numero3)/3;

	printf("el<resultado del promedio es:%d\n",promedio);

	return 0;



}
