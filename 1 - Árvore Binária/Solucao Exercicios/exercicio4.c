#include <stdio.h>
#include <stdlib.h>
#include "../arvorebin.h"

Arv_bin * cria_uma_arvore_arbitraria();
Arv_bin * espelho(Arv_bin * arv);
Nodo * espelho_nodo(Nodo *raiz);

int main () {
	Arv_bin *arv = cria_uma_arvore_arbitraria();

	Arv_bin* arv_espelhada = espelho(arv);

	arv_libera(arv);
	arv_libera(arv_espelhada);
}

Arv_bin * espelho(Arv_bin * arv) {
	arv
}
Nodo * espelho_nodo(Nodo *raiz);


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

