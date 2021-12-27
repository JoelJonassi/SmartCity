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
    struct _etapa *next;
} Pedido;

typedef struct _meio_eletrico
{
    char codigo[5];
    char tipo[10];
    char custo[4];
    int autonomia;
} MeioEletrico;

typedef struct _plano{
    struct _meio_eletrico transporte;
    struct _pedido pedido;
    int tempInicial;
    int tempFinal;
}Plano;


int ler_meio_Transporte(const char *nomeFicheiro, MeioEletrico *v);
int ler_pedidos(const char *nomeFicheiro, Pedido v[]);
void guardar_meio_Transporte(MeioEletrico transporte[],const char *nomeFicheiro, int *n);
void guardar_pedidos(Pedido pedido[], const char *nomeFicheiro, int *n);
void viewFileFirst(MeioEletrico *array,int *n);
void viewFileSecond(Pedido *array,int *n);
int existePedido(MeioEletrico transporte[], Pedido pedido[], int nif, char *cod, int aut);
int existeTransporte(MeioEletrico transporte[], char *cod, int aut);
int inserirMeioElectrico(MeioEletrico transporte[], char *codigo, char tipo[4], char custo[5], int autonomia, int *n);
float custUtiliz(MeioEletrico transporte[], Pedido pedido[], int nr_ordem, int *utilizador, char tipo[], int *n);
int inserirPedidoUtiliz(Pedido pedido[],MeioEletrico transporte[], int nr_ordem, int nif, char codigo[4], int tempo, int distancia, int *n);
int removerPedido(Pedido pedido[], int nr_ordem, int *n);
int removerTransporte(MeioEletrico transporte[], char *cod, int *n);
void mudarCarater(char custo[], char caraterAntigo, char caraterNovo);
int menu();

/*
void apresentar_concorrentes(Piloto *lista);
extern void apresentConcorrentes(char *nomeFicheiro);
extern int distanciaEtapas(char *nomeFicheiro);
extern Piloto *provaValida(Etapa* etapas, Piloto *pilotos, int tempo, char *inicio, char *fim);
extern int rapidoLento(char *nomeFicheiro, int x, int *v, int s);
Etapa *guardar_etapa(Etapa *todas_etapas,int id, int tempo, char *etapa_inicial,char *etapa_final, int distancia);
Prova *guardar_prova(Prova *todas_provas, int id, char *etapa, const int qt_etapa, const int n_concorrentes);
Piloto *guardar_piloto(Piloto *todos_pilotos, int id, char *nome, char *carro);
*/
#endif //PI_REPOSITORY_FUNCOES_H
