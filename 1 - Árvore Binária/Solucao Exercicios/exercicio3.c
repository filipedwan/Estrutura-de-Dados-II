#include <stdio.h>
#include <stdlib.h>
#include "../arvorebin.h"

Arv_bin * cria_uma_arvore_arbitraria();

int tamanho(Arv_bin * arv);

int main () {
	Arv_bin *arv = cria_uma_arvore_arbitraria();

	printf("%d\n", tamanho(arv));

	arv_libera(arv);
}

int tamanho(Arv_bin * arv) {
	return tamanho_nodo(arv->raiz);
}

int tamanho_nodo(Nodo * raiz) {
	if (raiz==NULL) 
		return 0;
	return 1+tamanho_nodo(raiz->esq)+tamanho_nodo(raiz->dir);
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
