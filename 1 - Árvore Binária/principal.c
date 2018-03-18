#include<stdio.h>
#include<stdlib.h>
#include"arvorebin.h"

int main () {
	//Exemplo de criação de uma árvore binária:
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
	arv_imprime(arv);

	arv_imprime_escolhendo_ordem(arv, 1);
	arv_imprime_escolhendo_ordem(arv, 2);
	arv_imprime_escolhendo_ordem(arv, 3);
	
	arv_pertence(arv, 'f') ? printf("sim\n") : printf("nao\n");
	
	Nodo *n = arv_busca(arv, 'f');
	if(n!=NULL)
		printf("Nodo Encontrado: %c\n", n->info);
	
	arv_imprime_formatado(arv);

	printf("Altura da arvore: %d\n", arv_altura(arv));
	
	arv_libera(arv);
}