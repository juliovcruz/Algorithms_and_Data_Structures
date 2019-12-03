#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fila Fila;

struct fila{
    int inicio,final,tamanho,tamanhoMax;
    char **elementos;
};

Fila * fila_cria (int maxTamanho);
Fila * fila_copia (Fila * p);
void fila_libera (Fila * p);
int fila_insere (Fila * p, char * elemento);
char * fila_remove (Fila * p);
char * fila_obtem_primeiro (Fila * p);
int fila_obtem_tamanho (Fila * p);
int fila_se_vazia (Fila * p);
int fila_se_cheia (Fila * p);
char * fila_imprime (Fila * p);

Fila * fila_cria (int maxTamanho){
    Fila * q = malloc(sizeof(Fila));
    
    if(q!=NULL){
        q->final = 0;
        q->tamanho = 0;
        q->tamanhoMax = maxTamanho;
        q->inicio = 0;
        q->elementos = (char **) malloc(sizeof(char *) * maxTamanho);
    }

    return q;
}

Fila * fila_copia (Fila * p){
    Fila * q = fila_cria(p->tamanhoMax);

    for(i=p->inicio;i<p->final;i++){
        q->elementos[i] = malloc(sizeof(char) * strlen(p->elementos[i) + 1);
        strcpy(q->elementos[i],p->elementos[i]); 
    }

    return q;
}
void fila_libera (Fila * p){
    int i;

    for(i=0;i<p->tamanhoMax;i++){
        free(p->elementos[i]);
    }

    free(p->elementos);
    free(p);
}
int fila_insere (Fila * p, char * elemento){
    if( p == NULL || fila_se_cheia(p)) return 0;

    p->elementos[p->final] = malloc(sizeof(char) * strlen(elemento) + 1);
    strcpy(p->elementos[p->final], elemento);
    p->final = (p->final+1)%p->tamanhoMax;

    p->tamanho++;

    return 1;

}
char * fila_remove (Fila * p){
    if(p == NULL || fila_se_vazia(p)) return 0;

    char * aux = malloc(sizeof(char) * strlen(p->elementos[p->inicio]));
    strcpy(aux,p->elementos[p->inicio]);

    free(p->elementos[p->inicio]);
    p->tamanho--;

    p->inicio = (p->inicio+1)%p->tamanhoMax;

    return aux;
}
char * fila_obtem_primeiro (Fila * p){
    char * aux = malloc(sizeof(char) * strlen(p->elementos[p->inicio]));
    strcpy(aux,p->elementos[p->inicio]);

    return aux;

}
int fila_obtem_tamanho (Fila * p){
    return p->tamanho;
}
int fila_se_vazia (Fila * p){
    if(fila_obtem_tamanho(p) == 0) return 1;
        else return 0;
}
int fila_se_cheia (Fila * p){
    if(fila_obtem_tamanho(p) == p->tamanhoMax) return 1;
        else return 0;
}
char * fila_imprime (Fila * p){
    int i;
    char * aux = malloc(sizeof(char) * 10000);
    for(i=p->inicio;i<p->final;i++){
        if(i==p->inicio) sprintf(aux, "%s ", p->elementos[i]);
            else sprintf(aux, "%s%s ", aux, p->elementos[i]);
    }

    return aux;
}

int main(){
    int i;
    char * nome = malloc(sizeof(char) * 100);
    char * aux = malloc(sizeof(char) * 100);
    char * op = malloc(sizeof(char) * 100);

    Fila * p = fila_cria(100);

    while(1){
        scanf("%s", op);
        if(!strcmp(op,"finalizar")) break;
        else if(!strcmp(op,"consultar")) printf("%s\n", fila_imprime(p));
        else scanf("%s", nome);

        if(!strcmp(op, "inserir"))
            fila_insere(p,nome);

        if(!strcmp(op,"remover")){
            for(i=0;i<=p->tamanho;i++){
                aux = fila_remove(p);
                if(strcmp(aux,nome))
                    fila_insere(p,aux);
            }
        }


    }

    return 1;


}
