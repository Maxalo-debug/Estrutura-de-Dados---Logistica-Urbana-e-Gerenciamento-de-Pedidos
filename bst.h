#ifndef BST_H
#define BST_H

#include "entidades.h"

/*
 * Estrutura: NoBST
 * Descricao: No encadeado da Arvore Binaria de Busca (BST) organizada por id_ponto.
 */
typedef struct NoBST {
    PontoEntrega dado;
    struct NoBST *esquerda;
    struct NoBST *direita;
} NoBST;

/*
 * Funcao: criar_no_bst
 * Complexidade Temporal: O(1) pior caso
 * Descricao: Aloca dinamicamente um novo no da BST com os dados do ponto de entrega
 * Retorna o ponteiro para o no criado ou NULL em caso de falha na alocacao.
 */
NoBST* criar_no_bst(PontoEntrega ponto);


/*
 * Funcao: inserir_ponto
 * Complexidade Temporal: O(log n) medio / O(n) pior caso
 * Descricao: Insere recursivamente um novo ponto de entrega na BST respeitando
 * a ordenacao por id_ponto (RF01). Nao permite codigos duplicados.
 * O parametro 'inserido' recebe 1 em caso de sucesso ou 0 se o codigo ja existir.
 * Retorna o ponteiro atualizado para a raiz da subarvore.
 */
NoBST* inserir_ponto(NoBST *raiz, PontoEntrega ponto, int *inserido);


/*
 * Funcao: buscar_ponto
 * Complexidade Temporal: O(log n) medio / O(n) pior caso
 * Descricao: Localiza recursivamente um ponto de entrega a partir do seu id_ponto (RF02).
 * Retorna o ponteiro para o no encontrado ou NULL caso nao exista.
 */
NoBST* buscar_ponto(NoBST *raiz, int id_ponto);


/*
 * Funcao: listar_pontos_em_ordem
 * Complexidade Temporal: O(n) pior caso
 * Descricao: Percorre recursivamente a BST utilizando o percurso em ordem (in-order),
 * exibindo todos os pontos em ordem crescente de id_ponto (RF03).
 */
void listar_pontos_em_ordem(NoBST *raiz);


/*
 * Funcao: encontrar_minimo_bst
 * Complexidade Temporal: O(log n) medio / O(n) pior caso
 * Descricao: Funcao auxiliar recursiva que encontra o no com o menor id_ponto
 * em uma subarvore (utilizada no caso de remocao de no com 2 filhos).
 * Retorna o ponteiro para o no minimo.
 */
NoBST* encontrar_minimo_bst(NoBST *raiz);

/*
 * Funcao: remover_ponto
 * Complexidade Temporal: O(log n) medio / O(n) pior caso
 * Descricao: Remove recursivamente um ponto de entrega da BST tratando os 3 casos
 * classicos: no folha, no com 1 filho e no com 2 filhos (RF03.1).
 * Pre-condicao: Verificar previamente se nao ha pedidos pendentes vinculados ao id_ponto.
 * O parametro 'removido' recebe 1 se o no foi excluido ou 0 se nao foi encontrado.
 * Retorna o ponteiro atualizado para a raiz da subarvore.
 */
NoBST* remover_ponto(NoBST *raiz, int id_ponto, int *removido);


/*
 * Funcao: liberar_bst
 * Complexidade Temporal: O(n) pior caso
 * Descricao: Percorre a arvore em pos-ordem liberando toda a memoria alocada
 * dinamicamente para os nos da BST ao final da execucao.
 */
void liberar_bst(NoBST *raiz);


#endif