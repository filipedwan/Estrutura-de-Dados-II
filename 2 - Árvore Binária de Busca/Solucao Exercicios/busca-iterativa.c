#include <stdio.h>
#include <stdlib.h>
#include "../arvbb.h"

Nodo *arv_busca_no_iter(Nodo *raiz, char c) {
  while (raiz!=NULL && raiz->info!=c) {
    if (c<raiz->info)
      raiz = raiz->esq;
    else
      raiz = raiz->dir;
  }
  return r;
}


void main() {
    Arv_bin* arv = abb_cria();
    abb_insere(arv, 'd');
    abb_insere(arv, 'b');
    abb_insere(arv, 'g');
    abb_insere(arv, 'a');
    Nodo *aux = arv_busca_no_iter(arv, 'b');
    if (!aux)
      printf("%c", aux->info);   
    return 0;
}
