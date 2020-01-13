#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printVetor(int *v, int N){

    for(int i = 0;i<N;i++){
        printf("%d ", v[i]);
    }   printf("%\n");
}

void countingSort(int *A, int N,int MAX) {
    int i;

    int *B = malloc(sizeof(int) * N);
    int *C = calloc(sizeof(int) ,MAX);

    for(i=0;i<N;i++) C[A[i]-1]++;

	for(i=1;i<MAX;i++) C[i] += C[i-1];

	for(i=N-1;i>=0;i--) {
		B[C[A[i]-1]-1] = A[i];
		C[A[i]-1]--;
	}

	for(i=0;i<N;i++) A[i] = B[i];

}

int main(){
    int N;
    scanf("%d", &N);

    int *v = malloc(sizeof(int) * N);

    srand(time(NULL));

    for(int i=0;i<N;i++) v[i] = rand()%100;

    printVetor(v,N);

    countingSort(v,N,100);

    printVetor(v,N);


    return 0;
}
