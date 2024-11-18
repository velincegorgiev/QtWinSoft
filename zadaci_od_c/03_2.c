// 2. Напиши програм кој вчитува два цели броја и одредува дали се парни или непарни.

#include <stdio.h>

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(a%2==0)
    {
        printf("brojot %d e paren\n",a);
    }
    else{
        printf("brojot %d e neparen\n",a);
    }
    if(b%2==0)
    {
        printf("brojot %d e paren\n",b);
    }
    else{
        printf("brojot %d e neparen\n",b);
    }
}