/**
 * @file funcoes.c
 * @author Joel Jonassi e Idelvina Fernando
 * @brief Prova de Rally
 * @version 0.1
 * @date 2021-01-17
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"



int main()
{
    Piloto *pilotos = NULL, *p = NULL;
    Prova *provas = NULL;
    Etapa *etapas = NULL;

    pilotos = guardar_piloto(pilotos, 1,"Joel Jonassi","Kia Rio");
    pilotos = guardar_piloto(pilotos, 2,"Maria Carvalho","Opel Corsa");
    etapas = guardar_etapa(etapas, 1, 28 ,"A","B", 5);
    etapas = guardar_etapa(etapas, 2, 25, "A", "B", 9);
    provas = guardar_prova(provas, 1, "A",3, 2);
    provas = guardar_prova(provas, 1,"B",3, 2);

//apresentar_concorrentes(pilotos);
    p = provaValida(etapas, pilotos, 9, "A", "B");
    listagemTempoDec(etapas, provas);
    apresentar_concorrentes(p);
    /*setlocale(LC_ALL, "Portuguese");

    FILE *af;
    FILE *af1;

    af = fopen("prova1.txt", "r");

    if (af == NULL)
    {
        printf("Impossivel abrir o ficheiro");
    }
    af1 = fopen("prova2.txt", "r");
    if (af1 == NULL)
    {
        printf("Impossivel abrir o ficheiro");
    }

    apresentConcorrentes(af);
   
    fclose(af);
    fclose(af1);*/
}






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "funcoes.h"
typedef struct etapa
{
    int nEtapa;
    char etapaInicial[10];
    char etapaFinal[10];
    char etapaCompleta[10];
    int idPiloto[10]
} etapa;

typedef struct piloto
{
    int nPilotos;
    char nome[10];
    char carro[10];
} piloto;

typedef struct prova
{
    int distancia;
    char etapaControl[10];
    int tempo;
} prova;

/**
 * @brief Procedimento dedicado a apresentar o numero total de concorrentes
 * @param nomeFicheiro prova1.txt
 */
