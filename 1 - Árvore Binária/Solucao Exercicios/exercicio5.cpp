#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../arvorebin.h"
#include <stack>

using namespace std;

Arv_bin * cria_uma_arvore_arbitraria();
void imprime_in_ordem_iterativo(Arv_bin *raiz);

int main () {
	Arv_bin *arv = cria_uma_arvore_arbitraria();

	imprime_in_ordem_iterativo(arv);

	arv_libera(arv);
}


void imprime_in_ordem_iterativo(Arv_bin *arv) {
	stack<Nodo *> pilha;
	Nodo *p = arv->raiz;

	while(p!=NULL || !pilha.empty()) {		
		if (p!=NULL) {
			pilha.push(p);
			p = p->esq;
		}
		else {
			p = pilha.top();
			pilha.pop();
			printf("%c\n", p->info);
			p = p->dir;
		}
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
