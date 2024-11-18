// 6.Напиши програма која пресметува сума на внесени броеви од тастатура се додека не се внесе -1.

#include <stdio.h>

int main()
{
    int broj, sum = 0;
    while (1) {
        scanf("%d", &broj); 
        if (broj == -1) { 
            break;
        }
        sum += broj;
    }
    printf("Sumata na broevite e: %d\n", sum);

    return 0;
}
