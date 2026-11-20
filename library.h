#pragma once
typedef struct Pedido{
    int cod_rastreio;
    int prioridade;
    unsigned long ordem_chegada;
    float peso;
    int id_destino;
    float valor;
}PedidoEntrega;

typedef struct {

    PedidoEntrega *dados;
    int tamanho;
    int capacidade;

} Heap;

typedef struct Entrega{
    int ponto;
    char nome_local[50];
    float latitude_longitude[2];
}Entrega;


/*
 * Funcao: inserir_pedido
 * Complexidade Temporal: O(log n) pior caso
 * Descricao: Insere um novo pedido no Heap, reorganizando
 * os elementos para manter a propriedade de prioridade.
 */
void inserir_pedido(Heap* heap, PedidoEntrega pedido);

/*
 * Funcao: consultar_pedido
 * Complexidade Temporal: O(1) pior caso
 * Descricao: Consulta o pedido de maior prioridade,
 * localizado na raiz do Heap, sem remove-lo.
 * Retorna um ponteiro para o pedido ou NULL caso o Heap esteja vazio.
 */
PedidoEntrega* consultar_pedido(Heap* heap);


/*
 * Funcao: remover_pedido
 * Complexidade Temporal: O(log n) pior caso
 * Descricao: Remove o pedido de maior prioridade da raiz
 * do Heap e reorganiza os elementos restantes.
 * Retorna o pedido removido.
 */
PedidoEntrega* remover_pedido(Heap* heap);

/*
 * Funcao: exibir_pedidos
 * Complexidade Temporal: O(n) pior caso
 * Descricao: Percorre e exibe todos os pedidos pendentes
 * armazenados no Heap, considerando sua estrutura interna.
 */
void exibir_pedidos(Heap* heap);

/*
 * Funcao: inicializar_heap
 * Complexidade Temporal: O(1) pior caso
 * Descricao: Inicializa o Heap, definindo seu tamanho
 * atual como zero e alocando dinamicamente o vetor
 * de pedidos conforme a capacidade informada.
 * Retorna 1 em caso de sucesso ou 0 em caso de
 * falha na alocacao.
 */
int inicializar_heap(Heap* heap, int capacidade);


/*
 * Funcao: liberar_heap
 * Complexidade Temporal: O(1) pior caso
 * Descricao: Libera a memoria alocada dinamicamente
 * para o vetor de pedidos do Heap, evitando
 * vazamentos de memoria.
 */

int liberar_heap(Heap** heap);



