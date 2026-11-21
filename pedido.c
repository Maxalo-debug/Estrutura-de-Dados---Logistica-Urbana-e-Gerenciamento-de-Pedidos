# include <stdio.h>
#include <stdlib.h>
#include  "auxiliares.h"
#include <stdbool.h>
#include <string.h>
#include  "heap.h"
//
// Created by matheus on 11/20/26.
//
void menu(Heap** heap){

    PedidoEntrega* lista = malloc(sizeof(PedidoEntrega));
    if(!lista) exit(1);
    char answer[50] = "";
    while (true) {
        printf("Deseja continua?(s/n)");
        fgets(answer, 50, stdin);
        if(strcmp(answer, "s")==0) {
            continue;
        }else {
            break;
        }
    }
}


PedidoEntrega* getPedido(){
    PedidoEntrega* pedido = malloc(sizeof(PedidoEntrega));
    if(!pedido) return NULL;

    pedido->cod_rastreio = getInput("Digite codigo de rastreio:");
    pedido->prioridade = getInput("Digite a prioridade");
    printf("Ordem de chegada:");
    unsigned long ordemChegada = 0;
    scanf("%lu", &ordemChegada);
    getchar();
    pedido->ordem_chegada = ordemChegada;
    pedido->peso = getInputFloat("Digite peso:");
    pedido->id_destino = getInput("Digite id de destino:");
    pedido->valor = getInputFloat("Digite valor:");

    return pedido;
}

int getInput(char* prompt){
    int valor = 0;
    do {
        printf("%s", prompt);
        scanf("%d", &valor);
        getchar();
    }while (valor < 1 || valor > 3);

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
    printf("Prioridade - %-10d\n", p->prioridade);
    printf("Ordem de chamada - %-10lu\n", p->ordem_chegada);
    printf("Peso - %-10f\n", p->peso);
    printf("Id de destino - %-10d\n", p->id_destino);
    printf("Valor - %-10f\n", p->valor);
}