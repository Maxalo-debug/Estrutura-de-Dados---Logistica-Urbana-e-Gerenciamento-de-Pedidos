
#ifndef HISTORICO_H
#define HISTORICO_H

#include "entidades.h"

/*
 * Estrutura: NoHistorico
 * Descricao: No da lista encadeada que armazena os dados
 * de um pedido processado e aponta para o proximo no.
 */
typedef struct NoHistorico {
    PedidoEntrega pedido;
    struct NoHistorico *proximo;
} NoHistorico;


/*
 * Estrutura: Historico
 * Descricao: Armazena os ponteiros para o inicio e o fim
 * da lista encadeada de pedidos processados.
 */
typedef struct {
    NoHistorico *inicio;
    NoHistorico *fim;
} Historico;


/*
 * Funcao: inicializar_historico
 * Complexidade Temporal: O(1) pior caso
 * Descricao: Inicializa o historico definindo os ponteiros
 * de inicio e fim como NULL.
 */
void inicializar_historico(Historico *h);


/*
 * Funcao: registrar_pedido
 * Complexidade Temporal: O(1) pior caso
 * Descricao: Aloca dinamicamente um novo no e registra
 * o pedido processado no final da lista (RF08).
 */
void registrar_pedido(Historico *h, PedidoEntrega pedido);


/*
 * Funcao: consultar_historico
 * Complexidade Temporal: O(n) pior caso
 * Descricao: Percorre a lista encadeada exibindo todos
 * os pedidos que ja foram processados (RF09).
 */
void consultar_historico(Historico *h);


/*
 * Funcao: buscar_pedido_historico
 * Complexidade Temporal: O(n) pior caso
 * Descricao: Localiza um pedido no historico a partir
 * do seu codigo de rastreio (RF10).
 * Retorna o ponteiro para o pedido encontrado ou NULL
 * caso nao exista.
 */
PedidoEntrega* buscar_pedido_historico(Historico *h, int cod_rastreio);


/*
 * Funcao: liberar_historico
 * Complexidade Temporal: O(n) pior caso
 * Descricao: Percorre a lista encadeada liberando toda
 * a memoria alocada dinamicamente para seus nos.
 */
void liberar_historico(Historico *h);


#endif