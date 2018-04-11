#ifndef _ARVBB_H_
#define _ARVBB_H_

/*
Estrutura para representação de um nodo
da árvore binária de busca
*/
typedef struct no {
	char info;
	struct no *esq;
	struct no *dir;
}Nodo;

/*
Tipo Abstrato para Representação
da Árvore como um todo
*/
typedef struct arv_bin {
	Nodo * raiz;
}Arv_bin;


/*
Interface do TAD com as operações para
manipulação da estrutura de dados Árvore Binária de Busca:
*/

/*
A funcao abb_cria cria uma uma árvore binária de busca
inicialmente vazia.
*/
Arv_bin* abb_cria(void);

/*
Funcao para exibir o conteúdo da árvore.
A funcao arv_imprime chama a arv_imprime_no,
passando como parâmetro o nodo raiz da árvore
binária de busca.
Usa o percurso in-ordem.
*/
void arv_imprime(Arv_bin* arv);
void arv_imprime_no(Nodo* raiz);

/*
Funçoes para liberar memória. 
A funcao arv_libera deve passar como parâmetro o
nodo raiz da árvore binária.
A funcao arv_libera_no percorre a árvore até encontrar 
os nodos folha para ai sim liberá-los (pós-ordem). Do contrário,
perderíamos a referência da sae e sad
*/

void arv_libera(Arv_bin* arv);
void arv_libera_no(Nodo* raiz);

/*
Realiza a busca de uma elemento da árvore binária de busca
*/
Nodo* arv_busca_no(Nodo* raiz, char c);

/*
A operação de inserção adiciona um nodo na posição correta da árvore
a fim de que a propriedade fundamental seja mantida.
**Se a (sub)árvore for vazia, então ela será substituída por uma árvore
cujo único nodo (o nodo raiz) contenha o valor v.
**Se a árvore não for vazia, comparamos v com o valor da raiz da árvore
e inserimos na sae ou sad, dependendo da comparação. 
*/

void abb_insere(Arv_bin* arv, char c);
Nodo* insere_no(Nodo* raiz, char c);

/*
A operação de remoção remove um nodo na posição correta da árvore
a fim de que a propriedade fundamental seja mantida.
**Se a (sub)árvore for vazia, então nada acontecerá, pois o elemento não está
presente na árvore.
**Se a árvore não for vazia, comparamos v com o valor da raiz da árvore. Se
os valores forem iguais, então este será o nodo removido, do contrário, com base na
comparação, o nodo será removido na sae ou sad.
Observe que em todos os casos, o nodo removido é a raiz de uma (sub)árvore.
Na remoção, existem três casos possíveis:
1 - Nodo a ser removido não tem filhos. Nesse caso, basta liberar a memória
e retornar NULL;
2 - Nodo a ser removido tem um filho. Nesse caso, o nodo passa a ser 
o filho dele.
3 - Nodo a ser removido tem dois filhos (mais complexo).
3.1 - Encontrar o nodo mais à direita da subárvore à esquerda;
3.2 - Trocar a informação da raiz com a do nodo encontrado;
3.3 - Remover o nodo da subárvore à esquerda, chamamos a função recursivamente.
*/

void abb_remove(Arv_bin* arv, char c);
Nodo* remove_no(Nodo* raiz, char c);

#endif