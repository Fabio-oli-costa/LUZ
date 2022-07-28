#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de Ordenação por Seleção
// Quick sort function
void quick_sort(int *a, int left, int right) {
    int i, j, x, y;

    i = left; // incio
    j = right;
    x = a[(left + right) / 2]; // meio

    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

// Função main
int main()
{
    srand(time(NULL));
	int *arr, n, i;

	printf("Insira o tamanho do vetor \n");
    scanf("%d", &n);

    arr = (int *) malloc(n * sizeof(int));

    for (i = 0; i<n; i++)
        arr[i] = rand() %n;

    system("pause");

    quick_sort(arr, 0, n - 1);

    printf("\n\n");

    for(i=0; i<n; i++)
        printf("vetor[%d]=%d\n", i, arr[i]);

 system("pause");
 return 0;
}
