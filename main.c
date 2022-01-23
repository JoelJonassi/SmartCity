/**
 * Atulamente Serve Para Debug
 * @file funcoes.c
 * @author Joel Jonassi
 * @brief Smart City - main
 * @version 0.1
 * @date 2021-12-16
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


int main()
{
    //Variáveis
    MeioEletrico transporte[10];
    Pedido  pedido[10];
    Plano plano[10];
    int totTransporte, totPedido, totPlano;
    float a = 0;
    int b;

    //Leitura de ficheiros texto
    totTransporte = ler_meio_Transporte("C:\\Users\\Asus\\CLionProjects\\ESI_PI_19698 - REPO\\pi_repository\\2-TipoTransporte.txt", transporte);
    totPedido = ler_pedidos("C:\\Users\\Asus\\CLionProjects\\ESI_PI_19698 - REPO\\pi_repository\\1-Pedidos.txt", pedido);
    guardar_pedidos(pedido, "C:\\Users\\Asus\\CLionProjects\\ESI_PI_19698 - REPO\\pi_repository\\1-Pedidosv2.txt", &totPedido);
    guardar_meio_Transporte(transporte,"C:\\Users\\Asus\\CLionProjects\\ESI_PI_19698 - REPO\\pi_repository\\2-TipoTransportev2.txt", &totTransporte);

    //totPlano = ler_atribuicao("C:\\Users\\Asus\\CLionProjects\\ESI_PI_19698 - REPO\\pi_repository\\1-Atribuicao.txt", plano);
    guardar_atribuicao(plano, transporte, pedido, "C:\\Users\\Asus\\CLionProjects\\ESI_PI_19698 - REPO\\pi_repository\\1-Atribuicao.txt", 0, 250, &totPedido);
    printf("PPPPPPPPPPPPP: %d", plano[2].nr_ordem);
    //Listar transportes
    puts("---------------TRANSPORTES--------------");
    viewFileFirst(transporte, &totTransporte);
    //Listar pedidos
    puts("-----------------PEDIDOS-----------------");
    viewFileSecond(pedido,&totPedido);

    //Remover pedidos
    removerPedido(pedido, 6,&totPedido);
    removerPedido(pedido, 7,&totPedido);
    removerPedido(pedido, 1,&totPedido);

    //Remover transportes
    removerTransporte(transporte,"M_1",&totTransporte);
    removerTransporte(transporte,"M_4",&totTransporte);

    //Inserir novo meio de transporte
    puts("---------------------INSERIR PEDIDOS-------------------");
    inserirMeioElectrico(transporte,"M_7", "mota", "0,44", 66, &totTransporte);
    //Inserir novo pedido
    inserirPedidoUtiliz(pedido, transporte, 6, 287060357, "M_7", 33, 17, &totPedido);

    puts("---------------PEDIDOS NAO REMOVIDOS--------------");
    viewFileSecond(pedido,&totPedido);
    puts("---------------TRANSPORTES NAO REMOVIDOS--------------");
    viewFileFirst(transporte, &totTransporte);

    //Atualizar ficheiros os removidos, os não removidos, os novos inseridos ou seja guardar em ficheiros


    //Cálculo do custo associado a um pedido de utilização a partir da indicação do seu número de ordem
    //Criar um ciclo for para facilitar a listagem do custo associado ao pedido
    puts("------------CALCULO ASSOCIADO A UM PEDIDO DE UTILIZACAO--------------");
    int user;
    char tipo[15];
    a = custUtiliz(transporte ,pedido, 3, &user, tipo, &totTransporte);
    printf("custo: %f -> utilizador: %d -> tipo: %s", a, user, tipo);

    puts("--------------------Guardar informação em ficheiros------------------------");
    guardar_pedidos(pedido, "C:\\Users\\Asus\\CLionProjects\\ESI_PI_19698 - REPO\\pi_repository\\1-Pedidosv2.txt", &totPedido);
    //AO GUARDAR UM NUMERO COM PONTO MODIFICAR O PONTO PARA VIRGULA
    guardar_meio_Transporte(transporte,"C:\\Users\\Asus\\CLionProjects\\ESI_PI_19698 - REPO\\pi_repository\\2-TipoTransportev2.txt", &totTransporte);



}


