// 1. Вие сте сопственик на продавница за компјутерска опрема. 
// Треба да си направите апликација која ќе се грижи за хардверот што го имате на располагање,
//  количината на секој од деловите во продавницата и цените на деловите. 
//  Напишете програма која иницијализира датотека “hardware.dat”, ви овозможува да 
//  внесете податоци за секој дел, да ги излистате податоците за специфичен дел, 
//  да дадете комплетен листинг на состојбата во вашата продавница, да избришете 
//  податоци за даден дел ако тој веќе го немате на лагер, да ажурирате податоци за 
//  даден дел и да правите продажба. Под продажба се подразбира намалување на бројот на 
//  потребни делови од датотеката, доколку има толку делови, колку што бара купецот. 
//  Да претпоставиме дека имаме оптички читач на касата и дека секој дел се вчитува со негов код. 

// За започнување со работа, користете ги следните информации:
// Код 	Име на дел	 Количина	Цена
// 3	glusec Mico	     7	    10.34
// 56	monitor Kiki3	 5	    65.09
// 75	tastatura Biko8	 4	    12.09
// 89	matploc Ziko32	 6	    87.09


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define FILENAME "hardware.dat"

typedef struct {
    int code;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} HardwarePart;

void initializeFile() {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("ne moze da se otvori datotekata!\n");
        return;
    }

    HardwarePart parts[] = {
        {3, "glusec Mico", 7, 10.34},
        {56, "monitor Kiki3", 5, 65.09},
        {75, "tastatura Biko8", 4, 12.09},
        {89, "matploc Ziko32", 6, 87.09}
    };

    fwrite(parts, sizeof(HardwarePart), 4, file);
    fclose(file);
    printf("datotekata e inicijalizirana.\n");
}

void listAllParts() {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("ne moze da se otvori datotekata!\n");
        return;
    }

    HardwarePart part;
    printf("site delovi vo prodavnicata:\n");
    while (fread(&part, sizeof(HardwarePart), 1, file)) {
        printf("kod: %d, ime: %s, kolicina: %d, cena: %.2f\n", part.code, part.name, part.quantity, part.price);
    }

    fclose(file);
}

void listPartByCode(int code) {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("ne moze da se otvori datotekata!\n");
        return;
    }

    HardwarePart part;
    int found = 0;
    while (fread(&part, sizeof(HardwarePart), 1, file)) {
        if (part.code == code) {
            printf("delot so kod %d e pronajden:\n", code);
            printf("ime: %s, kolicina: %d, cena: %.2f\n", part.name, part.quantity, part.price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("delot so kod %d ne postoi vo prodavnicata.\n", code);
    }

    fclose(file);
}

void updatePart(int code, int newQuantity, float newPrice) {
    FILE *file = fopen(FILENAME, "rb+");
    if (file == NULL) {
        printf("ne moze da se otvori datotekata!\n");
        return;
    }

    HardwarePart part;
    int found = 0;
    while (fread(&part, sizeof(HardwarePart), 1, file)) {
        if (part.code == code) {
            part.quantity = newQuantity;
            part.price = newPrice;
            fseek(file, -sizeof(HardwarePart), SEEK_CUR); // Врати се назад за да ги ажурираш податоците
            fwrite(&part, sizeof(HardwarePart), 1, file);
            found = 1;
            printf("podatocite za delot so kod %d se anzurirani.\n", code);
            break;
        }
    }

    if (!found) {
        printf("delot so kod %d ne postoi.\n", code);
    }

    fclose(file);
}

void deletePart(int code) {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("ne moze da se otvori datotekata!\n");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("ne moze da se otvori datotekata!\n");
        fclose(file);
        return;
    }

    HardwarePart part;
    int found = 0;
    while (fread(&part, sizeof(HardwarePart), 1, file)) {
        if (part.code != code) {
            fwrite(&part, sizeof(HardwarePart), 1, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILENAME);
        rename("temp.dat", FILENAME);
        printf("delot so kod %d e izbrisan.\n", code);
    } else {
        remove("temp.dat");
        printf("delot so kod %d ne postoi.\n", code);
    }
}

void sellPart(int code, int quantitySold) {
    FILE *file = fopen(FILENAME, "rb+");
    if (file == NULL) {
        printf("ne moze da se otvori datotekata!\n");
        return;
    }

    HardwarePart part;
    int found = 0;
    while (fread(&part, sizeof(HardwarePart), 1, file)) {
        if (part.code == code) {
            if (part.quantity >= quantitySold) {
                part.quantity -= quantitySold;
                fseek(file, -sizeof(HardwarePart), SEEK_CUR);
                fwrite(&part, sizeof(HardwarePart), 1, file);
                found = 1;
                printf("prodazba uspesna! prodadeni %d delovi.\n", quantitySold);
                break;
            } else {
                printf("nedovolna kolicina na delovi za prodazba.\n");
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("delot so kod %d ne postoi.\n", code);
    }

    fclose(file);
}

int main() {
    int choice, code, quantity, quantitySold;
    float price;

    initializeFile();

    do {
        printf("\nizberete opcija:\n");
        printf("1. izlistuvanje na site delovi\n");
        printf("2. izlistuvanje na del po kod\n");
        printf("3. anzuriranje na del\n");
        printf("4. brisenje na del\n");
        printf("5. prodazba na del\n");
        printf("6. izlez\n");
        printf("vas izbor: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                listAllParts();
                break;
            case 2:
                printf("vnesete kod na del: ");
                scanf("%d", &code);
                listPartByCode(code);
                break;
            case 3:
                printf("vnesete kod na del: ");
                scanf("%d", &code);
                printf("vnesete nova kolicina: ");
                scanf("%d", &quantity);
                printf("vnesete nova cena: ");
                scanf("%f", &price);
                updatePart(code, quantity, price);
                break;
            case 4:
                printf("vnesete kod na del: ");
                scanf("%d", &code);
                deletePart(code);
                break;
            case 5:
                printf("vnesete kod na del: ");
                scanf("%d", &code);
                printf("vnesete kolicina za prodazba: ");
                scanf("%d", &quantitySold);
                sellPart(code, quantitySold);
                break;
            case 6:
                printf("izleguvate od programata.\n");
                break;
            default:
                printf("nevaliden izbor.\n");
        }
    } while (choice != 6);

    return 0;
}

