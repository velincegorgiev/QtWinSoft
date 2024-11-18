// 3.Палиндроми се низи од букви што се читаат исто и оддесно на лево и одлево на десно.
//  На пример зборот “radar” е палиндром. Да се напише програм во кој внесуваме низа од карактери. 
//  Треба да имаме функција palindrom која враќа вредност 1 ако стрингот е палиндром или 0 инаку.

#include <stdio.h>
#include <string.h>

int palindrom(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end) {
        if (str[start] != str[end]) {
            return 0; 
        }
        start++;
        end--;
    }
    return 1; 
}

int main() {
    char str[100];
    printf("Vnesi niza od karakteri: ");
    scanf("%s", str);
    if (palindrom(str)) {
        printf("Stringot e palindrom.\n");
    } else {
        printf("Stringot ne e palindrom.\n");
    }

    return 0;
}

