#ifndef ENTIDADES_H
#define ENTIDADES_H

/*
 * Estrutura: PedidoEntrega
 * Descricao: Representa um pacote a ser despachado pela central.
 * Campos:
 *   - cod_rastreio: Identificador unico do pedido (definido como int).
 *   - prioridade: Classificacao (1 = Expressa, 2 = VIP, 3 = Convencional).
 *   - ordem_chegada: Contador incremental para garantir desempate FIFO.
 *   - peso: Peso do pacote em quilos.
 *   - id_destino: Codigo do ponto de entrega cadastrado na BST.
 *   - valor: Valor monetario associado ao pedido.
 */

typedef struct Pedido{
    int cod_rastreio;
    int prioridade;
    unsigned long ordem_chegada;
    float peso;
    int id_destino;
    float valor;
}PedidoEntrega;


/*
 * Estrutura: PontoEntrega
 * Descricao: Representa um local de destino das encomendas na cidade.
 * Campos:
 *   - id_ponto: Codigo unico de identificacao do ponto.
 *   - nome_local: Nome do bairro ou localidade.
 *   - latitude: Coordenada geografica (latitude).
 *   - longitude: Coordenada geografica (longitude).
 */
typedef struct Entrega{
    int id_ponto;
    char nome_local[100];
    float latitude;
    float longitude;
}PontoEntrega;


#endif