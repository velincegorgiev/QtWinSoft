// 2.Напиши програма која внесува елементи со функцијата vnesi несортирано, на крајот на листата,
//  ја користи функцијата sortOpagjanje која сортира елементи во опаѓачки редослед, функцијата 
//  sortRastenje која ги сортира елемнтите во растечки редослед, brisi која брише елемент со дадена содржина.
//   Елементите на листата се целобројни елементи.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;
void vnesi(Node **head, int value) {
    Node *novi = (Node*)malloc(sizeof(Node));
    if (novi == NULL) {
        printf("greska pri memoriranje na noviot element.\n");
        exit(1); 
    }
    novi->data = value;
    novi->next = NULL;

    if (*head == NULL) {
        *head = novi;
    } else {
        Node *tekoven = *head;
        while (tekoven->next != NULL) {
            tekoven = tekoven->next;
        }
        tekoven->next = novi;
    }
}

void sortOpagjanje(Node **head) {
    if (*head == NULL) return;
    Node *i, *j;
    int temp;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data < j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void sortRastenje(Node **head) {
    if (*head == NULL) return;
    Node *i, *j;
    int temp;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void brisi(Node **head, int value) {
    Node *tekoven = *head, *prethoden = NULL;
    if (tekoven != NULL && tekoven->data == value) {
        *head = tekoven->next;
        free(tekoven);
        return;
    }
    while (tekoven != NULL && tekoven->data != value) {
        prethoden = tekoven;
        tekoven = tekoven->next;
    }
    if (tekoven == NULL) {
        printf("elementot %d ne e pronajden vo listata.\n", value);
        return;
    }

    prethoden->next = tekoven->next;
    free(tekoven);
}

void pecatiLista(Node *head) {
    Node *tekoven = head;
    if (tekoven == NULL) {
        printf("listata e prazna.\n");
        return;
    }

    while (tekoven != NULL) {
        printf("%d -> ", tekoven->data);
        tekoven = tekoven->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    int izbor, vrednost;

    while (1) {
        printf("\n1. vnesi elementi\n");
        printf("2. sortiraj ja listata vo rastecki redosled\n");
        printf("3. sortiraj ja listata vo opagacki redosled\n");
        printf("4. brisi element\n");
        printf("5. pecati ja listata\n");
        printf("6. izlez\n");
        printf("izberi opcija: ");
        scanf("%d", &izbor);

        switch (izbor) {
            case 1:
                printf("vnesete element: ");
                scanf("%d", &vrednost);
                vnesi(&head, vrednost);
                break;

            case 2:
                sortRastenje(&head);
                printf("lsitata e sortirana vo rastecki redosled.\n");
                break;

            case 3:
                sortOpagjanje(&head);
                printf("listata e sortirana vo opagacki redosled.\n");
                break;

            case 4:
                printf("vnesete vrednost za element za brisenje: ");
                scanf("%d", &vrednost);
                brisi(&head, vrednost);
                break;

            case 5:
                pecatiLista(head);
                break;

            case 6:
                printf("izleguvate od programata.\n");
                return 0;

            default:
                printf("nevaliden izbor obidete se povtorno.\n");
        }
    }

    return 0;
}

