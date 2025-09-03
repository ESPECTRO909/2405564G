#include<stdio.h>

int funcionSumatoriaParciales(int n)
{
    return n*(n+1)/2;
}

int main(void)
{
    int n=0;
    scanf("%d",&n);
    int suma=0;
    for(int i=1; i<=n; i++){
    printf("sumatoria hasta %d = %d\n",i,funcionSumatoriaParciales(i));
    suma += funcionSumatoriaParciales(i);
    }
    printf("suma total = %d\n",suma);
    return 0;







}