void apresentConcorrentes(char *nomeFicheiro)
{

    piloto pilotos[5];
    etapa etapas[3];
    FILE *af;
    int i = 0;
    af = fopen("prova1.txt", "r");

    if (af == NULL)
        printf("Erro na abertura do ficheiro %s !\n");
    else
    {
        while (fscanf(af, "%d;%d", &etapas[i].nEtapa, &pilotos[i].nPilotos) != NULL)
        {
            if (etapas[strlen(etapas[i].nEtapa) - 1].nEtapa == '\n')
                etapas[strlen(etapas[i].nEtapa) - 1].nEtapa = '\0';

            for (int i = 1; i <= pilotos[i].nPilotos; i++)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    fclose(af);
}

/**
 * @brief Função para leitura da ficha dos pilotos
 * @param nomeFicheiro O ficheiro a ser lido é o prova3.txt
 */
void lerConcorrente(char *nomeFicheiro)
{
    FILE *af;
    int i = 0;
    piloto *v;
    af = fopen(nomeFicheiro, "r");

    if (af == NULL)
        puts("Erro na abertura do ficheiro!\n");
    else
    {
        while (fscanf(af, "%d;%[^;];%[^;\n]\n", &v[i].nPilotos, &v[i].nome, &v[i].carro) != NULL)
        {
            if (v[i].carro[strlen(v[i].carro) - 1] == '\n')
                v[i].carro[strlen(v[i].carro) - 1] = '\0';
            printf("%d\n", v[i].nPilotos);
            i++;

            break;
        }
    }
    fclose(af);
}
/**
 * @brief Função para recolha dos dados da pista "A distancia e as etapas"
 *
 * @param nomeFicheiro
 * @return int
 */
int lerPista(char *nomeFicheiro)
{
    prova *v;
    FILE *af;
    int i = 0;
    af = fopen(nomeFicheiro, "r");

    if (af == NULL)
        puts("Erro na abertura do ficheiro!\n");
    else
    {
        while (fscanf(af, "%[^;];%d\n", &v[i].etapaControl, &v[i].distancia) != NULL)
        {
            if (v[strlen(v[i].distancia) - 1].distancia == '\n')
            {
                v[strlen(v[i].distancia) - 1].distancia = '\0';
                return 1;
            }
        }
    }
    fclose(af);
}













/**
 * @brief Compara o ficheiro 1 e 2 e determina se a prova do concorrente é válida caso o conteudo seja igual
 * @param nomeFicheiro O ficheiro que possui os dados das etapas
 * @param nomeFicheiro2 O ficheiro que possui dados da pista
 * @return retorna -1 caso não abra o ficheiro, retorna 1 caso prova valido caso contrario retorna 0
 */
int provaValida(char *nomeFicheiro, char *nomeFicheiro2)
{
    FILE *af, *af1;
    etapa etapas[10];
    prova prova[5];
    piloto pilotos[7];
    int i = 0, y = 0;
    af = fopen(nomeFicheiro, "r");   // prova 1.txt
    af1 = fopen(nomeFicheiro2, "r"); //prova 2.txt

    if (af == NULL && af1 == NULL)
        return -1;
    else
    {
        while (fscanf(af, "%d;%[^;];%[^;];%d\n", &pilotos[i].nPilotos, &etapas[i].etapaInicial, &etapas[i].etapaFinal, &prova[i].tempo) != NULL)
        {
            if (prova[strlen(prova[i].tempo) - 1].tempo == '\n')
                prova[strlen(prova[i].tempo) - 1].tempo = '\0';
            i++;
        }
        while (fscanf(af1, "%[^;];%d", &prova[y].etapaControl, &prova[y].distancia) != NULL)
        {
            if (prova[strlen(prova[i].distancia) - 1].distancia == '\n')
                prova[strlen(prova[i].distancia) - 1].distancia = '\0';

            strcat(etapas[y].etapaCompleta[y], etapas[y].etapaInicial);
            strcat(etapas[y].etapaCompleta[y], etapas[y].etapaFinal);

            if (strcmp(prova[y].etapaControl, etapas[y].etapaCompleta[y]) == 0)
                return 1;
            return 0;
            y++;
        }
    }
    fclose(af);
    fclose(af1);
}


int main()
{

    setlocale(LC_ALL, "Portuguese");

    FILE *af;
    FILE *af1;

    af = fopen("prova1.txt", "r");

    if (af == NULL)
    {
        printf("Impossivel abrir o ficheiro");
    }
    af1 = fopen("prova2.txt", "r");
    if (af1 == NULL)
    {
        printf("Impossivel abrir o ficheiro");
    }

    apresentConcorrentes(af);

    fclose(af);
    fclose(af1);






    /**
 * @file funcoes.c
 * @author Joel Jonassi e Idelvina Fernando
 * @brief Prova de Rally
 * @version 0.1
 * @date 2021-01-17
 * @copyright Copyright (c) 2021
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.h"



    Etapa *guardar_etapa(Etapa *todas_etapas,int id, int tempo, char *etapa_inicial, char *etapa_final, int distancia){
        Etapa *etapas = (Etapa*) malloc(sizeof(Etapa));
        etapas->idPiloto = id;
        etapas->etapaInicial = strdup(etapa_inicial);
        etapas->tempo = tempo;
        etapas->etapaFinal = strdup(etapa_final);
        etapas->distancia = distancia;
        etapas->next = todas_etapas;
        return etapas;
    }

    Prova *guardar_prova(Prova *todas_provas, int id, char *etapa, const int qt_etapa, const int n_concorrentes){
        Prova *provas = (Prova*) malloc(sizeof(Prova));
        provas->etapa = strdup(etapa);
        provas->idPiloto = id;
        provas->n_concorrentes = n_concorrentes;
        provas->qt_etapas = qt_etapa;
        provas->next = todas_provas;
        return provas;
    }

    Piloto *guardar_piloto(Piloto *todos_pilotos, int id, char *nome, char *carro){
        Piloto *pilotos = (Piloto*) malloc(sizeof(Piloto));
        pilotos->nome = strdup(nome);
        pilotos->carro = carro;
        pilotos->id = id;
        pilotos->next = todos_pilotos;
        return pilotos;
    }

    void apresentar_concorrentes(Piloto *lista){
        printf("Id        Nome     Carro\n");
        while (lista)
        {
            printf("%2.d - %s -> %2s\n", lista->id, lista->nome, lista->carro);
            lista = lista->next;
        }
    }

    void listagemTempoDec(Etapa* etapas, Prova *provas){
        int aux[provas->qt_etapas];
        aux[0] = 0;
        int i = 0;
        for(int i = 0; i > provas->qt_etapas; i++){
            for(int j = i + 1; j > (provas->qt_etapas - 1); j++){
                if(aux[i] < etapas->tempo){
                    aux[i] = etapas->tempo;
                    etapas->tempo = etapas->next->tempo;
                    etapas->tempo = aux[i];
                }

                provas = provas->next;
                etapas = etapas->next;
            }

        }
        printf("%d\n", etapas->tempo);
    }

    // printf("%d\n" aux[1]);



    Piloto *provaValida(Etapa* etapas, Piloto *pilotos,int tempo, char *inicio, char *fim){
        Piloto *aux_piloto = (Piloto*) malloc(sizeof(Piloto));
        for(; pilotos; pilotos = pilotos->next)
        {
            if(pilotos->id == etapas->idPiloto){
                if((strcmp(etapas->etapaInicial, inicio) == 0)  && (strcmp(etapas->etapaFinal, fim) == 0) && tempo != 0)
                {
                    aux_piloto = pilotos;
                    aux_piloto->next = pilotos->next;
                }
            }
        }
        return aux_piloto;

    }
/**
 * @brief Procedimento dedicado a apresentar o numero total de concorrentes
 * @param nomeFicheiro prova1.txt
 */
/*void apresentConcorrentes(char *nomeFicheiro)
{

    piloto pilotos[5];
    etapa etapas[3];
    FILE *af;
    int i = 0;
    af = fopen("prova1.txt", "r");

    if (af == NULL)
        printf("Erro na abertura do ficheiro %s !\n");
    else
    {
        while (fscanf(af, "%d;%d", &etapas[i].nEtapa, &pilotos[i].nPilotos) != NULL) // '\n'
        {

            for (int i = 1; i <= pilotos[i].nPilotos; i++)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    fclose(af);
}

/**
 * @brief Função para leitura da ficha dos pilotos
 * @param nomeFicheiro O ficheiro a ser lido é o prova3.txt
 *//*
int lerConcorrente(char *nomeFicheiro, piloto *v)
{
    FILE *af;
    int i = 0;
    // piloto *v;
    af = fopen(nomeFicheiro, "r");

    if (af == NULL)
        puts("Erro na abertura do ficheiro!\n");
    else
    {
        while (fscanf(af, "%d;%[^;];%[^;\n]\n", &v[i].nPilotos, v[i].nome, v[i].carro) != NULL)
        {
            if (v[i].carro[strlen(v[i].carro) - 1] == '\n')
                v[i].carro[strlen(v[i].carro) - 1] = '\0';
            // printf("%d\n", v[i].nPilotos);
            i++;

            break;
        }
    }
    fclose(af);
    return i;
}
/**
 * @brief Função para recolha dos dados da pista "A distancia e as etapas"
 *
 * @param nomeFicheiro
 * @return int
 */
/*int lerPista(char *nomeFicheiro, prova *v)
{
    //prova *v;
    FILE *af;
    int i = 0;
    af = fopen(nomeFicheiro, "r");

    if (af == NULL)
        puts("Erro na abertura do ficheiro!\n");
    else
    {
        while (fscanf(af, "%[^];%d\n", v[i].etapaControl, &v[i].distancia) != NULL)
        {
            if (v[strlen(v[i].distancia) - 1].distancia == '\n')
            {
                v[strlen(v[i].distancia) - 1].distancia = '\0';
                //return 1;
            }
            i++;
        }
    }
    fclose(af);
    return 1;
}*/

/**
 * @brief Compara o ficheiro 1 e 2 e determina se a prova do concorrente é válida caso o conteudo seja igual
 * @param nomeFicheiro O ficheiro que possui os dados das etapas
 * @param nomeFicheiro2 O ficheiro que possui dados da pista
 * @return retorna -1 caso não abra o ficheiro, retorna 1 caso prova valido caso contrario retorna 0
 */
/*int provaValida(char *nomeFicheiro, char *nomeFicheiro2)
{
    FILE *af, *af1;
    etapa etapas[10];
    prova prova[5];
    piloto pilotos[7];
    int i = 0, y = 0;
    af = fopen(nomeFicheiro, "r");   // prova 1.txt
    af1 = fopen(nomeFicheiro2, "r"); //prova 2.txt

    if (af == NULL && af1 == NULL)
        return -1;
    else
    {
        while (fscanf(af, "%d;%[^];%[^;];%d\n", &pilotos[i].nPilotos, etapas[i].etapaInicial, etapas[i].etapaFinal, &prova[i].tempo) != NULL)
        {
            if (prova[strlen(prova[i].tempo) - 1].tempo == '\n')
                prova[strlen(prova[i].tempo) - 1].tempo = '\0';
            i++;
        }
        while (fscanf(af1, "%[^;];%d", &prova[y].etapaControl, &prova[y].distancia) != NULL)
        {
            if (prova[strlen(prova[i].distancia) - 1].distancia == '\n')
                prova[strlen(prova[i].distancia) - 1].distancia = '\0';

            strcat(etapas[y].etapaCompleta[y], etapas[y].etapaInicial);
            strcat(etapas[y].etapaCompleta[y], etapas[y].etapaFinal);
            y++;
        }
    }
    fclose(af);
    fclose(af1);
    if (strcmp(prova[y].etapaControl, etapas[y].etapaCompleta[y]) == 0)
        return 1;
    return 0;
}*/







#ifndef A // ou #pragma once
#define A
#include <stdio.h>
#include <string.h>


    typedef struct _etapa
    {
        char *etapaInicial;
        char *etapaFinal;
        int distancia;
        int idPiloto;
        int tempo;
        struct _etapa *next;
    } Etapa;

    typedef struct _piloto
    {
        int id;
        char *nome;
        char *carro;
        struct _piloto *next;
    } Piloto;

    typedef struct _prova
    {
        int idPiloto;
        char *etapa;
        int n_concorrentes;
        int qt_etapas;
        struct _prova *next;
    } Prova;

    void listagemTempoDec(Etapa * etapas, Prova* provas);
    void apresentar_concorrentes(Piloto *lista);
    extern void apresentConcorrentes(char *nomeFicheiro);
    extern int distanciaEtapas(char *nomeFicheiro);
    extern Piloto *provaValida(Etapa* etapas, Piloto *pilotos, int tempo, char *inicio, char *fim);
    extern int rapidoLento(char *nomeFicheiro, int x, int *v, int s);
    Etapa *guardar_etapa(Etapa *todas_etapas,int id, int tempo, char *etapa_inicial,char *etapa_final, int distancia);
    Prova *guardar_prova(Prova *todas_provas, int id, char *etapa, const int qt_etapa, const int n_concorrentes);
    Piloto *guardar_piloto(Piloto *todos_pilotos, int id, char *nome, char *carro);

#endif