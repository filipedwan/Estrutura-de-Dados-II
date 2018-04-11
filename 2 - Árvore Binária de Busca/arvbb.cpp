#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "arvbb.h"

Arv_bin* abb_cria(void) {
	Arv_bin* arv = (Arv_bin*) malloc(sizeof(Arv_bin));
	arv->raiz = NULL;
	return arv;
}

void arv_imprime(Arv_bin* arv) {
	arv_imprime_no(arv->raiz);
}
void arv_imprime_no(Nodo* raiz) {
	if (raiz!=NULL) {
		arv_imprime_no(raiz->esq);
		printf("%c\n", raiz->info);
		arv_imprime_no(raiz->dir);
	}
}

void arv_libera(Arv_bin* arv) {
	arv_libera_no(arv->raiz);
	free(arv);
}

void arv_libera_no(Nodo* raiz) {
	if (raiz!=NULL) {
		arv_libera_no(raiz->esq);
		arv_libera_no(raiz->dir);
		free(raiz);
	}
}

Nodo* arv_busca_no(Nodo* raiz, char c) {
	if (raiz==NULL || raiz->info==c)
		return raiz;
	if (c<raiz->info)
		return arv_busca_no(raiz->esq, c);
	else
		return arv_busca_no(raiz->dir, c);
}

/*
A operação de inserção adiciona um nodo na posição correta da árvore
a fim de que a propriedade fundamental seja mantida.
**Se a (sub)árvore for vazia, então ela será substituída por uma árvore
cujo único nodo (o nodo raiz) contenha o valor v.
**Se a árvore não for vazia, comparamos v com o valor da raiz da árvore
e inserimos na sae ou sad, dependendo da comparação. 
*/

void abb_insere(Arv_bin* arv, char c) {
	arv->raiz = insere_no(arv->raiz, c);
}

Nodo* insere_no(Nodo* raiz, char c) {
	if (raiz==NULL) {
		raiz = (Nodo*) malloc(sizeof(Nodo));
		raiz->info = c;
		raiz->esq = raiz->dir = NULL;
	} 
	else if (c < raiz->info)
		raiz->esq = insere_no(raiz->esq, c);
	else
		raiz->dir = insere_no(raiz->dir, c);
	return raiz;
}

void abb_remove(Arv_bin* arv, char c) {
	arv->raiz = remove_no(arv->raiz, c);
}

Nodo* remove_no(Nodo* raiz, char c) {
	if (raiz == NULL)
		return NULL;
	else if (c < raiz->info)
		raiz->esq = remove_no(raiz->esq, c);
	else if (c > raiz->info)
		raiz->dir = remove_no(raiz->dir, c);
	else {
		/*nodo não tem filhos*/
		if (raiz->esq==NULL && raiz->dir==NULL) {
			free(raiz);
			raiz = NULL;
		}
		/*só tem o filho à direita */
		else if (raiz->esq==NULL) {
			Nodo *aux = raiz;
			raiz = raiz->dir;
			free(aux);
		}
		/*só tem o filho à esquerda */
		else if (raiz->dir==NULL) {
			Nodo *aux = raiz;
			raiz = raiz->esq;
			free(aux);
		}
		/* tem dois filhos */
		else {
			Nodo *aux = raiz->esq;
			while (aux->dir!=NULL) {
				aux = aux->dir;
			}
			/*troca as informações da raiz
			com o nodo mais à direita da sae*/
			raiz->info = aux->info;
			aux->info = c;
			raiz->esq = remove_no(raiz->esq, c);
		}
	}
	return raiz;
}