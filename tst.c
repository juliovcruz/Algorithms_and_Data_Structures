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

void bubbleSort(int *v, int N){
    int i,aux;

    if(N>0){
        for(i=0;i<N;i++){
            if(v[i]>v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
        bubbleSort(v,N-1);
    }

}

int main(){
    int N,i;

    scanf("%d", &N);

    srand(time(NULL));

    int *v = (int *) malloc(N*sizeof(int));

    for(i=0;i<N;i++) v[i] = rand()%11;

    printVetor(v,N);

    bubbleSort(v,N-1);

    printVetor(v,N);

    free(v);

    return 0;
}