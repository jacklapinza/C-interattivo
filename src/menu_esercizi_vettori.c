#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "funzioni.h"

void menu_vettori() {
    const char *options[] = {
        "Chiedi vettore ad utente",
        "Torna indietro"
    };
    int selected = 0;
    int n_options = sizeof(options) / sizeof(options[0]);
    int ch;

    while (1) {
        print_menu("Esercizi: Vettori e Matrici", options, n_options, selected);
        ch = getch();
        if(ch == 'q') {
            clear_screen();
            printf("Hai premuto q... uscita in corso\n");
            exit(0);
        }
        if(ch == 127) {
            clear_screen();
            break;
        }
        if (ch == 27) {
            ch = getch();
            if (ch == 91) {
                ch = getch();
                if (ch == UP_ARROW && selected > 0) selected--;
                else if (ch == DOWN_ARROW && selected < n_options - 1) selected++;
            }
        } else if (ch == '\n') {
            if (selected == 0) {
                mostra_esempio_vettore();
            } else if (selected == 1) {
                break;
            }
        }
    }
}

void mostra_esempio_vettore() {

    char buffer[100];
    int j;

    clear_screen();
    printf("Esempio: chiedere un vettore di 5 interi all'utente\n\n");

    printf(
        "#include <stdio.h>\n\n"
        "int main() {\n"
        "    int v[5];\n"
        "    int i;\n\n"
        "    printf(\"Inserisci 5 numeri interi:\\n\");\n"
        "    for (i = 0; i < 5; i++) {\n"
        "        scanf(\"%%d\", &v[i]);\n"
        "    }\n\n"
        "    printf(\"Hai inserito:\\n\");\n"
        "    for (i = 0; i < 5; i++) {\n"
        "        printf(\"%%d \", v[i]);\n"
        "    }\n"
        "    printf(\"\\n\");\n\n"
        "    return 0;\n"
        "}\n"
    );

    printf("Inserisci un numero: ");
    fgets(buffer, sizeof(buffer), stdin);

    if (sscanf(buffer, "%d", &j) == 1) {
        printf("Hai inserito: %d\n", j);
    } else {
        printf("Input non valido o vuoto.\n");
    }

    printf("\nPremi un tasto per tornare indietro...");
    getch();
}
