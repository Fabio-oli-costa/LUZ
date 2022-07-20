#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* criação das listas */
	int L[n1], R[n2];

	/* Copia dos dados das listas*/
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/*]*/
	i = 0; // index 0 do primeiro array
	j = 0; // Iindex 0 do segundo array
	k = l; // index 0 do array com merge
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* copiando os ultimos elementos do arr L */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copiando os ultimo do array R*/
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* Merge com l para index da esquerda e r para os da direita do array a ser ordenado */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);


		merge(arr, l, m, r);
	}
}


/* Driver code */
int main()
{
	srand(time(NULL));
	int *arr, n, i;

	printf("Insira o tamanho do vetor \n");
    scanf("%d", &n);

    arr = (int *) malloc(n * sizeof(int));

    for (i = 0; i<n; i++)
        arr[i] = rand() %n;

	mergeSort(arr, 0, n - 1);

    printf("\n\n");

    for(i=0; i<n; i++)
        printf("vetor ordenado[%d]=%d\n", i, arr[i]);

	return 0;
}
