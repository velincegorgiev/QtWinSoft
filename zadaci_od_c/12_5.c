// 2. Да се напише програма која служи како генератор на телефонски броеви. Знаеме дека полесно 
// се паметат поими од броеви, па така некои од компаниите имаат телефонски броеви кои ја 
// означуваат дејноста или името на компанијата.
// Нека ни се подредени буквите на следниот начин:
// Цифра	Буква
// 2	    ABC
// 3	    DEF
// 4	    GHI
// 5	    JKL
// 6	    MNO
// 7	    PQR
// 8	    STU
// 9	    VWX
// 0	    YZ
// а) За даден седумбуквен стринг да се изгенерира бројот на телефон. Пример: “TELEKOM” = 8353566
// б) За даден седмоцифрен број да се изгенерираат што поголем број на стрингови. Да се внимава дека 0 има само две букви.


#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

char letter_to_digit(char c) {
    if (c >= 'A' && c <= 'C') return '2';
    if (c >= 'D' && c <= 'F') return '3';
    if (c >= 'G' && c <= 'I') return '4';
    if (c >= 'J' && c <= 'L') return '5';
    if (c >= 'M' && c <= 'O') return '6';
    if (c >= 'P' && c <= 'R') return '7';
    if (c >= 'S' && c <= 'U') return '8';
    if (c >= 'V' && c <= 'X') return '9';
    if (c == 'Y' || c == 'Z') return '0';
    return '\0'; 
}

void generatePhoneNumber(char *str, char *phoneNumber) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        phoneNumber[i] = letter_to_digit(str[i]);
    }
    phoneNumber[i] = '\0';
}

void generateCombinations(char *digits, int index, char *current, FILE *output) {
    if (digits[index] == '\0') {
        current[index] = '\0';
        fprintf(output, "%s\n", current); 
        return;
    }

    int digit = digits[index] - '0';
    
    char letters[10][4] = {
        {'0', '\0', '\0', '\0'},
        {'A', 'B', 'C', '\0'},
        {'D', 'E', 'F', '\0'},
        {'G', 'H', 'I', '\0'},
        {'J', 'K', 'L', '\0'},
        {'M', 'N', 'O', '\0'},
        {'P', 'Q', 'R', 'S'},
        {'T', 'U', 'V', '\0'},
        {'W', 'X', 'Y', '\0'},
        {'Y', 'Z', '\0', '\0'}
    };

    for (int i = 0; letters[digit][i] != '\0'; i++) {
        current[index] = letters[digit][i];
        generateCombinations(digits, index + 1, current, output);
    }
}

int main() {
    char str[MAX_LENGTH];
    char phoneNumber[MAX_LENGTH];
    FILE *output;

    printf("vnesete bukven string: ");
    scanf("%s", str);
    generatePhoneNumber(str, phoneNumber);
    printf("telefonski broj: %s\n", phoneNumber);

    output = fopen("phone_number.txt", "w");
    if (!output) {
        printf("greska pri otvaranje na datotekata.\n");
        return 1;
    }
    fprintf(output, "telefosnki broj: %s\n", phoneNumber);
    fclose(output);
    printf("vnesete broj: ");
    scanf("%s", str);
    char current[MAX_LENGTH];
    output = fopen("combinations.txt", "w");
    if (!output) {
        printf("greska pri otvaranje na datotekata.\n");
        return 1;
    }
    generateCombinations(str, 0, current, output);
    fclose(output);

    printf("kombinaciite se zapisuvaat vo datotekata 'combinations.txt'.\n");

    return 0;
}
