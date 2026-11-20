# include <stdio.h>
#include <stdlib.h>
#include  "auxiliares.h"
#include  "library.h"
//
// Created by matheus on 11/20/26.
//
void menu(){
    PedidoEntrega* lista = malloc(sizeof(PedidoEntrega));
    if(!lista) exit(1);


}


PedidoEntrega* getPedido(){
    PedidoEntrega* pedido = malloc(sizeof(PedidoEntrega));
    if(!pedido) return NULL;

    pedido->cod_rastreio = getInput("Digite codigo de rastreio:");
    pedido->prioridade = getInput("Digite a prioridade");
    printf("Ordem de chegada:");
    scanf("%u", &pedido->ordem_chegada);
    getchar();
    pedido->peso = getInputFloat("Digite peso:");
    pedido->id_destino = getInput("Digite id de destino:");

}

int getInput(char* prompt){
    int valor = 0;
    printf("%s", prompt);
    scanf("%d", &valor);
    getchar();

    return valor;
}

float getInputFloat(char* prompt){
    float valor = 0;
    printf("%s", prompt);
    scanf("%f", &valor);
    getchar();
    return valor;
}

void mostrar_pedido(PedidoEntrega* p){
    printf("Codigo de rastreio - %-10d\n", p->cod_rastreio);
    printf("Prioridade - %-10d\n", p->cod_rastreio);
    printf("Ordem de chamada - %-10u\n", p->cod_rastreio);
    printf("Peso - %-10f\n", p->cod_rastreio);
    printf("Id de destino - %-10d\n", p->cod_rastreio);
    printf("Valor - %-10f\n", p->valor);
}