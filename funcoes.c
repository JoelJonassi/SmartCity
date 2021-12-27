/**
 * Falta a alinea 10 e 11
 * @file funcoes.c
 * @author Joel Jonassi
 * @brief Smart City - implementation of functions
 * @version 0.1
 * @date 2021-12-17
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

/**Alinea 1
 * Lê os ficheiros os dados dos pedidos
 * @param nomeFicheiro = 1.Pedidos.txt
 * @param v
 * @return
 */
int ler_pedidos(const char *nomeFicheiro, Pedido v[])
{
    FILE *af;
    int tot = 0;
    af = fopen(nomeFicheiro, "r");
    if (af == NULL)
        perror("Error");
    else
    {
        int i = 0;
        while (fscanf(af, " %d %d %s %d %d\n", &v[i].nr_ordem, &v[i].nif, v[i].codigo, &v[i].tempo, &v[i].distancia) != EOF)
        {
            if(v[i].nr_ordem != 0)
            {
                i++;
                tot = i;
            }


        }
    }
    fclose(af);
    return  tot;
}
/**Auxiliar da alinea 9
 * Para Calculo
 * Converter a virgula num ponto
 * @param string
 * @param caraterAntigo
 * @param caraterNovo
 */
void mudarCarater(char custo[], char caraterAntigo, char caraterNovo)
{
    int slen = strlen(custo);
    for(int i = 0; i < slen; i++)
        if(custo[i] == caraterAntigo)custo[i] = caraterNovo;
}


 /**
  * Alinea 2
  * Lê os ficheiros e guarda os dados dos meios de transporte
  * @param nomeFicheiro = 2- TipoTransporte
  * @param v
  * @return
  */
int ler_meio_Transporte(const char *nomeFicheiro, MeioEletrico v[])
{
    FILE *af;
    int tot = 0;
    af = fopen(nomeFicheiro, "r");
    if (af == NULL)
        perror("Error");
    else
    {
        int i = 0;
        while (fscanf(af, "%s %s %s %d\n", v[i].codigo, v[i].tipo, v[i].custo, &v[i].autonomia) != EOF)
        {
            mudarCarater(v[i].custo,',','.'); // Atera a virgula para ponto - Falta criar uma função para reverter o processo

            i++;
            tot = i;
        }
    }
    fclose(af);
    return  tot;
}


/**
 * Auxiliar da alinea 9
 * Para Calculo
 * Converter o custo num float
 * @param string
 * @return
 */
float stringToFloat(char string[]){
    float custo = atof(string);
    return custo;
}

/**Auxiliar da alinea 9
 * Para Calculo
 * Convert float em string de modo a guardar no ficheiro
 * @param string
 * @param n_digit
 */
void floatToString(float number, char* buffer){
    gcvt(number, 30, buffer);
}

/**
 * Armazenamento dos pedidos de utilização em ficheiro
 *Alinea 12
 * @param pedido
 * @param quantidadeAtletas
 */
void guardar_pedidos(Pedido v[], const char *nomeFicheiro, int *n)
{
    //%d %d %s %d %d
    FILE* fp;
    fp = fopen(nomeFicheiro,"w");   // "wt" write text  "rt" read text  "at" append
    if (fp == NULL)
        perror("Error");
    else {
        for (int i = 0; i < *n; i++) {
            fprintf(fp, "%d %d %s %d %d\n", v[i].nr_ordem, v[i].nif, v[i].codigo, v[i].tempo, v[i].distancia);
            //        fprintf(fp, "%[^]", pedido[i].codigo);
            //        fprintf(fp, "%d", pedido[i].distancia);
            //        fprintf(fp, "%d", pedido[i].nr_ordem);
            //        fprintf(fp, "%d", pedido[i].nif);
            //        fprintf(fp, "%d\n", pedido[i].tempo);
        }
    }
    fclose(fp);
}

/**Alinea 13
 *Armazenamento dos meios de mobilidade elétrica em ficheiro
 * @param c
 * @param quantidadeAtletas
 */
