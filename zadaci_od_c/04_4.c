// 4.Напиши програма која ја пресметува сумата на броевите од 1 до десет.

#include<stdio.h>

int main()
{
    int suma=0;
    for(int i=1;i<=10;i++)
    {
        suma+=i;
    }
    printf("sumata na broevite od 1 do 10 e %d",suma);
}
