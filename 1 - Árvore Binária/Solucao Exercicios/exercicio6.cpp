#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../arvorebin.h"
#include <stack>

using namespace std;

Arv_bin * cria_uma_arvore_arbitraria();
void imprime_pos_ordem_iterativo(Arv_bin *raiz);

int main () {
	Arv_bin *arv = cria_uma_arvore_arbitraria();

	imprime_pos_ordem_iterativo(arv);

	arv_libera(arv);
}


void imprime_pos_ordem_iterativo(Arv_bin *arv) {
	stack<Nodo *> pilha1;
	stack<Nodo *> pilha2;
	Nodo *p = NULL;

	pilha1.push(arv->raiz);

	while(!pilha1.empty()) {
		p = pilha1.top();
		pilha1.pop();
		pilha2.push(p);
		if (p->esq != NULL)
			pilha1.push(p->esq);
		if (p->dir != NULL)
			pilha1.push(p->dir);
	}

	while (!pilha2.empty()) {
		p = pilha2.top();
		pilha2.pop();
		printf("%c\n", p->info);
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
