// 1.Напиши програм кој внесува линија текст и користи стек за да се испечати текстот во обратен дерослед.
//  Текстот да содржи и празни места.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

void push(StackNode **top, char c) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("greska pri memoriranje nov element.\n");
        exit(1);
    }
    newNode->data = c;
    newNode->next = *top;
    *top = newNode;
}

char pop(StackNode **top) {
    if (*top == NULL) {
        printf("stekot e prazen.\n");
        return '\0';
    }
    StackNode* temp = *top;
    char poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedData;
}

void printReverse(char *text) {
    StackNode *stack = NULL;
    int length = strlen(text);

    for (int i = 0; i < length; i++) {
        push(&stack, text[i]);
    }

    printf("tekstot vo obraten redosled: ");
    while (stack != NULL) {
        printf("%c", pop(&stack));
    }
    printf("\n");
}

int main() {
    char text[1000];
    printf("vnesi tekst: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    printReverse(text);
    return 0;
}

