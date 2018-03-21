#include <stdio.h>
#include <stdlib.h>
#include "../arvorebin.h"

Arv_bin * cria_uma_arvore_arbitraria();
Arv_bin * espelho(Arv_bin * arv);
void espelho_nodo(Nodo *ori_raiz, Nodo *esp_raiz);

int main () {
	Arv_bin *arv = cria_uma_arvore_arbitraria();

	Arv_bin* arv_espelhada = espelho(arv);

	arv_imprime_escolhendo_ordem(arv, 1);
	arv_imprime_escolhendo_ordem(arv_espelhada, 1);

	arv_libera(arv);
	arv_libera(arv_espelhada);
}


Arv_bin * espelho(Arv_bin * arv) {
	Arv_bin * nova = NULL;

	if (arv->raiz != NULL) {
		nova = arv_cria(arv_cria_no(arv->raiz->info, NULL, NULL));
		espelho_nodo(arv->raiz, nova->raiz);
	}
	return nova;
}
void espelho_nodo(Nodo *ori_raiz, Nodo *esp_raiz) {
	if (ori_raiz!=NULL) {
		if (ori_raiz->esq != NULL)
			esp_raiz->dir = arv_cria_no(ori_raiz->esq->info, NULL, NULL);
		espelho_nodo(ori_raiz->esq, esp_raiz->dir);
		if (ori_raiz->dir != NULL)
			esp_raiz->esq = arv_cria_no(ori_raiz->dir->info, NULL, NULL);
		espelho_nodo(ori_raiz->dir, esp_raiz->esq);
	}
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

