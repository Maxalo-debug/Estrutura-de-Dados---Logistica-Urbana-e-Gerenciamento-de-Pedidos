#pragma once
#include "heap.h"

float getInputFloat(char* prompt);
PedidoEntrega* getPedido();
void menu(Heap** heap);
int getInput(char* prompt, int lim_inferior, int lim_superior);
float getInputFloat(char* prompt);
void mostrar_pedido(PedidoEntrega* p);
