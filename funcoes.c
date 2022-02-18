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
int ler_pedidos(const char *nomeFicheiro, Pedido v[], int *n)
{
    FILE *af;
    af = fopen(nomeFicheiro, "a+"); //Abertura, escrita e acrescentar
    if (af == NULL) {
        perror("Error");
        return 0;
    }
    else
    {
        int i = 0;
        while (fscanf(af, " %d %d %s %d %d\n", &v[i].nr_ordem, &v[i].nif, v[i].codigo, &v[i].tempo, &v[i].distancia) != EOF)
        {
            if(v[i].nr_ordem != 0)
            {
                i++;
                *n = i;
            }
        }
    }
    fclose(af);
    return  1;
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
  * @param transporte
  * @return
  */
int ler_meio_Transporte(const char *nomeFicheiro, MeioEletrico transporte[], int *n)
{
    FILE *af;
    af = fopen(nomeFicheiro, "r+"); //lê e rescreve todo conteudo
    if (af == NULL) {
        perror("Error");
        return 0;
    }
    else
    {
        int i = 0;
        while (fscanf(af, "%s %s %s %d\n", transporte[i].codigo, transporte[i].tipo, transporte[i].custo, &transporte[i].autonomia) != EOF)
        {
            mudarCarater(transporte[i].custo, ',', '.'); // Atera a virgula para ponto - Falta criar uma função para reverter o processo

            i++;
            *n = i;
        }
    }
    fclose(af);
    return  1;
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
int guardar_pedidos(Pedido v[], const char *nomeFicheiro, int *n)
{
    FILE* fp;
    fp = fopen(nomeFicheiro,"w");   // le e reescreve todo conteudo
    if (fp == NULL) {
        perror("Error");
        return 0;
    }
    else {
        for (int i = 0; i < *n; i++) {
            fprintf(fp, "%d %d %s %d %d\n", v[i].nr_ordem, v[i].nif, v[i].codigo, v[i].tempo, v[i].distancia);
        }

    }
    fclose(fp);
    return 1;
}

/**Alinea 13
 *Armazenamento dos meios de mobilidade elétrica em ficheiro
 * @param c
 * @param quantidadeAtletas
 */
int guardar_meio_Transporte(MeioEletrico transporte[], const char *nomeFicheiro, int *n)
{
    FILE* fp;
    fp = fopen(nomeFicheiro,"w");
    if (fp == NULL) {
        perror("Error");
        return 0;
    }
    else {
        for (int i = 0; i < *n; i++) {
            fprintf(fp, "%s %s %s %d\n", transporte[i].codigo, transporte[i].tipo, transporte[i].custo,
                    transporte[i].autonomia);
            //mudarCarater(transporte[i].custo,".",",");
        }
    }
    fclose(fp);
    return 1;
}

// Ordenar por ordem crescente de número de ordem
void ordenarNrOrdem(Pedido Pedidos[], int *n) {
    Pedido aux;
    for (int i = 0; i < *n; i++)
        for (int j = i+1; j < *n; j++)
            if (Pedidos[i].nr_ordem > Pedidos[j].nr_ordem) {
                aux = Pedidos[i];
                Pedidos[i] = Pedidos[j];
                Pedidos[j] = aux;
            }
}
/**Alinea
 *Armazenamento atribuição dos meios de mobilidade elétrica aos repectivos utilizadores de acordo com os pedidos em ficheiro
 * @param c
 * @param quantidadeAtletas
 */
void distribMeiosMobili(Plano plano[], MeioEletrico transporte[], Pedido pedido[], int *totTransporte, int *totPedido)
{
    for(int j = 0; j < *totPedido; j++)
    {
        for(int i = 0; i < *totTransporte; i++) {
            if (strcmp(transporte[i].codigo, pedido[j].codigo) == 0 && transporte[i].autonomia >= pedido[j].distancia)
            {
                plano[j].nif = pedido[j].nif;
                plano[j].nr_ordem = pedido[j].nr_ordem;
                plano[j].autonomia = transporte[i].autonomia - pedido[j].distancia;
                transporte[i].autonomia = plano[j].autonomia;
                strcpy(plano[j].codigo, pedido[j].codigo);
                plano[j].tempInicial = 0;
                plano[j].tempFinal = 0;
            }
            else
                continue;
        }
    }
}

/**
 * Mostrar o plano
 * @param nomeFicheiro
 * @param plano
 * @param cod
 * @param totPlano
 * @return
 */
void listarPlano(Plano plano[], char codigo[], int *totPlano)
{
    for (int i = 0; i < *totPlano; i++)
    {
        if(strcmp(plano[i].codigo, codigo) == 0) {
            printf("    %d %d %d %d %d %s\n", plano[i].nr_ordem, plano[i].nif, plano[i].tempInicial,
                   plano[i].tempFinal, plano[i].autonomia, plano[i].codigo);

        }
    }
}



/**
 * Carregar o ficheiro e comfirmar os dados comparando o nif  e o transporte atribuido com outras estrututuras
 * Se ja tiver sido atribuido procurar outro e atribuir
 *
 * @param p
 * @param n
 * @return
 */
/*int inserir_atribuicao(Plano p[], int *n){
    for(int i = 0; i < *n; i++)
    {
        if( strcmp(p[i]., p[i].transporte.codigo) == 0)
        {
            fprintf(fp, "%d %d %d %d %d %s\n", p[i].pedido.nr_ordem, p[i].pedido.nif, p[i].tempInicial, p[i].tempFinal, p[i].transporte.autonomia, p[i].transporte.codigo);
        }
    }
}*/

/**
 * Alenea 7
 * Listagem dos dados de todos os meios de mobilidade elétrica
 * Visualizar os dados dos meios eletricos
 * @param v
 * @param n
 */
void listarTransportes(MeioEletrico *v, int *n){
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
void listarPedidos(Pedido *v, int *n)
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
int existeTransporte(MeioEletrico transporte[], char cod[4], int aut, char tipo[5])
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
    if (existeTransporte(transporte,codigo,autonomia, tipo)==-1)
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
    int aux = 0;
    for(int i = 0; i  < *n; i++){
        if (nr_ordem == pedido[i].nr_ordem)
            aux++;
    }
    if ((existePedido(transporte, pedido,nif, codigo, distancia) == -1) && (aux == 0))
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
float custUtiliz(MeioEletrico transporte[], Pedido pedido[], int nr_ordem, int *totTransporte, int *totPedido){
    float custo;
    float aux = 0;
    for(int i = 0; i < *totPedido; i++)
    {

        if (pedido[i].nr_ordem == nr_ordem)
        {

            for(int j = 0; j < *totTransporte; j ++) {
                if(strcmp(pedido[i].codigo,transporte[j].codigo) == 0) {
                    mudarCarater(transporte[j].custo, ',', '.');
                    custo = stringToFloat(transporte[j].custo);
                    aux = (float) pedido[i].distancia * custo; //Converter o char custo em float
                }
            }
            return aux;
        }
    }
    return -1;

}


/**
 * // Apresentação do menu e leitura da opcao escolhida
 * @return
 */
int menu()
{
    int opcao;
    do {
        printf("M E N U\n");
        printf("Ler Ficheiros\n");
        printf("    1 Pedidos\n");
        printf("    2 Meios de Mobilidade\n");
        printf("Inserir Dados\n");
        printf("    3 Pedidos\n");
        printf("    4 Meios de Mobilidaade\n");
        printf("Remover Dados\n");
        printf("    5 Pedidos\n");
        printf("    6 Meios de Mobilidade\n");
        printf("Consultas\n");
        printf("    7 Listar Mobilidade\n");
        printf("    8 Listar Pedidos\n");
        printf("    9 Plano de Utilizacao\n");
        printf("Armazenar Dados em ficheiros\n");
        printf("   10 - Armazenar Pedidos\n");
        printf("   11 - Armazenar Meios de Mobilidade\n");
        printf("Custo de um pedido\n");
        printf("    12 Indicar o nr do pedido\n");
        printf("13 Distribuir os meios de Mobilidade\n");
        printf("14 Limpar Tela\n");
        printf("0 - Sair\n");
        printf("Opcao?\n");
        scanf("%d",&opcao);
    }

    while ((opcao<0)||(opcao>14));
    return(opcao);
}
/**
 * Limpar a tela
 */
void limparTela(){
    for(int linha = 0; linha < 35; linha++)
    {
        printf( "\n" );
    }
}
