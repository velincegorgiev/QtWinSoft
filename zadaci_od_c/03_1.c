// 1. Напиши програм кој како влез зема два цели броја и ги споредува. 
// Потоа го испечатува поголемиот број проследен со коментарот e pogolem 
// od и го испечатува и помалиот број. Ако броевите се еднакви, програмот 
// треба да испечати Broevite se ednakvi.

#include <stdio.h>
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(a>b)
    {
        printf("%d e pogolem od %d",a,b);
    }
    else if(a<b)
    {
        printf("%d e pogolem od %d",b,a);
    }
    else{
        printf("Broevite se ednakvi");
    }
}