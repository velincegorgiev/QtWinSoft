// 7.Напиши програма која пресметува сума на внесени броеви од тастатура се додека не се внесе карактер ‘n’.
// Пример:
//           Vnesi broj: 6
//           Ushte? (d/n): d
//           Vnesi broj: 7
//           Ushte? (d/n): d
//           Vnesi broj: 3
//           Ushte? (d/n): n
//                   Sumata e 16


#include <stdio.h>

int main() {
    int broj, suma = 0;
    char cr;

    while (1) {
        printf("Vnesi broj: \n");
        if (scanf("%d", &broj) == 1) {
            suma += broj;
            getchar(); 
            printf("Ushte? (d/n): \n");
            cr = getchar();
            if (cr == 'n' || cr == 'N') {
                break;
            }
        } else {
            printf("Nevaliden broj.\n");
            break;
        }
    }

    printf("Sumata e %d\n", suma);
    return 0;
}
