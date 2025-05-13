#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void prova() {

    const int N = 5;
    int i,v[N];

    printf("Ti verranno chiesti 5 numeri\n");
    for(i=0;i<N;i++)

    {
        printf("[%d/%d] Numero: ",i+1,N);
        scanf("%d", &v[i]);
    }

    printf("\n");

    for(i=0;i<N;i++)
    {
        printf("%3d",v[i]);
    }
    getch();
}
