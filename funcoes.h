/**
 * @file funcoes.c
 * @author Joel Jonassi
 * @brief Smart City - Biblioteca
 * @version 0.1
 * @date 2021-12-17
 * @copyright Copyright (c) 2021
 */

#ifndef PI_REPOSITORY_FUNCOES_H
#define PI_REPOSITORY_FUNCOES_H

typedef enum {Trotinete, Bicicleta, Carro} TIPO;
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

/**
 * Guardar dados dos Meios Elétricos
 * @param nomeFicheiro
 * @param v
 */
int guardar_meio_Transporte(const char *nomeFicheiro, MeioEletrico *v);
int guardar_pedidos(const char *nomeFicheiro, Pedido v[]);
void viewFileFirst(MeioEletrico *array,int n);
void viewFileSecond(Pedido *array,int n);



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
