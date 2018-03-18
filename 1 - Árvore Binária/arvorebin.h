#ifndef _ARVOREBIN_H_
#define _ARVOREBIN_H_

/*
Estrutura para representação de um nodo
da árvore binária
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
manipulação da estrutura de dados Árvore Binária:
*/

/*
Para a criação da estrutura da árvore serão criadas duas funcoes:
	*arv_cria
	*arv_cria_nodo

A funcao arv_cria cria uma representação do TAD Arv_bin.
A funcao arv_cria_nodo é responsável por criar um novo 
nodo na árvore.
*/
Arv_bin* arv_cria(Nodo* raiz);
Nodo* arv_cria_no(char c, Nodo* esq, Nodo* dir);

/*
Funcao para exibir o conteúdo da árvore.
A funcao arv_imprime chama a arv_imprime_no,
passando como parâmetro o nodo raiz da árvore
binária:
*/
void arv_imprime(Arv_bin* arv);
void arv_imprime_no(Nodo* raiz);

/*
Imprime usando uma representação com parentização.
*/
void arv_imprime_formatado(Arv_bin* arv);
void arv_imprime_formatado_no(Nodo* raiz);

/*
Por fins didáticos a funcao arv_imprime_escolhendo_ordem
imprime a arvore binária em pre_ordem, ordem ou em pos ordem
dependendo da constante que for passada para o parâmetro 
'ordem'. O parâmetro 'ordem' pode assumir os seguintes valores:
1 - chama a funcao arv_imprime_pre_ordem
2 - chama a funcao arv_imprime_infixa
3 - chama a funcao arv_imprime_pos_ordem
*/
void arv_imprime_escolhendo_ordem(Arv_bin* arv, int ordem);

/*
mostra raiz, percorre sae, percorre sad
*/
void arv_imprime_pre_ordem(Nodo* raiz);
/*
percorre sae, mostra raiz, percorre sad
*/
void arv_imprime_infixa(Nodo* raiz);
/*
percorre sae, percorre sad, mostra raiz
*/
void arv_imprime_pos_ordem(Nodo* raiz);

/*
Funçoes para liberar memória. 
A funcao arv_libera deve passar como parâmetro o
nodo raiz da árvore binária.
A funcao arv_libera_no percorre a árvore até encontrar 
os nodos folha para ai sim liberará-los (pós-ordem). Do contrário,
perderíamos a referência da sae e sad
*/
void arv_libera(Arv_bin* arv);
void arv_libera_no(Nodo* raiz);

/*
Essa funcao deve informar se determinado nodo
pertence à árvore.
*/
int arv_pertence(Arv_bin* arv, char c);
int arv_pertence_no(Nodo* raiz, char c);

/*
Similar a funcao arv_pertence. Entretanto nesse
caso ela returna o Nodo encontrado ou NULL
caso ele não seja encontrado.
Em casos práticos, não é suficiente saber se o nodo está presente
na árvore. Na verdade, geralmente é necessário ter acesso ao nodo.
*/
Nodo* arv_busca(Arv_bin* arv, char c);
Nodo* arv_busca_no(Nodo* raiz, char c);

/*
Calcula a altura da árvore. No que uma árvore vazia tem altura = -1.
*/
int arv_altura(Arv_bin* arv);
int arv_altura_no(Nodo* raiz);

#endif