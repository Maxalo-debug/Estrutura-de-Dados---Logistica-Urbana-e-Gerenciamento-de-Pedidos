#include "entidades.h"
#include  "heap.h"
#include <stdio.h>
#include <stdlib.h>


void inserir_pedido(Heap* heap, PedidoEntrega pedido) {

    int i = heap->tamanho;

    heap->tamanho++;
    heap->dados[i] = pedido;

    int pai = (i - 1) / 2;
}


int inicializar_heap(Heap* heap, int capacidade){
    heap->capacidade = capacidade;
    heap->dados = malloc(sizeof(PedidoEntrega));
    heap->tamanho = 0;

}

int liberar_heap(Heap** heap){
    if(*heap == NULL || heap == NULL) return 1;
    free((*heap)->dados);
    free(heap);

    *heap = NULL;
    return 0;
}

PedidoEntrega* consultar_pedido(Heap* heap){
    PedidoEntrega* pedido = &heap->dados[0];
    return pedido;

}
PedidoEntrega* remover_pedido(Heap* heap){

}

void exibir_pedidos(Heap* heap){

}