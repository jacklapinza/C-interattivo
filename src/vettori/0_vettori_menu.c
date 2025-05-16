#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "funzioni.h"

void menu_vettori() {
    const char *options[] = {
        "1 - Nozioni principali",
        "2 - Vettore da tastiera",
        "3 - Bubble sorting",
        "Torna indietro"
    };
    int selected = 0;
    int n_options = sizeof(options) / sizeof(options[0]);
    int ch;

    while (1) {
        print_menu("Vettori", options, n_options, selected);
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
                clear_screen();
                intro_vettori();
                getch();
            } else if (selected == 1) {
                clear_screen();
                vettore_utente();
                getch();
            } else if (selected == 2) {

                clear_screen();
                bubble_sort();
                getch();
            }
        }
    }
}
