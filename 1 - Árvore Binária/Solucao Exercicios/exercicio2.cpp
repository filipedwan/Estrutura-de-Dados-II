#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../arvorebin.h"
#include <queue>

using namespace std;

Arv_bin * cria_uma_arvore_arbitraria();

int main () {
	//Exemplo de criação de uma árvore binária:
	Arv_bin *arv = cria_uma_arvore_arbitraria();

	queue<Nodo *> fila;
	Nodo *corr = NULL;

	fila.push(arv->raiz);

	while(!fila.empty()) {
		corr = fila.front();
		printf("%c\n", corr->info);
		fila.pop();
		if (corr->esq!=NULL)
			fila.push(corr->esq);
		if (corr->dir!=NULL)
			fila.push(corr->dir);
	}

	arv_libera(arv);
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
