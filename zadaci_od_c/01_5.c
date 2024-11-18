// Напиши програм кој  го дава следниот излез: 
// a) pravoagolnik, b)krug, v)strelka nogore, d)baklava

#include <stdio.h>

int main() {
    // pravoagolnik
    printf("*****\n");
    for (int i = 0; i < 5; i++) {
        printf("*   *\n");
    }
    printf("*****\n");

    //krug
    printf("\n  ***  \n");
    printf(" *   * \n");
    printf("*     *\n");
    printf("*     *\n");
    printf("*     *\n");
    printf(" *   * \n");
    printf("  ***  \n");

    //strelka nogore
    printf("\n   *   \n");
    printf("  ***  \n");
    printf("*******\n");
    printf("   *   \n");
    printf("   *   \n");
    printf("   *   \n");
    printf("   *   \n");

    //baklava
    printf("\n   *   \n");
    printf("  * *  \n");
    printf(" *   * \n");
    printf("*     *\n");
    printf(" *   * \n");
    printf("  * *  \n");
    printf("   *   \n");
    

    return 0;
}
