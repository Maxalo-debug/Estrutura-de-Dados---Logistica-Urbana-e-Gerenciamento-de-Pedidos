#include "entidades.h"
#include  "heap.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


void inserir_pedido(Heap* heap, PedidoEntrega pedido) {

    heap->tamanho++;
    int i = heap->tamanho - 1;
    heap->dados[i] = pedido;

    int pai = 0;
    while (i > 0) {
        pai = (i -1)/2;
        if (heap->dados[i].prioridade > heap->dados[pai].prioridade) {
            PedidoEntrega temp = heap->dados[pai];
            heap->dados[pai] = pedido;
            heap->dados[i] = temp;
            i = pai;
            continue;
        }
        if (heap->dados[i].prioridade == heap->dados[pai].prioridade) {
            if (pedido.ordem_chegada < heap->dados[pai].ordem_chegada) {
                PedidoEntrega temp = heap->dados[pai];
                heap->dados[pai] = heap->dados[i];
                heap->dados[i] = temp;
                i = pai;
                continue;
            }

        }
        break;
    }
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
    if (heap->tamanho == 0) return NULL;

    return &heap->dados[0];;

}
PedidoEntrega* remover_pedido(Heap* heap){
    if (heap->tamanho == 0) return NULL;

    PedidoEntrega pedido = heap->dados[0];
    heap->dados[0] = heap->dados[heap->tamanho - 1];
    heap->tamanho--;
    int i = 0;

    while (true) {
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;
        int maior = i;

        if (esq < heap->tamanho && heap->dados[esq].prioridade > heap->dados[maior].prioridade) {
            maior = esq;
        }

        if (dir < heap->tamanho && heap->dados[dir].prioridade > heap->dados[maior].prioridade ) {
            maior = dir;
        }

        if (maior == i) {
            break;
        }
        PedidoEntrega temp = heap->dados[maior];
        heap->dados[maior] = heap->dados[i];
        heap->dados[i] = temp;
    }



    return &pedido;
}

void exibir_pedidos(Heap* heap){

}