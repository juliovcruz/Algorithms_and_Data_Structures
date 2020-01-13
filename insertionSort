#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printVetor(int *v, int N){

    for(int i = 0;i<N;i++){
        printf("%d ", v[i]);
    }   printf("%\n");
}

void insertionSort(int *v, int n) {
	int i = 0, j = 1, aux = 0;
	while (j < n) {
		aux = v[j];
		i = j - 1;

		while (i >= 0 && v[i] > aux) {
			v[i+1] = v[i];
			i--;
		}

		v[i+1] = aux;
		j++;

	}
}

int main(){
    int N;
    scanf("%d", &N);

    int *v = malloc(sizeof(int) * N);

    srand(time(NULL));

    for(int i=0;i<N;i++) v[i] = rand()%111;

    printVetor(v,N);

    insertionSort(v,N);

    printVetor(v,N);


    return 0;
}
