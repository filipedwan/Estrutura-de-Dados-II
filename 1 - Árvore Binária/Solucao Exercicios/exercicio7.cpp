#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../arvorebin.h"

using namespace std;

Arv_bin * cria_uma_arvore_arbitraria();
int numero_folhas(Nodo *raiz);

int main () {
	Arv_bin *arv = cria_uma_arvore_arbitraria();

	int qnt = numero_folhas(arv->raiz);
	printf("%d\n", qnt);

	arv_libera(arv);
}

int numero_folhas(Nodo *raiz) {
	if (raiz==NULL)
		return 0;
	if (raiz->esq==NULL && raiz->dir==NULL)
		return 1;
	return numero_folhas(raiz->esq) + numero_folhas(raiz->dir);
}

Arv_bin * cria_uma_arvore_arbitraria() {
	Arv_bin *arv = arv_cria(
			arv_cria_no('a',
					arv_cria_no('b', 
						NULL,
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