void guardar_meio_Transporte(MeioEletrico v[],const char *nomeFicheiro, int *n)
{
    FILE* fp;
    fp = fopen(nomeFicheiro,"w");   // "wt" write text  "rt" read text  "at" append
    for(int i = 0; i < *n; i++)
    {
        fprintf(fp, "%s %s %s %d\n", v[i].codigo, v[i].tipo, v[i].custo, v[i].autonomia);
        ///mudarCarater(transporte[i].custo,".",",");
//        fprintf(fp, "%s", transporte[i].codigo);
//        fprintf(fp, "%s", transporte[i].tipo);
//        fprintf(fp, "%s", transporte[i].custo);
//        fprintf(fp, "%d\n", transporte[i].autonomia);
    }
    fclose(fp);
}

/**Alinea
 *Armazenamento atribuição dos meios de mobilidade elétrica aos repectivos utilizadores de acordo com os pedidos em ficheiro
 * @param c
 * @param quantidadeAtletas
 */
void guardar_atribuicao(MeioEletrico v[], Pedido p[], const char *nomeFicheiro, int *n)
{
    FILE* fp;
    fp = fopen(nomeFicheiro,"w");   // "wt" write text  "rt" read text  "at" append
    for(int i = 0; i < *n; i++)
    {
        if( strcmp(v[i].codigo, p[i].codigo) == 0)
        {
            fprintf(fp, "%s %s %s %d\n", p[i].nr_ordem, p[i].nif, v[i].codigo, v[i].tipo, v[i].custo, v[i].autonomia);
            ///mudarCarater(transporte[i].custo,".",",");
//          fprintf(fp, "%s", transporte[i].codigo);
//          fprintf(fp, "%s", transporte[i].tipo);
//          fprintf(fp, "%s", transporte[i].custo);
//           fprintf(fp, "%d\n", transporte[i].autonomia);
        }
    }
    fclose(fp);
}

/**
 * Alenea 7
 * Listagem dos dados de todos os meios de mobilidade elétrica
 * Visualizar os dados dos meios eletricos
 * @param v
 * @param n
 */
void viewFileFirst(MeioEletrico *v, int *n){
    for(int i = 0; i < *n; i++){
        printf("%s %s %s %d\n", v[i].codigo,v[i].tipo,v[i].custo, v[i].autonomia);
    }
}

/**
 * Alinea 8
 * Listagem de todos os pedidos de utilização
 * Visualizar os dados dos pedidos
 * @param v
 * @param n
 */
void viewFileSecond(Pedido *v, int *n)
{
    for(int i = 0; i < *n; i++){
        printf("%d %d %s %d %d\n", v[i].nr_ordem, v[i].nif, v[i].codigo, v[i].tempo, v[i].distancia);
    }
}

/**
 * // Determinar se existe um transporte com código 'cod' no array transporte
// Devolve o índice do registo com a informação do transporte se existir
// Devolve -1 se não existir
 * @param transporte
 * @param cod
 * @param aut
 * @return
 */
int existeTransporte(MeioEletrico transporte[], char cod[4], int aut)
{
    int i=0;
    while (i != 1)
    {
        if (transporte[i].codigo == cod && transporte[i].autonomia == aut) {//Analisar
            i++;
            return (i);
        }
    return(-1);
    }
}

/**
 *
 * @param transporte
 * @param pedido
 * @param nif
 * @param cod
 * @param aut
 * @return
 */
int existePedido(MeioEletrico transporte[], Pedido pedido[], int nif, char cod[4], int aut)
{
    int i=0;
    while (i != 1) {
        if ((transporte[i].codigo == cod && transporte[i].autonomia == aut) && (pedido[i].nif == nif))
        {
            i++;
            return (i);
        }
        return(-1);
    }
}

 /**
  * Alinea 3
  * Função para inserção de um novo transporte no array transporte
  * devolvendo como resultado 1 em caso de sucesso e 0 em caso de insucesso
  * @param transporte
  * @param n
  * @param codigo
  * @param tipo
  * @param custo
  * @param autonomia
  * @return
  */
