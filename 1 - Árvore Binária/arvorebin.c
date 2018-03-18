#include<stdio.h>
#include<stdlib.h>
#include"arvorebin.h"

Arv_bin* arv_cria(Nodo* raiz) {
	Arv_bin* arv = (Arv_bin*) malloc(sizeof(Arv_bin));
	arv->raiz = raiz;
	return arv;
}

Nodo* arv_cria_no(char c, Nodo* esq, Nodo* dir) {
	Nodo * nodo = (Nodo *) malloc(sizeof(Nodo));
	nodo->esq = esq;
	nodo->dir = dir;
	nodo->info = c;
	return nodo;
}

void arv_imprime(Arv_bin* arv) {
	arv_imprime_no(arv->raiz);
}

void arv_imprime_no(Nodo* raiz) {
	if (raiz!=NULL) {
		printf("%c\n", raiz->info);
		arv_imprime_no(raiz->esq);
		arv_imprime_no(raiz->dir);
	}
}

void arv_imprime_formatado(Arv_bin* arv) {
	arv_imprime_formatado_no(arv->raiz);
	printf("\n");
}

void arv_imprime_formatado_no(Nodo* raiz) {
	printf("<");
	if (raiz!=NULL) {
		printf("%c", raiz->info);
		arv_imprime_formatado_no(raiz->esq);
		arv_imprime_formatado_no(raiz->dir);
	}
	printf(">");
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

int arv_pertence(Arv_bin* arv, char c) {
	return arv_pertence_no(arv->raiz, c);
}


int arv_pertence_no(Nodo* raiz, char c) {
	if (raiz==NULL)
		return 0;
	if (raiz->info==c)
		return 1;
	else if (arv_pertence_no(raiz->esq, c))
		return 1;
	else
		return arv_pertence_no(raiz->dir, c);
	//return arv_pertence_no(raiz->esq, c) || 
	//	arv_pertence_no(raiz->dir, c);
}

/**
A funcao abaixo funciona porque em uma condicao OR (||)
ao ser verdaira uma proposicao simples pertencente a uma proposicao
composta, então toda a proposicao composta eh verdadeira.


int arv_pertence_no(Nodo* raiz, char c) {
	if (raiz==NULL)
		return 0;
	else 
		return c==raiz->info || 
				arv_pertence_no(raiz->esq, c) ||
				arv_pertence_no(raiz->dir, c);
}
*/

Nodo* arv_busca(Arv_bin* arv, char c) {
	return arv_busca_no(arv->raiz, c);
}

Nodo* arv_busca_no(Nodo* raiz, char c) {
	if (raiz == NULL)
		return NULL; //arvore vazia, não encontrou
	else if (raiz->info == c)
		return raiz;
	else {
		Nodo *no = arv_busca_no(raiz->esq, c); //busca na sae
		if (no!=NULL)
			return no;
		else 
			return arv_busca_no(raiz->dir, c); //busca na sad
	}
}

void arv_imprime_escolhendo_ordem(Arv_bin* arv, int ordem) {
	if (ordem==1)
		arv_imprime_pre_ordem(arv->raiz);
	else if (ordem==2)
		arv_imprime_infixa(arv->raiz);
	else if (ordem == 3)
		arv_imprime_pos_ordem(arv->raiz);
	else
		printf("Valor invalido! Escolha um valor entre [1-3]");
	printf("\n");
}

void arv_imprime_pre_ordem(Nodo* raiz) {
	if (raiz!=NULL) {
		printf("%c", raiz->info);
		arv_imprime_pre_ordem(raiz->esq);
		arv_imprime_pre_ordem(raiz->dir);
	}
}
void arv_imprime_infixa(Nodo* raiz) {
	if (raiz!=NULL) {
		arv_imprime_infixa(raiz->esq);
		printf("%c", raiz->info);
		arv_imprime_infixa(raiz->dir);
	}
}
void arv_imprime_pos_ordem(Nodo* raiz) {
	if (raiz!=NULL) {
		arv_imprime_pos_ordem(raiz->esq);
		arv_imprime_pos_ordem(raiz->dir);
		printf("%c", raiz->info);
	}	
}

int arv_altura(Arv_bin* arv) {
	return arv_altura_no(arv->raiz);
}

int max(int alt_sae, int alt_sad) {
	return alt_sae>alt_sad ? alt_sae : alt_sad;
}

int arv_altura_no(Nodo* raiz) {
	if (raiz == NULL)
		return -1;
	int alt_sae = 1+arv_altura_no(raiz->esq);
	int alt_sad = 1+arv_altura_no(raiz->dir);
	return max(alt_sae, alt_sad);
}

/*
A funcao arv_altura_no poderia ser escrita da seguinte forma:

int arv_altura_no(Nodo* raiz) {
	if (raiz == NULL)
		return -1;
	return 1 + max(arv_altura_no(raiz->esq), arv_altura_no(raiz->dir));
}
*/