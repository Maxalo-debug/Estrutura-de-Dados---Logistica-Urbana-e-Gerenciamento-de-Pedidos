# include <stdio.h>
#include <stdlib.h>
#include  "pedido.h"
#include <stdbool.h>
#include <string.h>
#include  "heap.h"
//
// Created by matheus on 11/20/26.
//

void menu(Heap** heap){
    printf("=========================================\n");
    printf("        GERENCIAMENTO DE PEDIDOS\n");
    printf("=========================================\n");
    printf("1 - Cadastrar pedido\n");
    printf("2 - Consultar proximo pedido\n");
    printf("3 - Processar despacho pedido\n");
    printf("4 - Listar pedidos pendentes\n");
    printf("0 - Sair\n");
    printf("-----------------------------------------\n");
    while (true) {
        int option = getInput("Escolha uma opção:", 0, 4);
        switch(option) {
            case 0:
                liberar_heap(heap);
                exit(0);
            case 1: {
                PedidoEntrega* pedido = getPedido();
                inserir_pedido(*heap, *pedido);
                int size = (*heap)->tamanho + 1;
                PedidoEntrega* temp = realloc((*heap)->dados, size * sizeof(PedidoEntrega));
                if (temp == NULL) {
                    printf("Falha em realocar");
                    exit(1);
                }
                (*heap)->dados = temp;
                break;
            }
            case 2: {
                PedidoEntrega* pedido_maior_prioridade = consultar_pedido(*heap);
                mostrar_pedido(pedido_maior_prioridade);
                break;
            }
            case 3: {
                PedidoEntrega* pedido_removido = malloc(sizeof(PedidoEntrega));
                if (pedido_removido == NULL) {
                    printf("Falha em realocar");
                    break;
                }
                bool isRemoved = remover_pedido(*heap, pedido_removido);
                if (isRemoved == 1) {
                    printf("SEM ITEMS PENDENTES\n");
                    break;
                }
                //printf("Pedido %d removido:\n", pedido_removido->cod_rastreio);

                mostrar_pedido(pedido_removido);
                break;
            }
            case 4: {
                exibir_pedidos(*heap);
                break;
            }

        }
    }
}


PedidoEntrega* getPedido(){
    PedidoEntrega* pedido = malloc(sizeof(PedidoEntrega));
    if(!pedido) return NULL;

    pedido->cod_rastreio = getInput("Digite codigo de rastreio:", 1, 100000);
    pedido->prioridade = getInput("Digite a prioridade", 1, 3);
    printf("Ordem de chegada:");
    unsigned long ordemChegada = 0;
    scanf("%lu", &ordemChegada);
    getchar();
    pedido->ordem_chegada = ordemChegada;
    pedido->peso = getInputFloat("Digite peso:");
    pedido->id_destino = getInput("Digite id de destino:", 1, 100000);
    pedido->valor = getInputFloat("Digite valor:");

    return pedido;
}

int getInput(char* prompt, int lim_inferior, int lim_superior){
    int valor = 0;
    do {
        printf("%s", prompt);
        scanf("%d", &valor);
        getchar();
    }while (valor < lim_inferior || valor > lim_superior);

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

    printf("-----------------------------------------------\n");
    printf("                Dados do pedido:\n");
    printf("-----------------------------------------------\n");
    printf("%-22s -|%d\n", "Codigo de rastreio", p->cod_rastreio);
    printf("%-22s -|%d\n", "Prioridade", p->prioridade);
    printf("%-22s -|%lu\n", "Ordem de chamada", p->ordem_chegada);
    printf("%-22s -|%.2f\n", "Peso", p->peso);
    printf("%-22s -|%d\n", "Id de destino", p->id_destino);
    printf("%-22s -|%.2f\n", "Valor", p->valor);
    printf("-----------------------------------------------\n");
}