int inserirMeioElectrico(MeioEletrico transporte[], char codigo[4], char tipo[4], char custo[5], int autonomia, int *n)
{
    if (existeTransporte(transporte,codigo,autonomia)==-1)
    {
        strcpy(transporte[*n].codigo, codigo);
        strcpy(transporte[*n].tipo, tipo);
        strcpy(transporte[*n].custo, custo);
        transporte[*n].autonomia = autonomia;
        *n = *n + 1;
        return(1);
    }
    else
        return(0);
}


 /**
  * Alinea 4 - Por analiar
  * Remoção de um meio de mobilidade elétrica a partir do seu código
  * @param transporte
  * @param cod
  * @param n
  * @return
  */
int removerTransporte(MeioEletrico transporte[], char *cod, int *n){
    int i, j;
    for( i = 0; i < *n; i++){
        if (strcmp(transporte[i].codigo, cod)==0){
            for( j = i; j < *n-1; j++){
                transporte[j] = transporte[j+1];
            }
            *n-=1;
            return 1;
        }

    }
    return -1;
}

/**
 *
 */
 /**
  * Alinea 3
  * Função para inserção de um pedido de utilização de um meio electrico no array pedido
  * devolvendo como resultado 1 em caso de sucesso e 0 em caso de insucesso
  * @param pedido
  * @param transporte
  * @param n
  * @param nr_ordem
  * @param nif
  * @param codigo
  * @param tempo
  * @param distancia
  * @return
  */
int inserirPedidoUtiliz(Pedido pedido[], MeioEletrico transporte[], int nr_ordem, int nif, char codigo[4], int tempo, int distancia, int *n)
{
    int i = 1;
    if (existePedido(transporte, pedido,nif, codigo, transporte[1].autonomia) == -1)
    {
        strcpy(pedido[*n].codigo, codigo);
        pedido[*n].nr_ordem= nr_ordem;
        pedido[*n].nif= nif;
        pedido[*n].distancia= distancia;
        pedido[*n].tempo= tempo;
        *n = *n + 1;
        return(1);
    }
    else
        return(0);
}


/**
 * Alinea 6
 * Remoção de um pedido de utilização a partir do seu código;
 * @param pedido
 * @param nr_ordem
 * @param n
 * @return
 */
int removerPedido(Pedido pedido[], int nr_ordem, int *n){
    int i, j;
    for(i = 0; i < *n; i++){
        if (pedido[i].nr_ordem == nr_ordem){
            for( j = i; j < *n-1; j++)
                pedido[j] = pedido[j+1];
            *n-=1;
            return 1;
        }
    }
    return -1;
}

/**
 * Alinea 9
 * Cálculo do custo associado a um pedido de utilização a partir da indicação do seu número de ordem
 * @param transporte
 * @param pedido
 * @param nr_ordem
 * @param n
 * @return
 */
float custUtiliz(MeioEletrico transporte[], Pedido pedido[], int nr_ordem, int *utilizador, char tipo[], int *n){
   float custo = 0;
   float aux = 0;
    for(int i = 0; i < *n; i++)
    {
        if ((pedido[i].nr_ordem == nr_ordem))
        {
            mudarCarater(transporte[i].custo,',','.');
            custo = stringToFloat(transporte[i].custo);
            aux = (float) pedido[i].distancia * custo; //Converter o char custo em float
            *utilizador = pedido[i].nif;
            strcpy(tipo,transporte[i].tipo);
            return aux;
        }
    }
    return -1;

}


/** Opcional "Melhorar no final"
 * // Apresentação do menu e leitura da opcao escolhida
 * @return
 */
int menu()
{
    int opcao;
    do { printf("M E N U\n");
        printf("1 - Inserir Meio de Mobilidae\n");
        printf("2 - Consultar Meio De Mobilidade\n");
        printf("3 - Listar Mobilidade\n"); //
        printf("4 - Listar Pedidos\n");
        printf("5 - Remover Pedidos\n");
        printf("6 - Guardar\n");
        printf("7 - Ordenar pelo Ordenar crescente\n");
        printf("8 - Ordenar pelo Ordenar decrescente\n");
        printf("9 - Guardar em ficheiro\n");
        printf("10 - Ler\n");
        printf("0 - Sair\n");
        printf("Opcao?");
        scanf("%d",&opcao);
    }
    while ((opcao<0)||(opcao>10));
    return(opcao);
}
