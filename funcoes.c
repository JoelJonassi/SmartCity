/**
 * @file funcoes.c
 * @author Joel Jonassi e Idelvina Fernando
 * @brief Smart City - implementation of functions
 * @version 0.1
 * @date 2021-12-17
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include <assert.h>

/**Alinea - 1
 * Lê os ficheiros os dados dos pedidos
 * @param nomeFicheiro = 1.Pedidos.txt
 * @param v
 * @return
 */
int guardar_pedidos(const char *nomeFicheiro, Pedido v[])
{
    FILE *af;
    int tot = 0;
    af = fopen(nomeFicheiro, "r");
    if (af == NULL)
        perror("Error");
    else
    {   int i = 0;
        while (fscanf(af, " %d %d %s %d %d\n", &v[i].nr_ordem, &v[i].nif, v[i].codigo, &v[i].tempo, &v[i].distancia) != EOF)
        {
            i++;
            tot = i;
        }
    }
    fclose(af);
    return  tot;
}

 /**
  * Alinea - 2
  * Lê os ficheiros e guarda os dados dos meios de transporte
  * @param nomeFicheiro = 2- TipoTransporte
  * @param v
  * @return
  */
int guardar_meio_Transporte(const char *nomeFicheiro, MeioEletrico v[])
{
    FILE *af;
    int tot = 0;
    af = fopen(nomeFicheiro, "r");
    if (af == NULL)
        perror("Error");
    else
    {   int i = 0;
        while (fscanf(af, "%s %s %s %d\n", v[i].codigo, v[i].tipo, v[i].custo, &v[i].autonomia) != EOF)
        {
            i++;
            tot = i;
        }
    }
    fclose(af);
    return  tot;
}



/**
 * Para Debug
 * Visualizar os dados dos meios eletricos
 * @param v
 * @param n
 */
void viewFileFirst(MeioEletrico *v, int n){
    for(int i = 0; i < n; i++){
        printf("%s %s %s %d\n", v[i].codigo,v[i].tipo,v[i].custo, v[i].autonomia);
    }
}

/**
 * Para Debug
 * Visualizar os dados dos pedidos
 * @param v
 * @param n
 */
void viewFileSecond(Pedido *v, int n){
    for(int i = 0; i < n; i++){
        printf("%d %d %s %d %d\n", v[i].nr_ordem, v[i].nif, v[i].codigo, v[i].tempo, v[i].distancia);
    }
}
