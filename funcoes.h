/**
 * @file funcoes.c
 * @author Joel Jonassi
 * @brief Smart City - Assinatura das funções
 * @version 0.1
 * @date 2021-12-17
 * @copyright Copyright (c) 2021
 */

#ifndef PI_REPOSITORY_FUNCOES_H
#define PI_REPOSITORY_FUNCOES_H


typedef struct _pedido
{
    int nr_ordem;
    int nif;
    char codigo[3];
    int distancia;
    int tempo;
} Pedido;

typedef struct _meio_eletrico
{
    char codigo[5];
    char tipo[10];
    char custo[4];
    int autonomia;
} MeioEletrico;

typedef struct _plano{
    char codigo[5];
    int nr_ordem;
    int nif;
    int tempInicial;
    int tempFinal;
    int autonomia;
}Plano;


int ler_meio_Transporte(const char *nomeFicheiro, MeioEletrico transporte[], int *n);
int ler_pedidos(const char *nomeFicheiro, Pedido v[], int *n);
int guardar_meio_Transporte(MeioEletrico transporte[],const char *nomeFicheiro, int *n);
int guardar_pedidos(Pedido pedido[], const char *nomeFicheiro, int *n);
void ordenarNrOrdem(Pedido Pedidos[], int *n);
void listarPlano(Plano plano[], char codigo[], int *totPlano);
void listarTransportes(MeioEletrico *v, int *n);
void listarPedidos(Pedido *v, int *n);
void distribMeiosMobili(Plano plano[], MeioEletrico transporte[], Pedido pedido[], int *totTransporte, int *totPedido);
int existePedido(MeioEletrico transporte[], Pedido pedido[], int nif, char *cod, int aut);
int existeTransporte(MeioEletrico transporte[], char *cod, int aut, char tipo[5]);
int inserirMeioElectrico(MeioEletrico transporte[], char *codigo, char tipo[4], char custo[5], int autonomia, int *n);
float custUtiliz(MeioEletrico transporte[], Pedido pedido[], int nr_ordem, int *totTransporte, int *totPedido);
int inserirPedidoUtiliz(Pedido pedido[],MeioEletrico transporte[], int nr_ordem, int nif, char codigo[4], int tempo, int distancia, int *n);
int removerPedido(Pedido pedido[], int nr_ordem, int *n);
int removerTransporte(MeioEletrico transporte[], char *cod, int *n);
void mudarCarater(char custo[], char caraterAntigo, char caraterNovo);
void floatToString(float number, char* buffer);
int menu();
void limparTela();

#endif //PI_REPOSITORY_FUNCOES_H
