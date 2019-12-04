#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pilha Pilha;

struct pilha{
    int tamanho,tamanhoMax;
    char **elementos;
};

Pilha * pilha_cria (int maxTamanho);
Pilha * pilha_copia (Pilha * p);
void pilha_libera (Pilha * p);
int pilha_insere (Pilha * p, char * elemento); // push
char * pilha_remove (Pilha * p); // pop
char * pilha_obtem_topo  (Pilha * p); // top
int pilha_obtem_tamanho  (Pilha * p);
int pilha_se_vazia (Pilha * p);
int pilha_se_cheia (Pilha * p);
char * pilha_imprime  (Pilha * p);

Pilha * pilha_cria (int maxTamanho){
    Pilha * q = malloc(sizeof(Pilha));

    if(q!=NULL){
        q->tamanho = 0;
        q->tamanhoMax = maxTamanho;
        q->elementos = (char **) malloc(sizeof(char *) * maxTamanho);
    }

    return q;
}
Pilha * pilha_copia (Pilha * p){
    Pilha *q = pilha_cria(p->tamanhoMax);
    int i;

    for(i=0;i<p->tamanho;i++){
        q->elementos[i] = malloc(sizeof(char) * strlen(p->elementos[i]));
        strcpy(q->elementos[i],p->elementos[i]);
    }
    
    q->tamanho = p->tamanho;

    return q;

}
void pilha_libera (Pilha * p){
    int i;
    for(i=0;i<p->tamanho;i++){
        free(p->elementos[i]);
    }

    free(p->elementos);
    free(p);
}
int pilha_insere (Pilha * p, char * elemento){
    if(p == NULL || pilha_se_cheia(p)) return 0;

    p->elementos[p->tamanho] = malloc(sizeof(char) * strlen(elemento) + 1);

    strcpy(p->elementos[p->tamanho],elemento);

    p->tamanho++;
    return 1;
}
char * pilha_remove (Pilha * p){
    if(p==NULL || pilha_se_vazia(p)) return 0;

    char * aux = malloc(sizeof(char) * strlen(p->elementos[p->tamanho]));

    strcpy(aux,p->elementos[p->tamanho-1]);
    free(p->elementos[p->tamanho-1]);
    p->tamanho--;

    return aux;

}
char * pilha_obtem_topo  (Pilha * p){
    if(p == NULL || pilha_se_vazia(p)) return 0;
    return p->elementos[pilha_obtem_tamanho(p)-1];
}
int pilha_obtem_tamanho  (Pilha * p){
    return p->tamanho;
}
int pilha_se_vazia (Pilha * p){
    if(p->tamanho == 0) return 1;
        else return 0;
}
int pilha_se_cheia (Pilha * p){
    if(p->tamanho == p->tamanhoMax) return 1;
        else return 0;
}

char * pilha_imprime  (Pilha * p){
    int i;
    char * aux = malloc(sizeof(char) * 1000);
    aux[0] = '\0';
 
    if(p->tamanho == 0) return aux;
   
    for(i=0;i<pilha_obtem_tamanho(p);i++){
        if(i==0) sprintf(aux, "%s ", p->elementos[i]);
            else sprintf(aux, "%s%s ", aux, p->elementos[i]);
    }
 
    return aux;
   
}

int main () {
 
    Pilha * p = pilha_cria (100);
    pilha_insere  (p, "44");
    pilha_insere  (p, "bola");
    pilha_insere  (p, "33");
    pilha_insere  (p, "carro");
    printf("[pilha original: %d] #topo# %s\n", pilha_obtem_tamanho(p), pilha_imprime(p));
    Pilha * q = pilha_copia (p);
    printf("[pilha copia: %d   ] #topo# %s\n", pilha_obtem_tamanho(q), pilha_imprime(q));
    pilha_insere  (q, "mostarda");
    printf("[pilha copia: %d   ] #topo# %s\n", pilha_obtem_tamanho(q), pilha_imprime(q));
    pilha_libera(q);
    pilha_libera(p);
   
    return 1;
}
