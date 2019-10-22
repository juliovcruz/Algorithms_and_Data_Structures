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

void merge(int *v, int inicio, int meio, int fim){
    int com1 = inicio;
    int com2 = meio+1;
    int comAux = 0;
    int *vAux = (int *) malloc(fim-inicio+1 * sizeof(int));

    while(com1 <= meio && com2 <=fim){
        if(v[com1] <= v[com2]){
            vAux[comAux] = v[com1];
            com1++;
        }
        else{
            vAux[comAux] = v[com2];
            com2++;
        }
        comAux++;
    }

    while(com1<=meio){
          vAux[comAux] = v[com1];
          comAux++;
          com1++;
    }

    while(com2<=fim){
        vAux[comAux] = v[com2];
        comAux++;
        com2++;
    }

    for(comAux = inicio; comAux<=fim;comAux++){
        v[comAux] = vAux[comAux - inicio];
    }

    free(vAux);

}

void mergeSort(int *v,int inicio, int fim){
    int meio;

    if(inicio<fim){
        meio =(inicio + fim) /2;

        mergeSort(v,inicio,meio);
        mergeSort(v,meio+1,fim);
        merge(v,inicio,meio,fim);
    }

}

int main(){
    int N,i;

    scanf("%d", &N);

    srand(time(NULL));

    int *v = (int *) malloc(N*sizeof(int));

    for(i=0;i<N;i++) v[i] = rand()%100;

    printVetor(v,N);

    mergeSort(v,0,N-1);

    printVetor(v,N);

    free(v);

    return 0;
}
