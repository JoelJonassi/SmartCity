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
#define TAMANHO 200

int main()
{

    //Variáveis
    MeioEletrico transportes[TAMANHO];
    Pedido  pedidos[TAMANHO];
    Plano planos[TAMANHO];
    int totTransporte, totPedido, totPlano, opcao, autonomia, distancia, nr_ordem, nif, tempo, res;
    char codigo[5], tipo[10], custoStr[5];
    float custoFloat;

    do
    {
        fflush(stdin);
        opcao = menu();

        switch(opcao)
        {case 1:
                res = ler_pedidos("1-Pedidos.txt", pedidos, &totPedido);
                guardar_pedidos(pedidos, "1-Pedidos.txt", &totPedido);
                if (res==1) {
                    printf("Ficheiro lido com sucesso!\n");
                }
                else printf("Falha na leitura do ficheiro!\n");
                break;
            case 2:
                res = ler_meio_Transporte("2-TipoTransporte.txt", transportes, &totTransporte);
                guardar_meio_Transporte(transportes, "2-TipoTransporte.txt", &totTransporte);
                if (res==1) {
                    printf("Ficheiro lido com sucesso!\n");
                }
                else printf("Falha na leitura do Ficheiro!\n");
                break;
            case 3:
                printf("Numero de Ordem? ");
                scanf("%d",&nr_ordem);
                printf("Numero de Identificacao Fiscal?");
                scanf("%d",&nif);
                printf("Codigo do Meio de Mobilidae?");
                scanf("%s", codigo);
                printf("Tempo?");
                scanf("%d",&tempo);
                printf("Distancia?");
                scanf("%d",&distancia);
                res = inserirPedidoUtiliz(pedidos, transportes, nr_ordem, nif, codigo, tempo, distancia, &totPedido);
                if (res==1) {
                    printf("Inserido com sucesso!\n");
                }
                else printf("Falha na Insercao!\n");
                break;
            case 4:

                printf("Codigo?");
                scanf("%s", codigo);
                printf("Tipo de Mobilidade?");
                scanf(" %[^\n]s",tipo);
                printf("Custo?");
                scanf("%s", custoStr);
                printf("Autonomia?");
                scanf(" %d", &autonomia);
                res = inserirMeioElectrico(transportes, codigo, tipo, custoStr, autonomia, &totTransporte);
                if (res==1) {
                    printf("Inserido com sucesso!\n");
                }
                else printf("Falha na Insercao!\n");
                break;
            case 5:
                printf("Indicar o numero de ordem do Pedido: ");
                scanf("%d", &nr_ordem);
                res = removerPedido(pedidos, nr_ordem, &totPedido);
                if (res==1) {
                    printf("Removido com sucesso!");
                }
                else printf("Não removido!");
                break;
            case 6:printf("Indicar o Codigo do Meio de Mobilidade: ");
                scanf("%s", codigo);
                res = removerTransporte(transportes, codigo, &totTransporte);
                if (res==1) {
                    printf("Removido com sucesso!\n");
                }
                else printf("Nao removido!\n");
                break;
            case 7:
                listarTransportes(transportes, &totTransporte);
                break;

            case 8:
                listarPedidos(pedidos, &totPedido);
                break;
            case 9:
                printf("Insira o codigo do Meio de Mobilidade: ");
                scanf("%s", codigo);
                listarPlano(planos, codigo, &totPedido);
                break;
            case 10:
                res = guardar_pedidos(pedidos, "C:\\Users\\Asus\\CLionProjects\\ESI_PI_19698 - REPO\\pi_repository\\1-Pedidos.txt", &totPedido);
                if (res==1) {
                    printf("Pedidos de utilizacao Armazenados no Ficheiro!\n");
                }
                else printf("Falha no Armazenamento!\n");
                break;
            case 11:
                res = guardar_meio_Transporte(transportes, "C:\\Users\\Asus\\CLionProjects\\ESI_PI_19698 - REPO\\pi_repository\\2-TipoTransporte.txt", &totTransporte);
                if (res==1) {
                    printf("Meios de Mobilidade eletrica Armazenados no Ficheiro!\n");
                }
                else printf("Falha no Armazenamento!\n");
                break;
            case 12:
                printf("Insira o numero de ordem do Pedido: ");
                scanf("%d", &nr_ordem);
                custoFloat = custUtiliz(transportes , pedidos, nr_ordem, &totTransporte, &totPedido);
                printf("****Numero de ordem: %d -> preco: %f ******\n\n", nr_ordem, custoFloat);
                break;
            case 13:
                ordenarNrOrdem(pedidos, &totPedido);
                distribMeiosMobili(planos, transportes, pedidos, &totTransporte, &totPedido);
                break;
            case 14:
               limparTela();
        }

    } while (opcao !=0);


}


