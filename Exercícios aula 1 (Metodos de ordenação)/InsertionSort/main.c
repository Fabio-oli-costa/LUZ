#include <math.h>
#include <stdio.h>


void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) { // i = 1 porque o algoritmo começa a comparação a partir do segundo número procurando um igual ou menor.
		key = arr[i];
		j = i - 1;

		// esse laço move os elementos comparando a key com os elementos a esquerda, até que encontre sua posição.
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
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

    for (i = 0; i<n; i++)
        printf("vetor[%d]=%d\n", i, arr[i]);


	insertionSort(arr, n);

    printf("\n\n");

    for(i=0; i<n; i++)
        printf("vetor[%d]=%d\n", i, arr[i]);


	return 0;
}
