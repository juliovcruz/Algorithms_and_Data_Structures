#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printVetor(int *v, int N){

    for(int i = 0;i<N;i++){
        printf("%d ", v[i]);
    }   printf("%\n");
}

void bubbleSort(int *v, int N) {
    int i,flag,aux;

    while(N>1 && flag){
        flag = 0;

        for(i=0;i<N;i++){
            if(v[i]>v[i+1]){
                aux = v[i+1];
                v[i+1] = v[i];
                v[i] = aux;
                flag = 1;
            }
        }

        N--;
    }

}

int main(){
    int N;
    scanf("%d", &N);

    int *v = malloc(sizeof(int) * N);

    srand(time(NULL));

    for(int i=0;i<N;i++) v[i] = rand()%111;

    printVetor(v,N);

    bubbleSort(v,N);

    printVetor(v,N);


    return 0;
}
