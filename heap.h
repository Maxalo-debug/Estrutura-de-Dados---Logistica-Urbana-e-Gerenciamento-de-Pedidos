#ifndef HEAP_H
#define HEAP_H

#include "entidades.h"
#include "historico.h"

/*
 * Estrutura: Heap
 * Descricao: Fila de prioridade implementada como Heap Maximo em vetor
 * alocado dinamicamente. A maior prioridade logica (1 = Expressa) fica na raiz,
 * com desempate FIFO pelo menor valor de ordem_chegada.
 */
typedef struct {
    PedidoEntrega *dados;
    int tamanho;
    int capacidade;
} Heap;


/*
* Funcao: inicializar_heap
 * Complexidade Temporal: O(1) pior caso
 * Justificativa: Executa apenas uma alocacao dinamica (malloc) e atribuicoes
 * diretas de tamanho e capacidade.
 * Descricao: Inicializa o Heap com tamanho zero e aloca dinamicamente o vetor de pedidos conforme a capacidade informada
 * Retorna 1 em caso de sucesso ou 0 em caso de falha na alocacao.
*/
int inicializar_heap(Heap* heap, int capacidade);




/*
* Função: liberar_heap
* Complexidade Temporal: O(1) pior caso
* Descrição: Libera a memoria alocada dinamicamente
* para o vetor de pedidos do Heap, evitando
* vazamentos de memoria.
*/
  
void liberar_heap(Heap* heap);/*
* Função: inserir_pedido
* Complexidade Temporal: O(log n) pior caso
* Descrição: Insere um novo pedido no Heap, reorganizando
* os elementos para manter a propriedade de prioridade.
*/
void inserir_pedido(Heap* heap, PedidoEntrega pedido);


/*
* Função: consultar_pedido
* Complexidade Temporal: O(1) pior caso
* Descricao: Consulta o pedido de maior prioridade,
* localizado na raiz do Heap, sem remove-lo.
* Retorna um ponteiro para o pedido ou NULL caso o Heap esteja vazio.
*/
PedidoEntrega* consultar_pedido(Heap* heap);


/*
* Função: remover_pedido
* Complexidade Temporal: O(log n) pior caso
* Descrição: Remove o pedido de maior prioridade da raiz
* do Heap e reorganiza os elementos restantes.
* Retorna o pedido removido.
*/


PedidoEntrega* remover_pedido(Heap* heap);


/*
* Função: exibir_pedidos
* Complexidade Temporal: O(n) pior caso
* Descrição: Percorre e exibe todos os pedidos pendentes
* armazenados no Heap, considerando sua estrutura interna.
*/
void exibir_pedidos(Heap* heap);

/*
* Função: registrar_remocao_historico
* Complexidade Temporal: O(log n) pior caso,
* considerando inserção O(1) no histórico.
* Descrição: Remove o pedido de maior prioridade do Heap, reorganiza os elementos restantes e
* registra o pedido removido na lista encadeada
* do histórico de operações.
*/



#endif