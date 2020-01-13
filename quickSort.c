#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printVetor(int *v, int N){
    int i;

    for(i=0;i<N;i++){
        printf("%d ", v[i]);
    }

    printf("\n");

}

void troca (int *vetor, int i, int j) {
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

int partition(int *v, int inicio, int fim){
    int pivot = v[fim];
    int j, i = inicio-1;

    for(j = inicio;j< fim;j++){
        if(v[j] < pivot){
            i++;
            troca(v,i,j);
        }
    }
    troca(v,i+1,fim);
    return i+1;
}

void quickSort(int *v,int inicio,int fim){
    int meio;

    if(inicio<fim){
        meio = partition(v,inicio,fim);
        quickSort(v,inicio,meio-1);
        quickSort(v,meio+1,fim);
    }
}

int main () {
	int n = 10,i;
  
  srand(time(NULL));

	int *vetor = (int*) malloc (n * sizeof(int));

	for(i = 0; i < n; i++) vetor[i] = rand()%101;

    printVetor(vetor,n);

	quickSort(vetor, 0, n-1);

	printVetor(vetor,n);

	free (vetor);

	return 0;
}
