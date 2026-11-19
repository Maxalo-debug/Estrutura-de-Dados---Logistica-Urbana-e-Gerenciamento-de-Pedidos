#include "library.h"
#include <stdio.h>
#include <stdlib.h>


void inserir_pedido(Heap* heap, Pedido pedido) {

    int i = heap->current_size;

    heap->current_size++;
    heap->pedidos[i] = pedido;

    int pai = (i - 1) / 2;
    if (pai)
}