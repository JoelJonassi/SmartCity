/**
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
#include <assert.h>

/**Alinea - 1
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
            i++;
            tot = i;
        }
    }
    fclose(af);
    return  tot;
}
/**
 * Para Calculo
 * Converter a virgula num ponto
 * @param string
 * @param caraterAntigo
 * @param caraterNovo
 */
void mudarCarater(char *custo, char caraterAntigo, char caraterNovo)
{
    int slen = strlen(custo);
    for(int i = 0; i < slen; i++)
        if(custo[i] == caraterAntigo)custo[i] = caraterNovo;
}


 /**
  * Alinea - 2
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
 * Para Calculo
 * Converter o custo num float
 * @param string
 * @return
 */
int stringToFloat(char string[]){
    double custo = atof(string);
    return custo;
}

/**
 * Para Calculo
 * Convert float em string de modo a guardar no ficheiro
 * @param string
 * @param n_digit
 */
void floatToString(double number, int n_digit, char* buffer){
    gcvt(number, 30, buffer);
}

/**
 *Alinea 12
 * @param pedido
 * @param quantidadeAtletas
 */
void guardar_pedidos(Pedido pedido[], int n)
{
    int i;
    FILE* fp;
    fp = fopen("2-TipoTransporte.txt","at");   // "wt" write text  "rt" read text  "at" append
    for(i = n;i < n+n; i++)
    {fprintf(fp, "%d;", pedido[i].codigo);
        fprintf(fp, "%.2f;", pedido[i].distancia);
        fprintf(fp, "%.2f;", pedido[i].nr_ordem);
        fprintf(fp, "%s\n", pedido[i].nif);
        fprintf(fp, "%s\n", pedido[i].tempo);
    }
    fclose(fp);
}

/**Alinea 13
 *
 * @param c
 * @param quantidadeAtletas
 */
void guardar_meio_Transporte(MeioEletrico transporte[], int quantidadeAtletas)
{
    int i;
    FILE* fp;
    fp = fopen("2-TipoTransporte.txt","at");   // "wt" write text  "rt" read text  "at" append
    for(i = 0;i < quantidadeAtletas; i++)
    {fprintf(fp, "%d;", transporte[i].codigo);
        fprintf(fp, "%.2f;", transporte[i].tipo);
        fprintf(fp, "%.2f;", transporte[i].custo);
        fprintf(fp, "%s\n", transporte[i].autonomia);
    }
    fclose(fp);
}

/**
 * Alenea 7
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
 * Alinea 8
 * Para Debug
 * Visualizar os dados dos pedidos
 * @param v
 * @param n
 */
void viewFileSecond(Pedido *v, int n)
{
    for(int i = 0; i < n; i++){
        printf("%d %d %s %d %d\n", v[i].nr_ordem, v[i].nif, v[i].codigo, v[i].tempo, v[i].distancia);
    }
}

/**
 * // Determinar se existe um atleta com código 'cod' no array clube
// Devolve o índice do registo com a informação do atleta se existir
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
        if (transporte[i].codigo == cod && transporte[i].autonomia == aut) {
            i++;
            return (i);
        }
    return(-1);
    }
}

/**
 * // Determinar se existe um atleta com código 'cod' no array clube
// Devolve o índice do registo com a informação do atleta se existir
// Devolve -1 se não existir
 * @param transporte
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

/**Alinea 3
 * Função para inserção de um novo atleta no array clube
 * devolvendo como resultado 1 em caso de sucesso e 0 em caso de insucesso
 *
 * @param clube
 * @param qt
 * @param cod
 * @param nm
 * @param alt
 * @param pes
 * @return
 */
int inserirMeioElectrico(MeioEletrico transporte[], int posi, char codigo[4], char tipo[4], char custo[5], int autonomia)
{
    if (existeTransporte(transporte,codigo,autonomia)==-1)
    {
        strcpy(transporte[posi].codigo,codigo);
        strcpy(transporte[posi].tipo,tipo);
        strcpy(transporte[posi].custo, custo);
        transporte[posi].autonomia= autonomia;
        return(1);
    }
    else
        return(0);
}

/**Alinea 3
 * Função para inserção de um novo atleta no array clube
 * devolvendo como resultado 1 em caso de sucesso e 0 em caso de insucesso
 *
 * @param clube
 * @param qt
 * @param cod
 * @param nm
 * @param alt
 * @param pes
 * @return
 */
int inserirPedidoUtiliz(Pedido pedido[],MeioEletrico transporte[], int pos,int nr_ordem, int nif, char codigo[4], int tempo, int distancia)
{
    if (existePedido(transporte, pedido,nif, codigo, transporte[1].autonomia) == -1)
    {
        strcpy(pedido[pos].codigo, codigo);
        pedido[pos].nr_ordem= nr_ordem;
        pedido[pos].nif= nif;
        pedido[pos].distancia= distancia;
        pedido[pos].tempo= tempo;
        return(1);
    }
    else
        return(0);
}

/**
 * Custo de utllização Associado ao transporte
 * @param transporte
 * @param pedido
 * @param nr_ordem
 * @param n
 * @return
 */
int custUtiliz(MeioEletrico transporte[], Pedido pedido[], int nr_ordem, int n){
   float custo = 0;
   float aux = 0;
    for(int i = 0; i <= n; i++)
    {
        if ((pedido[i].nr_ordem == nr_ordem))
        {
            mudarCarater(transporte[i].custo,',','.');
            custo = stringToFloat(transporte[i].custo);
            aux = (float) pedido[i].distancia * custo; //Converter o char custo em float
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
