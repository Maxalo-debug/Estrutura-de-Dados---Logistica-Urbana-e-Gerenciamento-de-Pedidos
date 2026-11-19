#pragma once
typedef struct Pedido{
    int cod_rastreio;
    int prioridade;
    unsigned long ordem_chegada;
    float peso;
    int id_destino;
    float valor;
}Pedido;

typedef struct heap {
    int current_size;
    int max_size;
    Pedido pedidos[1000];
}Heap;

typedef struct Entrega{
    int ponto;
    char nome_local[50];
    float latitude_longitude[2];
}Entrega;



void inserir_pedido(Heap* heap, Pedido pedido);