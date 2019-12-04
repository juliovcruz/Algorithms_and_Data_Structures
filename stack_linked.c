#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pilha Pilha;
typedef struct no No;

struct no{
    char * elemento;
    No * proximo;
};

struct pilha{
    int tamanho,tamanhoMax;
    No * topo;
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
    q->topo = NULL;
    }

    return q;

}
Pilha * pilha_copia (Pilha * p){
    Pilha * aux1 = pilha_cria(p->tamanhoMax);
    Pilha * aux2 = pilha_cria(p->tamanhoMax);
    
    while(p->tamanho>0){
        pilha_insere(aux2,pilha_remove(p));
    }    

    while(aux2->tamanho>0){
        char * el = pilha_remove(aux2);
        pilha_insere(aux1,el);
        pilha_insere(p,el);
    }

    return aux1;
}
void pilha_libera (Pilha * p){
    No * aux = p->topo;

    while(aux!=NULL){
        No *q = aux;
        aux = aux->proximo;
        free(q->elemento);
        free(q);
    }

    free(p);

}
int pilha_insere (Pilha * p, char * elemento){
    if(p == NULL || pilha_se_cheia(p)) return 0;

    No * q = malloc(sizeof(No));
    q->elemento = malloc(sizeof(char) * strlen(elemento) + 1);
    strcpy(q->elemento,elemento);

    q->proximo = p->topo;
    p->topo = q;
    p->tamanho++;

    return 1;

}
char * pilha_remove (Pilha * p){
    if(p == NULL || pilha_se_vazia(p)) return 0;
    No * aux = p->topo;

    char * str = malloc(sizeof(char) * strlen(aux->elemento) + 1);
    strcpy(str,aux->elemento);

    p->topo = aux->proximo;
    p->tamanho--;

    free(aux->elemento);
    free(aux);

    return str;
}
char * pilha_obtem_topo  (Pilha * p){
    No * aux = p->topo;

    char * str = malloc(sizeof(char) * strlen(aux->elemento) + 1);
    strcpy(str,aux->elemento);

    return str;
    
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
    if(p==NULL || pilha_se_vazia(p)) return 0;
    int i;
    char *str = malloc(sizeof(char) * 1000);

    No * aux = p->topo;

    for(i=0;aux!=NULL;i++){
        if(i==0) sprintf(str, "%s ", aux->elemento);
            else sprintf(str, "%s%s ", str,aux->elemento);
        aux = aux->proximo;
    }

    return str;
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
