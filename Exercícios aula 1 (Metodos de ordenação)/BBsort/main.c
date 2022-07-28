#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int p[], int n)
    {
        int i,j, aux;

        for(i=0; i<n; i++)
        {
            for(j=0; j<n-1-i; j++)
            {
                if(p[j]>p[j+1])
                {
                    aux = p[j];
                    p[j]= p[j+1];
                    p[j+1]= aux;
                }
            }
        }
    }

int main(void)
    {
        int i, n, *p;
        srand(time(NULL));


        printf("Insira o tamanho do vetor \n");
        scanf("%d", &n);
        p = (int *) malloc(n * sizeof(int));

        for (i = 0; i<n; i++)
            p[i] = rand() %n;

        for (i = 0; i<n; i++)
            printf("vetor[%d]=%d\n", i, p[i]);

            bubbleSort(p, n);

            printf("\n\n");

            for(i=0; i<n; i++)
                printf("vetor[%d]=%d\n", i, p[i]);

            return 0;

    }
