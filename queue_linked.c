#include <stdlib.h>
#include <string.h>
#include <stdio.h>
    
#define MAX 100
    
typedef struct fila Fila;
typedef struct elemento Elemento;

struct elemento{
    Elemento * proximo;
    char *elemento;
};

struct fila{
    int tamanho;
    Elemento * cabeca;
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
    Fila *q = (Fila *) malloc(sizeof(Fila));
    
    if(q!=NULL){
        q->tamanho = 0;
        q->cabeca = NULL;
    }
    return q;
}
    
Fila * fila_copia (Fila * p);
void fila_libera (Fila * p){
    int i;

    Elemento *aux = p->cabeca;
    
    for(i=0;i<p->tamanho;i++){
        Elemento *q = aux;
        aux = aux->proximo;
        free(q);
    }
    
    free(p);
}
int fila_insere (Fila * p, char * elemento){
        int i=1;
    
    if(p==NULL) return 0;

        Elemento *q = malloc(sizeof(Elemento));
        q->proximo = NULL;
        q->elemento = (char *) malloc(sizeof(char) * strlen(elemento) + 1);
        strcpy( q->elemento , elemento);

    if(p->tamanho == 0){
        p->cabeca = q;
        p->tamanho++;
        return 1;
    }

    Elemento *aux = p->cabeca;
    
        while(aux->proximo!=NULL){
            aux = aux->proximo;
        }
    
        aux->proximo = q;
    
        p->tamanho++;
        return 1;
    
    
}
char * fila_remove (Fila * p){
    if(p== NULL || fila_se_vazia(p)) return 0;

    Elemento *aux = p->cabeca;

    char *str = malloc(sizeof(char) * strlen(aux->elemento) +1);
    strcpy(str, aux->elemento);

    p->cabeca = aux->proximo;

    free(aux);
    
    p->tamanho--;
    
    return str;
    
}
char * fila_obtem_primeiro (Fila * p){
    Elemento *aux = p->cabeca;
    return aux->elemento;
}
int fila_obtem_tamanho (Fila * p){
    return p->tamanho;
}
int fila_se_vazia (Fila * p){
    if(p->tamanho == 0) return 1;
        else return 0;
}
int fila_se_cheia (Fila * p){
    return 0;
}
char * fila_imprime (Fila * p){
    char * str = malloc(sizeof(char) * 10000);
    int i;

    Elemento *aux = p->cabeca;
    
    for(i=1;aux!=NULL;i++){
        if(i == 1) sprintf(str,"%s ", aux->elemento);
            else sprintf(str, "%s%s ",str,aux->elemento);
        aux = aux->proximo;
    }
    
    return str;
    
}

    int fila_obtem_posicao(Fila *p, char * elemento){

        int pos;

        Elemento * aux = p->cabeca;

        for(pos = 1; aux ->proximo!=NULL;pos++){
            if(!strcmp(aux->elemento,elemento)) break;
            aux = aux->proximo;
        }

        return pos;
    }

int fila_mover(Fila *p, char * elemento, int pos){
    int i;

    Elemento * aux = p->cabeca;

    pos += fila_obtem_posicao(p,elemento);

    if(pos < 0 || pos > fila_obtem_tamanho(p)) return 0;

    if(pos>0){
        while(fila_obtem_posicao(p,elemento) != pos ){
            fila_insere(p,fila_remove(p));
        }
    }

    return 1;

}
    
int main(){
    int i,pos;
    
    char * operacao = malloc(sizeof(char) * 100);
    char * nome = malloc(sizeof(char) * 100);
    char * aux = malloc(sizeof(char) * 100);
    
    Fila *p = fila_cria(MAX);
        
    while(1){

        scanf("%s", operacao);
        if(!strcmp(operacao, "finalizar")) break;
        else if(!strcmp(operacao, "consultar")) printf("%s\n", fila_imprime(p));
        else scanf("%s", nome);


        if(!strcmp(operacao, "inserir")){
            fila_insere(p,nome);
        }
            
    
        else if(!strcmp(operacao,"remover")){
            for(i=p->tamanho;i>0;i--){
                aux = fila_remove(p);
                if(strcmp(aux,nome))
                    fila_insere(p,aux);
            }

        }

        else if(!strcmp(operacao, "mover")){
            scanf("%d", &pos);
            fila_mover(p,nome,pos);
        }
    
    
    }
    
    
    return 0;
}
