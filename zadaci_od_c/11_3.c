// 3. Да се пронајдат на Интернет кодовите за бројки и букви во Морзеовата азбука.
//  Да се напише програм кој чита текст фраза и ја дава нејзината вредност во 
//  Морзеовата азбука. Да се направи и друга функција на која и се предава 
//  Морзеов текст, а треба како резултат да се добие текст фраза во говорен јазик.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


const char* morse[] = {
    ".-",   "-...", "-.-.", "-..", ".",   "..-.", "--.",   "....", "..",    ".---", 
    "-.-",  ".-..", "--",   "-.",    "---",  ".--.", "--.-", ".-.",  "...",  "-", 
    "..-",   "...-", ".--",  "-..-", "-.--", "--..", 
    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", 
    " ",
    "/"
};


void text_to_morse(char* text) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        

        if (ch >= 'a' && ch <= 'z') {
            printf("%s ", morse[ch - 'a']);
        }

        else if (ch >= 'A' && ch <= 'Z') {
            printf("%s ", morse[ch - 'A']);
        }

        else if (ch >= '0' && ch <= '9') {
            printf("%s ", morse[ch - '0' + 26]); 
        }

        else if (ch == ' ') {
            printf("/ ");
        }

        else {
            continue; 
        }
    }
    printf("\n");
}

void morse_to_text(char* morse_code) {
    char* token = strtok(morse_code, " ");
    
    while (token != NULL) {
        if (strcmp(token, ".-") == 0) printf("A");
        else if (strcmp(token, "-...") == 0) printf("B");
        else if (strcmp(token, "-.-.") == 0) printf("C");
        else if (strcmp(token, "-..") == 0) printf("D");
        else if (strcmp(token, ".") == 0) printf("E");
        else if (strcmp(token, "..-.") == 0) printf("F");
        else if (strcmp(token, "--.") == 0) printf("G");
        else if (strcmp(token, "....") == 0) printf("H");
        else if (strcmp(token, "..") == 0) printf("I");
        else if (strcmp(token, ".---") == 0) printf("J");
        else if (strcmp(token, "-.-") == 0) printf("K");
        else if (strcmp(token, ".-..") == 0) printf("L");
        else if (strcmp(token, "--") == 0) printf("M");
        else if (strcmp(token, "-.") == 0) printf("N");
        else if (strcmp(token, "---") == 0) printf("O");
        else if (strcmp(token, ".--.") == 0) printf("P");
        else if (strcmp(token, "--.-") == 0) printf("Q");
        else if (strcmp(token, ".-.") == 0) printf("R");
        else if (strcmp(token, "...") == 0) printf("S");
        else if (strcmp(token, "-") == 0) printf("T");
        else if (strcmp(token, "..-") == 0) printf("U");
        else if (strcmp(token, "...-") == 0) printf("V");
        else if (strcmp(token, ".--") == 0) printf("W");
        else if (strcmp(token, "-..-") == 0) printf("X");
        else if (strcmp(token, "-.--") == 0) printf("Y");
        else if (strcmp(token, "--..") == 0) printf("Z");
        else if (strcmp(token, ".----") == 0) printf("1");
        else if (strcmp(token, "..---") == 0) printf("2");
        else if (strcmp(token, "...--") == 0) printf("3");
        else if (strcmp(token, "....-") == 0) printf("4");
        else if (strcmp(token, ".....") == 0) printf("5");
        else if (strcmp(token, "-....") == 0) printf("6");
        else if (strcmp(token, "--...") == 0) printf("7");
        else if (strcmp(token, "---..") == 0) printf("8");
        else if (strcmp(token, "----.") == 0) printf("9");
        else if (strcmp(token, "-----") == 0) printf("0");
        else if (strcmp(token, "/") == 0) printf(" "); 
        
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
    int choice;
    char input[200];

    while (1) {
        printf("izberete opcija:\n");
        printf("1. tekst vo mozeov kod\n");
        printf("2. mozeov kod vo tekst\n");
        printf("3. izlez\n");
        printf("vasata opcija: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("vnesete tekst za konventiranje vo mozeov kod: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;
            text_to_morse(input);
        } else if (choice == 2) {
            printf("vnesete mozeov kod za konventiranje vo tekst: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;
            morse_to_text(input);
        } else if (choice == 3) {
            printf("programata e zavrsena.\n");
            break;
        } else {
            printf("nevalidna opcija obidete se povtorno\n");
        }
    }

    return 0;
}

