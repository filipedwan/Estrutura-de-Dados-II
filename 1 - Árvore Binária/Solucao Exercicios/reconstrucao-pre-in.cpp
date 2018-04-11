#include <stdio.h>
#include <stdlib.h>
#include "../arvorebin.h"

/*
Ideia do Algoritmo constroiArvoreBin:
1) Pegar o elemento do percurso em pre-ordem. Incrementar o índece preIndex 
que aponta para pegar a raiz da próxima chamada recursiva;
2) Alocar o espaço de um novo nodo R com os dados do elemento que foi pego na etapa 1.
3) Encontrar o índice do elemento da etapa 1 no percurso in-ordem. Chamar
esse índice de inIndex.
4) Chamar recursiva da funcao constroiArvoreBin para os elementos antes do inIndex e fazer essa árvore ser a subárvore esquerda do nodo R criado na etapa 2.
5) Chamar recursiva da funcao constroiArvoreBin para os elementos depois do inIndex e fazer essa árvore ser a subárvore direita do nodo R criado na etapa 2.
6) return o nodo R.

protótipo da funcao controiArvoreBin:
Nodo* controiArvoreBin((char inordem[], char preordem[], int inInicio, int inFim))
Caso base da recursão:
Se o inInicio e o inFIM se cruzarem, então retornar NULL;
Se o inInicio e o inFIM forem iguais, então retornar o nodo alocado R;
*/
 
int busca_index(char str[], int ini, int fim, char v);
Nodo* criaNodo(char c);
Nodo* constroiArvoreBin(char in[], char pre[], int inIni, int inFim);

int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  Nodo *raiz = constroiArvoreBin(in, pre, 0, len - 1);
 
  printf("Impressao In-ordem da arvore construida\n");
  arv_imprime_infixa(raiz);
  return 0;
}

/* Recursive function to construct binary of size len from
   Inorder traversal in[] and Preorder traversal pre[].  Initial values
   of inStrt and inEnd should be 0 and len -1.  The function doesn't
   do any error checking for cases where inorder and preorder
   do not form a tree */
Nodo* constroiArvoreBin(char in[], char pre[], int inIni, int inFim) {
  static int preIndex = 0;
 
  if(inIni > inFim)
     return NULL;
 
  /* Pega o caractere corrente do percurso em pré-ordem e cria um nodo
  com esse caractere. Depois incrementa a variável estática preIndex.*/
  Nodo *r = criaNodo(pre[preIndex++]);
 
  /* Se o nodo não tem filhos, então retorna ele. */
  if(inIni == inFim) {
    r->esq = r->dir = NULL;
    return r;
    }
 
  /* Encontra o index do caractere corrente no percurso inordem */
  int inIndex = busca_index(in, inIni, inFim, r->info);
 
  /* Usando o inIndex para construir a sae e sad do nodo corrente */
  r->esq = constroiArvoreBin(in, pre, inIni, inIndex-1);
  r->dir = constroiArvoreBin(in, pre, inIndex+1, inFim);
 
  return r;
}
 
/* Encontra o índice do caractere v na string str[ini...fim] */
int busca_index(char str[], int ini, int fim, char v) {
  int i;
  for(i = ini; i <= fim; i++)
  {
    if(str[i] == v)
      return i;
  }
}
 
/* Cria um nodo sem filhos. */
Nodo* criaNodo(char c) {
  Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
  novo->info = c;
  novo->esq = NULL;
  novo->dir = NULL;
  return novo;
}