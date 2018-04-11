#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "arvbb.h"

int main() {
	Arv_bin* arv = abb_cria();
	
	abb_insere(arv, 'g');
	abb_insere(arv, 'c');
	abb_insere(arv, 'p');
	abb_insere(arv, 'b');
	abb_insere(arv, 'd');
	abb_insere(arv, 'h');
	abb_insere(arv, 'r');
	
	abb_remove(arv, 'g');
	abb_remove(arv, 'c');
	
	arv_imprime(arv);
	arv_libera(arv);
	return 0;
}