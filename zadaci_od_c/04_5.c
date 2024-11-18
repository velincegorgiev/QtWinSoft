// 5.Напиши програма која за внесени десет броја, го пресметува нивниот производ.

#include<stdio.h>

int main()
{
    int broevi,rezultat=1,brojac=10;
    for(int i=0;i<brojac;i++)
    {
        scanf("%d",&broevi);
        rezultat*=broevi;
    }
    printf("rezultatot od mnozenje na vnesenite deset broja e: %d",rezultat);
}
