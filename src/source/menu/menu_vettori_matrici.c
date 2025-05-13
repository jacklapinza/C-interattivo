#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "menu_principale.h"
#include "funzioni.h"

void menu_vettori_matrici() {
    const char *options[] = {
        "Concetti base",
        "Vettori",
        "Matrici",
        "Torna al menu principale"
    };
    int selected = 0;
    int n_options = sizeof(options) / sizeof(options[0]);
    int ch;

    while (1) {
        print_menu("Sezione: Vettori e Matrici", options, n_options, selected);
        ch = getch();
        if(ch == 'q') {
            clear_screen();
            printf("Hai premuto q. Uscita...\n");
            exit(0);
        }
        if (ch == 127) {
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
                clear_screen();
                printf("Qui probablimente mi conviene linkare direttamente il manuale\n");
                getch();
            } else if (selected == 1) {
                menu_vettori();
            } else if (selected == 2) {
                clear_screen();
                printf("Hai selezionato matrici\n");
                getch();
            } else if (selected == 3) {
                break;
            }
        }
    }
}
