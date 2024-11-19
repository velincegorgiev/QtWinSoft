// 2. Напиши програм кој чита датум во обликот 14/06/2005 и враќа датум во обликот 
// 14 juni 2005. Корисникот да има можност да внесува колку што сака датуми 
// кои треба да бидат конвертирани во другиот излез.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* get_month_name(int month) {
    switch(month) {
        case 1: return "januari";
        case 2: return "februari";
        case 3: return "mart";
        case 4: return "april";
        case 5: return "maj";
        case 6: return "juni";
        case 7: return "juli";
        case 8: return "avgust";
        case 9: return "september";
        case 10: return "oktober";
        case 11: return "noemvri";
        case 12: return "dekemvri";
        default: return NULL;  
    }
}

int main() {
    char date[11];
    int day, month, year;

    while (1) {
        printf("vnesi datum vo forma dd/mm/yyyy (ili 'kraj' za zavrsuvanje): ");
        fgets(date, sizeof(date), stdin);
        
        if (strncmp(date, "kraj", 4) == 0) {
            break;
        }

        if (sscanf(date, "%d/%d/%d", &day, &month, &year) != 3) {
            printf("nevaliden format na datum obidete se povtorno\n");
            continue;
        }

        if (month < 1 || month > 12) {
            printf("nevaliden mesec obidete se povtorno\n");
            continue;
        }

        const char *month_name = get_month_name(month);
        if (month_name != NULL) {
            printf("%d %s %d\n", day, month_name, year);
        } else {
            printf("greska pri dobivanje na mesecot\n");
        }
    }
    
    printf("programata e zavrsena\n");
    return 0;
}
