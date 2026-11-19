#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "entidades.h"
#include "historico.h"
#include "bst.h"
#include "heap.h"

#define POR_CODIGO 1
#define POR_VALOR 2

#define INSERTION_SORT 1
#define MERGE_SORT 2

/*
 * Funcao: insertion_sort
 * Complexidade Temporal: O(n^2) pior caso
 * Descricao: Ordena os pedidos pelo criterio escolhido,
 * utilizando o algoritmo Insertion Sort (RF11).
 */
void insertion_sort(PedidoEntrega dados[], int n, int criterio);


/*
 * Funcao: merge_sort
 * Complexidade Temporal: O(n log n) pior caso
 * Descricao: Ordena os pedidos pelo criterio escolhido,
 * utilizando o algoritmo Merge Sort (RF11).
 */
void merge_sort(PedidoEntrega dados[], int inicio, int fim, int criterio);


/*
 * Funcao: gerar_relatorio
 * Complexidade Temporal: O(n^2) pior caso
 * Descricao: Gera um relatorio dos pedidos processados,
 * ordenando uma copia do historico por codigo de
 * rastreio ou valor, sem alterar os dados originais (RF11).
 */
void gerar_relatorio(Historico *h, int criterio, int algoritmo);


/*
 * Funcao: comparar_algoritmos
 * Complexidade Temporal: O(n^2) pior caso
 * Descricao: Compara o desempenho do Insertion Sort e
 * Merge Sort utilizando copias identicas dos pedidos,
 * contabilizando tempo, comparacoes e trocas para
 * N = 100, 1000 e 10000 elementos (RF12).
 */
void comparar_algoritmos(Historico *h);


/*
 * Funcao: carga_inicial
 * Complexidade Temporal: O(p^2 + pq + q log q) pior caso
 * Descricao: Cadastra automaticamente pontos de entrega
 * e pedidos aleatorios na BST e no Heap para testes
 * de estresse (RF13).
 */
void carga_inicial(NoBST **raiz, Heap *heap, int qtd_pontos, int qtd_pedidos);


#endif