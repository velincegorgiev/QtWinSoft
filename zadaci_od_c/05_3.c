// 3.Да се напише програма која ќе пресметува Питагорини броеви до 100. Тоа се броеви кои го исполнуваат следниот услов a2+b2=c2.


#include <stdio.h>

int main()
{
    for(int a=1;a<=100;a++)
    {
        for(int b=1;b<=100;b++)
        {
            for(int c=1;c<=100;c++)
            {
                if((a*a)+(b*b)==(c*c))
                {
                    printf("Pitagorinski broevi: a = %d, b = %d, c = %d\n", a, b, c);
                }
            }
        }
    }

    return 0;
}
