#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp) // para efetuar as trocas
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	for (i = 0; i < n-1; i++)
	{

		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		// Chama a função de troca para substituir o valor minimo com o novo valor encontrado
		swap(&arr[min_idx], &arr[i]);
	}
}


int main()
{
    srand(time(NULL));
	int *arr, n, i;

	printf("Insira o tamanho do vetor \n");
    scanf("%d", &n);

	arr = (int *) malloc(n * sizeof(int));

	for (i = 0; i<n; i++)
        arr[i] = rand() %n;

	selectionSort(arr, n);

	    printf("\n\n");

    for(i=0; i<n; i++)
        printf("vetor[%d]=%d\n", i, arr[i]);

	return 0;
}
