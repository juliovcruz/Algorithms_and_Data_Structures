#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printVetor(int *v, int N){

    for(int i = 0;i<N;i++){
        printf("%d ", v[i]);
    }   printf("%\n");
}

void selectionSort(int *v, int N){

    int i,j,min,aux;

    for(i=0;i<N;i++){
        min = i;
            for(j=i;j<N;j++){
                if(v[j] < v[min]) {
                    min = j;
                }
            }

        aux = v[i];
        v[i] = v[min];
        v[min] = aux;

    }

}

int main(){
    int N;
    scanf("%d", &N);

    int *v = malloc(sizeof(int) * N);

    srand(time(NULL));

    for(int i=0;i<N;i++) v[i] = rand()%111;

    printVetor(v,N);

    selectionSort(v,N);

    printVetor(v,N);


    return 0;
}
