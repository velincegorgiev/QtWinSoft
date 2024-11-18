// 2.Напиши програма која на функцијата vreme и доделува три целобројни аргументи,
//  час, минута и секунда и како резултат го враќа бројот на секунди до 12 часот. 
//  Имено, ако е 11 часот 59 минути и 58 секунди, тогаш има уште 2 секунди до 12 часот.

#include<stdio.h>

int vreme(int minuti, int sekundi)
{
    int dodatni=0;
    int min=0;
    while(sekundi<60)
    {
        dodatni++;
        sekundi++;
    }
    minuti+=1;
    while(minuti<60)
    {
        min++;
        minuti++;
    }
    dodatni=dodatni+(min*60);
    return dodatni;
}

int main()
{
    int casovi,minuti,sekundi;
    scanf("%d%d%d",&casovi,&minuti,&sekundi);
    printf("%d sekundi do %d casot",vreme(minuti,sekundi),casovi+1);
}
