#include <stdio.h>
#include "menu_principale.h"
#include "sub_menu.h"
#include "funzioni.h"
#include "utils.h"

void menu_principale() {
    const char *options[] = {
        "Help",
        "Funzioni",
        "Puntatori",
        "Vettori e Matrici",
        "Prova",
        "Esci"
    };
    int selected = 0;
    int n_options = sizeof(options) / sizeof(options[0]);
    int ch;

    while (1) {
        print_menu("=== Menu Principale ===", options, n_options, selected);
        ch = getch();
        if(ch == 'q') {
            clear_screen();
            printf("Hai premuto q. Uscita...\n");
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
                clear_screen();
                benvenuti();
                getch();
            } else if (selected == 1) {
                clear_screen();
                printf("Hai selezionato: Funzioni\nPremi un tasto per continuare...\n");
                getch();
            } else if (selected == 2) {
                clear_screen();
                printf("Hai selezionato: Puntatori\nPremi un tasto per continuare...\n");
                getch();
            } else if (selected == 3) {
                menu_vettori_matrici();
            } else if (selected == 4) {
                clear_screen();
                printf("Hai selezionato: Prova questa è la versione aggiornata\nPremi un tasto qualsiasi...\n");
                getch();
            } else if (selected == 5) {
                clear_screen();
                printf("Uscita...\n");
                break;



            }
        }
    }
}
