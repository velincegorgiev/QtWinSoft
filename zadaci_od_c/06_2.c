// 2.Напиши програма која вчитува датуми во облик gg/mm/dd, gg-mm-dd и gg+mm+dd 
// и ги испечаува така да наместо бројот на месецот се испечати имато на месецот.
// Пример:
// Vnesi datum: 2005+06+01
// Vneseniot datum e 1 juni 2005 godina.

#include<stdio.h>

int main()
{
    int godina,mesec,den;
    char prv,vtor;
    printf("Vnesi datum: ");
    scanf("%d%c%d%c%d",&godina,&prv,&mesec,&vtor,&den);
    printf("\n");
    switch (mesec)
    {
    case 1:
        printf("Vneseniot datum e %d January %d godina.",den,godina);
        break;
    case 2:
        printf("Vneseniot datum e %d February %d godina.",den,godina);
        break;
    case 3:
        printf("Vneseniot datum e %d March %d godina.",den,godina);
        break;
    case 4:
        printf("Vneseniot datum e %d April %d godina.",den,godina);
        break;
    case 5:
        printf("Vneseniot datum e %d May %d godina.",den,godina);
        break;
    case 6:
        printf("Vneseniot datum e %d June %d godina.",den,godina);
        break;
    case 7:
        printf("Vneseniot datum e %d July %d godina.",den,godina);
        break;
    case 8:
        printf("Vneseniot datum e %d August %d godina.",den,godina);
        break;
    case 9:
        printf("Vneseniot datum e %d September %d godina.",den,godina);
        break;
    case 10:
        printf("Vneseniot datum e %d October %d godina.",den,godina);
        break;
    case 11:
        printf("Vneseniot datum e %d November %d godina.",den,godina);
        break;
    case 12:
        printf("Vneseniot datum e %d December %d godina.",den,godina);
        break;
    default:
        printf("Pogresno vnesen datum");
        break;
    }
}
