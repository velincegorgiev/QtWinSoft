// 6. Напишете програма која од стандардниот влез зема 5 букви и ги испечатува 
// по следниот редослед: прво петтата, па третата, па втората, па првата, па четвртата буква. Пример:
// vnesi pet bukvi
// prva bukva: e
// vtora bukva: i
// treta bukva: b
// chetvrta  bukva: n
// petta bukva: p
// Se dobi: pbien

#include<stdio.h>

int main()
{
    char a,b,c,d,i;
    printf("vnesi pet bukvi\n");
    scanf("%c\n%c\n%c\n%c\n%c",&a,&b,&c,&d,&i);
    printf("Se dobi: %c%c%c%c%c",i,c,b,a,d);
}
