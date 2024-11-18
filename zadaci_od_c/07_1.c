// 1.Напиши програма која внесува 10 цели броеви и и ги доделува на функцијата 
// paren која враќа 1 ако бројот е парен и 0 ако бројот не е парен.

#include<stdio.h>

int paren(int broj)
{
    if(broj%2==0)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    int broj;
    for(int i=0;i<10;i++)
    {
        scanf("%d",&broj);
        if(paren(broj))
        {
            printf("brojot %d e paren\n",broj);
        }
        else{
            printf("brojot %d e neparen\n",broj);
        }
    }
}
