// 1. Напиши програм кој внесува телефонски број како стринг во облик (333) 333-3333.
//  Програмот треба со користење на наредбата strtok да го извлече кодот на државата 
//  како едно делче, а потоа да го спои целиот телефонски број во друг стринг без -.
//   Програмот треба да го конвертира бројот на државата во int, а седмоцифрениот телефонски 
//   број во long. Двата бројат треба да бидат испечатени.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char phone_number[20];
    char country_code[5];
    char phone_no[10];
    int country_code_int;
    long phone_no_long;

    printf("vnesi telefonski broj (vo format (333) 333-3333): ");
    fgets(phone_number, sizeof(phone_number), stdin);

    char *token = strtok(phone_number, " ()-");

    strncpy(country_code, token, 3);
    country_code[3] = '\0';
    country_code_int = atoi(country_code);

    token = strtok(NULL, " ()-");

    phone_no[0] = '\0'; 
    while (token != NULL) {
        strcat(phone_no, token); 
        token = strtok(NULL, " ()-");  
    }

    phone_no_long = atol(phone_no);

    printf("kod na drzava: %d\n", country_code_int);
    printf("telefonski broj: %ld\n", phone_no_long);

    return 0;
}

