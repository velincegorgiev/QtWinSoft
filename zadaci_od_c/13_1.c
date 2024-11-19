// 1.Напиши функција pecatiListaNanazad која рекурзивно ги печати елементите од листа наназад.
//  Елементите на листата се состојат од едно целоборјно поле broj и еден карактер кој се вика karakter.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int broj;      
    char karakter;  
    struct Node *next;
} Node;

void pecatiListaNanazad(Node *head) {
    if (head == NULL) {
        return;
    }

    pecatiListaNanazad(head->next);

    printf("broj: %d, karakter: %c\n", head->broj, head->karakter);
}

Node* kreirajNovElement(int broj, char karakter) {
    Node* novi = (Node*)malloc(sizeof(Node));
    if (novi == NULL) {
        printf("greska pri memoriranje na nov element.\n");
        exit(1);
    }
    novi->broj = broj;
    novi->karakter = karakter;
    novi->next = NULL;
    return novi;
}
void dodadiNaPocetak(Node **head, int broj, char karakter) {
    Node *novi = kreirajNovElement(broj, karakter);
    novi->next = *head;
    *head = novi;
}
void pecatiLista(Node *head) {
    Node *tekoven = head;
    while (tekoven != NULL) {
        printf("broj: %d, karakter: %c\n", tekoven->broj, tekoven->karakter);
        tekoven = tekoven->next;
    }
}

int main() {
    Node *head = NULL; 
    dodadiNaPocetak(&head, 10, 'A');
    dodadiNaPocetak(&head, 20, 'B');
    dodadiNaPocetak(&head, 30, 'C');
    printf("pecatenje na listata po redosled:\n");
    pecatiLista(head);
    printf("\npecatene na listata nanazad:\n");
    pecatiListaNanazad(head);

    return 0;
}
