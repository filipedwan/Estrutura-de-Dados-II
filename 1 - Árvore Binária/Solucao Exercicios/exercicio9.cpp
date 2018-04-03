#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../arvorebin.h"

using namespace std;

Arv_bin * cria_uma_arvore_arbitraria();
int binaria_completa(Nodo *raiz);

int main () {
	Arv_bin *arv = cria_uma_arvore_arbitraria();

	int flag = binaria_completa(arv->raiz);
	flag == 1 ? printf("Binaria Completa\n"): printf("Nao eh Binaria Completa\n");

	arv_libera(arv);
}

int binaria_completa(Nodo *raiz) {
	if (raiz==NULL)
		return 1;
	if (raiz->esq==NULL && raiz->dir==NULL)
		return 1;
	if (raiz->esq!=NULL && raiz->dir!=NULL)
		return binaria_completa(raiz->esq) && binaria_completa(raiz->dir);
	return 0;
}

Arv_bin * cria_uma_arvore_arbitraria() {
	Arv_bin *arv = arv_cria(
			arv_cria_no('a',
					arv_cria_no('b', 
						arv_cria_no('h', NULL, NULL),
						arv_cria_no('d', NULL, NULL)
						),
					arv_cria_no('c',
						arv_cria_no('e', NULL, NULL),
						arv_cria_no('f', NULL, NULL)
						)
				)
		);
	return arv;
}
