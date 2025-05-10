#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <string.h>
#include <unistd.h>
#define MAX 300
#define FILENAME "benvenuti.txt"

void benvenuti() {
    FILE *fpIn;
    int i, lung, term_width;
    char benvenuti[MAX];

    if ((fpIn = fopen(FILENAME, "r")) == NULL) {
        fprintf(stderr, "Errore nell'apertura di %s\n", FILENAME);
        exit(1);
    }

    get_terminal_width(&term_width);

    while (fgets(benvenuti, MAX, fpIn) != NULL) {
        lung = strlen(benvenuti);

        if (benvenuti[lung - 1] == '\n') {
            benvenuti[--lung] = '\0';
        }

        int padding = (term_width - lung) / 2;
        if (padding < 0) padding = 0;

        for (i = 0; i < padding; i++) {
            printf(" ");
        }

        for (i = 0; i < lung; i++) {
            delay_text(benvenuti[i], 0.02);
        }

        printf("\n");
    }

    fclose(fpIn);
}
