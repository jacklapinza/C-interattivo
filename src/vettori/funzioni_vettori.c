#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#define N 5

void vettore_utente() {

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


void bubble_sort() {

    int i,j,temp,v[N];

    printf("Ti verranno chiesti 5 numeri\n");

    for(i=0;i<N;i++)
    {
        printf("[%d/%d] Numero: ",i+1,N);
        scanf("%d", &v[i]);
    }

    printf("\nVettore originale: \n");
    for(i=0;i<N;i++)
    {
        printf("%3d", v[i]);
    }


    printf("\nBubble sorting...\n");

    for(i=0;i<N-1;i++)
    {
        for(j=0;j<N-1-i;j++)
        {
            if(v[j] >= v[j+1])
            {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }


    for(i=0;i<N;i++)
    {
        printf("%3d", v[i]);
    }

    getch();

}
